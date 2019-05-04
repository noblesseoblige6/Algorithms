#pragma once

namespace acLib
{
    namespace DX12
    {
        using namespace Microsoft::WRL;

        class PipelineState
        {
        public:
            static D3D12_RASTERIZER_DESC          CreateDefaultRasterizerDesc();
            static D3D12_RENDER_TARGET_BLEND_DESC CreateDefaultRenderTargetDesc();
            static D3D12_BLEND_DESC               CreateDefaultBlendDesc();
            static D3D12_DEPTH_STENCIL_DESC       CreateDefaultDepthStencilDesc();

        public:
            struct InputElement
            {
                std::vector<D3D12_INPUT_ELEMENT_DESC> elements;
            };

            struct ShaderCode
            {
                D3D12_SHADER_BYTECODE vs;
                D3D12_SHADER_BYTECODE ps;
            };

        public:
            PipelineState( const InputElement& inputElements, const ShaderCode& shader, shared_ptr<RootSignature> rs = nullptr);
            ~PipelineState();

            bool Create( ID3D12Device* pDevice );

            void SetRootSinature( shared_ptr<RootSignature> rs);

            ID3D12PipelineState* GetPipelineState() { return m_pPipelineState.Get(); };
            ID3D12PipelineState** GetGetPipelineStateAddress() { return m_pPipelineState.GetAddressOf(); };
            
            D3D12_GRAPHICS_PIPELINE_STATE_DESC& GetDesc() { return m_desc; }
            const D3D12_GRAPHICS_PIPELINE_STATE_DESC& GetDesc() const { return m_desc; }


        private:
            ComPtr<ID3D12PipelineState>            m_pPipelineState;
            D3D12_GRAPHICS_PIPELINE_STATE_DESC     m_desc;
            InputElement m_inputElement;
        };
    }
}
