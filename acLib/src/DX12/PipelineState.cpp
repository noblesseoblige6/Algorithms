namespace acLib
{
    using namespace util;

    namespace DX12
    {
        D3D12_RASTERIZER_DESC          PipelineState::CreateDefaultRasterizerDesc()
        {
            D3D12_RASTERIZER_DESC descRS;
            descRS.FillMode                 = D3D12_FILL_MODE_SOLID;
            descRS.CullMode                 = D3D12_CULL_MODE_BACK;
            descRS.FrontCounterClockwise    = FALSE;
            descRS.DepthBias                = D3D12_DEFAULT_DEPTH_BIAS;
            descRS.DepthBiasClamp           = D3D12_DEFAULT_DEPTH_BIAS_CLAMP;
            descRS.SlopeScaledDepthBias     = D3D12_DEFAULT_SLOPE_SCALED_DEPTH_BIAS;
            descRS.DepthClipEnable          = TRUE;
            descRS.MultisampleEnable        = FALSE;
            descRS.AntialiasedLineEnable    = FALSE;
            descRS.ForcedSampleCount        = 0;
            descRS.ConservativeRaster       = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;

            return descRS;
        }
        
        D3D12_RENDER_TARGET_BLEND_DESC PipelineState::CreateDefaultRenderTargetDesc()
        {
            // レンダーターゲットのブレンド設定.
            D3D12_RENDER_TARGET_BLEND_DESC descRTBS = {
                FALSE, FALSE,
                D3D12_BLEND_ONE, D3D12_BLEND_ZERO, D3D12_BLEND_OP_ADD,
                D3D12_BLEND_ONE, D3D12_BLEND_ZERO, D3D12_BLEND_OP_ADD,
                D3D12_LOGIC_OP_NOOP,
                D3D12_COLOR_WRITE_ENABLE_ALL
            };

            return descRTBS;
        }

        D3D12_BLEND_DESC PipelineState::CreateDefaultBlendDesc()
        {
            D3D12_BLEND_DESC descBS;
            descBS.AlphaToCoverageEnable  = FALSE;
            descBS.IndependentBlendEnable = FALSE;
        
            
            D3D12_RENDER_TARGET_BLEND_DESC descRTBS = CreateDefaultRenderTargetDesc();
            for (UINT i = 0; i<D3D12_SIMULTANEOUS_RENDER_TARGET_COUNT; ++i)
            {
                descBS.RenderTarget[i] = descRTBS;
            }

            return descBS;
        }

        D3D12_DEPTH_STENCIL_DESC PipelineState::CreateDefaultDepthStencilDesc()
        {
            // デプスステンシルの設定
            D3D12_DEPTH_STENCIL_DESC descDS = {};
            descDS.DepthEnable    = TRUE;                             //深度テストあり
            descDS.DepthFunc      = D3D12_COMPARISON_FUNC_LESS_EQUAL;
            descDS.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;

            descDS.StencilEnable    = FALSE;                            //ステンシルテストなし
            descDS.StencilReadMask  = D3D12_DEFAULT_STENCIL_READ_MASK;
            descDS.StencilWriteMask = D3D12_DEFAULT_STENCIL_WRITE_MASK;

            descDS.FrontFace.StencilFailOp      = D3D12_STENCIL_OP_KEEP;
            descDS.FrontFace.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;
            descDS.FrontFace.StencilPassOp      = D3D12_STENCIL_OP_KEEP;
            descDS.FrontFace.StencilFunc        = D3D12_COMPARISON_FUNC_ALWAYS;

            descDS.BackFace.StencilFailOp       = D3D12_STENCIL_OP_KEEP;
            descDS.BackFace.StencilDepthFailOp  = D3D12_STENCIL_OP_KEEP;
            descDS.BackFace.StencilPassOp       = D3D12_STENCIL_OP_KEEP;
            descDS.BackFace.StencilFunc         = D3D12_COMPARISON_FUNC_ALWAYS;

            return descDS;
        }

        PipelineState::PipelineState( const InputElement& inputElement, const ShaderCode& shader, shared_ptr<RootSignature> rs )
        {
            m_desc = { 0 };

            // Shader
            m_desc.VS = shader.vs;
            m_desc.PS = shader.ps;

            // Input layout
            m_inputElement = inputElement;

            // Rasterier
            m_desc.RasterizerState = CreateDefaultRasterizerDesc();

            // Blend State
            m_desc.BlendState = CreateDefaultBlendDesc();

            // Depth Stencil
            m_desc.DepthStencilState = CreateDefaultDepthStencilDesc();
            m_desc.DSVFormat = DXGI_FORMAT_D32_FLOAT;

            // Sampler
            m_desc.SampleDesc.Count = 1;
            m_desc.SampleDesc.Quality = 0;
            m_desc.SampleMask = UINT_MAX;

            m_desc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
            SetRootSinature( rs );
        }

        PipelineState::~PipelineState()
        {
            m_pPipelineState.Reset();
        }

        void PipelineState::SetRootSinature( shared_ptr<RootSignature> rs )
        {
            m_desc.pRootSignature = rs->GetRootSignature();
        }

        bool PipelineState::Create( ID3D12Device* pDevice )
        {
            HRESULT hr = S_OK;

            int count = m_inputElement.elements.size();

            D3D12_INPUT_ELEMENT_DESC* elements = new D3D12_INPUT_ELEMENT_DESC[count];
            for (int i = 0; i < count; ++i)
                elements[i] = m_inputElement.elements[i];

            m_desc.InputLayout = { elements, (UINT)count };

            // パイプラインステートを生成.
            hr = pDevice->CreateGraphicsPipelineState( &m_desc, IID_PPV_ARGS( m_pPipelineState.GetAddressOf() ) );

            delete[] elements;

            if (FAILED( hr ))
            {
                Log::Output( Log::LOG_LEVEL_ERROR, "ID3D12Device::CreateGraphicsPipelineState() Failed." );
                return false;
            }

            return true;
        }
    }
}