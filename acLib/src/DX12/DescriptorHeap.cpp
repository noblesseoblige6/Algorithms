namespace acLib
{
    using namespace util;

    namespace DX12
    {
        DescriptorHeap::DescriptorHeap()
            : m_pDescHeap()
            , m_bufferCount( 0 )
        {
        }

        DescriptorHeap::~DescriptorHeap()
        {
            m_pDescHeap.Reset();
        }

        bool DescriptorHeap::Create( ID3D12Device* pDevice, const D3D12_DESCRIPTOR_HEAP_DESC& desc )
        {
            HRESULT hr = S_OK;

            hr = pDevice->CreateDescriptorHeap( &desc,
                IID_ID3D12DescriptorHeap,
                (void**)(m_pDescHeap.ReleaseAndGetAddressOf()) );
            if (FAILED( hr ))
            {
                Log::Output( Log::LOG_LEVEL_ERROR, "ID3D12Device::CreateDescriptorHeap() Failed." );
                return false;
            }

            m_DescHeapCBSize = pDevice->GetDescriptorHandleIncrementSize( desc.Type );

            return true;
        }
    }
}