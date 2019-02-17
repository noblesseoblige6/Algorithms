#pragma once

namespace acLib
{
    namespace DX12
    {
        using namespace Microsoft::WRL;
        using namespace std;

        class ConstantBuffer
        {
        public:
            ConstantBuffer();
            ~ConstantBuffer();

            void SetDescHeap( shared_ptr<DescriptorHeap> heap ) { m_pDescHeap = heap; }
            shared_ptr<DescriptorHeap> GetDescHeap() const { return m_pDescHeap; }

            bool CreateBuffer( ID3D12Device* pDevice, int size );
            void CreateBufferView( ID3D12Device* pDevice, int size );
            void Map( void* pData, int size );

        private:
            ComPtr<ID3D12Resource>          m_pBuffer;
            UINT8*                          m_pDataBegin;

            shared_ptr<DescriptorHeap>    m_pDescHeap;
        };
    }
}
