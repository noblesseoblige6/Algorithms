#pragma once

namespace acLib
{
    namespace DX12
    {
        using namespace Microsoft::WRL;

        class RootSignature
        {
        public:
            RootSignature();
            ~RootSignature();

            bool Create( ID3D12Device* pDevice, const D3D12_ROOT_SIGNATURE_DESC& desc );

            ID3D12RootSignature* GetRootSignature() { return m_pRootSignature.Get(); };
            ID3D12RootSignature** GetGetRootSignatureAddress() { return m_pRootSignature.GetAddressOf(); };

        private:
            ComPtr<ID3D12RootSignature>            m_pRootSignature;
        };
    }
}
