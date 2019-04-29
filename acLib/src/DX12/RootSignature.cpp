namespace acLib
{
    using namespace util;

    namespace DX12
    {
        RootSignature::RootSignature()
        {}

        RootSignature::~RootSignature()
        {
            m_pRootSignature.Reset();
        }

        bool RootSignature::Create( ID3D12Device* pDevice, const D3D12_ROOT_SIGNATURE_DESC& desc )
        {
            HRESULT hr = S_OK;

            ComPtr<ID3DBlob> pSignature;
            ComPtr<ID3DBlob> pError;

            // シリアライズする.
            hr = D3D12SerializeRootSignature( &desc,
                                              D3D_ROOT_SIGNATURE_VERSION_1,
                                              pSignature.GetAddressOf(),
                                              pError.GetAddressOf() );
            if (FAILED( hr ))
            {
                Log::Output( Log::LOG_LEVEL_ERROR, "D3D12SerializeRootSignataure() Failed." );
                return false;
            }

            // ルートシグニチャを生成.
            hr = pDevice->CreateRootSignature( 0,
                                               pSignature->GetBufferPointer(),
                                               pSignature->GetBufferSize(),
                                               IID_PPV_ARGS( m_pRootSignature.GetAddressOf() ) );

            if (FAILED( hr ))
            {
                Log::Output( Log::LOG_LEVEL_ERROR, "ID3D12Device::CreateRootSignature() Failed." );
                return false;
            }

            return true;
        }
    }
}