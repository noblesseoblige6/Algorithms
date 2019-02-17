namespace acLib
{
    using namespace util;

    namespace DX12
    {
        ConstantBuffer::ConstantBuffer()
            : m_pBuffer( nullptr )
            , m_pDataBegin( 0 )
        {
        };


        ConstantBuffer::~ConstantBuffer()
        {
            if (m_pBuffer != nullptr)
            {
                m_pBuffer->Unmap( 0, nullptr );
                m_pBuffer.Reset();
            }
        };


        bool ConstantBuffer::CreateBuffer( ID3D12Device* pDevice, int size )
        {
            HRESULT hr = S_OK;

            // ヒーププロパティの設定.
            D3D12_HEAP_PROPERTIES prop = {};
            prop.Type = D3D12_HEAP_TYPE_UPLOAD;
            prop.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
            prop.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
            prop.CreationNodeMask = 1;
            prop.VisibleNodeMask = 1;

            // リソースの設定.
            D3D12_RESOURCE_DESC desc = {};
            desc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
            desc.Alignment = 0;
            desc.Width = size;
            desc.Height = 1;
            desc.DepthOrArraySize = 1;
            desc.MipLevels = 1;
            desc.Format = DXGI_FORMAT_UNKNOWN;
            desc.SampleDesc.Count = 1;
            desc.SampleDesc.Quality = 0;
            desc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
            desc.Flags = D3D12_RESOURCE_FLAG_NONE;

            // リソースを生成.
            hr = pDevice->CreateCommittedResource( &prop,
                D3D12_HEAP_FLAG_NONE,
                &desc,
                D3D12_RESOURCE_STATE_GENERIC_READ,
                nullptr,
                IID_PPV_ARGS( m_pBuffer.ReleaseAndGetAddressOf() ) );

            if (FAILED( hr ))
            {
                Log::Output( Log::LOG_LEVEL_ERROR, "ID3D12Device::CreateCommittedResource() Failed." );
                return false;
            }

            // マップする. アプリケーション終了まで Unmap しない.
            hr = m_pBuffer->Map( 0, nullptr, reinterpret_cast<void**>(&m_pDataBegin) );
            if (FAILED( hr ))
            {
                Log::Output( Log::LOG_LEVEL_ERROR, "ID3D12Resource::Map() Failed." );
                return false;
            }

            return true;
        };

        void ConstantBuffer::CreateBufferView( ID3D12Device* pDevice, int size )
        {
            if (m_pDescHeap == nullptr)
            {
                Log::Output( Log::LOG_LEVEL_ERROR, "ConstantBuffer::CreateBufferView --> No descriptor heap." );
                return;
            }

            // 定数バッファビューの設定.
            D3D12_CONSTANT_BUFFER_VIEW_DESC bufferDesc = {};
            bufferDesc.BufferLocation = m_pBuffer->GetGPUVirtualAddress();
            bufferDesc.SizeInBytes = size;

            D3D12_CPU_DESCRIPTOR_HANDLE handle = m_pDescHeap->GetCPUStartHandle();
            handle.ptr += m_pDescHeap->GetIncrementSize() * m_pDescHeap->GetBufferCount();
            m_pDescHeap->SetBufferCount( m_pDescHeap->GetBufferCount() + 1 );

            // 定数バッファビューを生成.
            pDevice->CreateConstantBufferView( &bufferDesc, handle );
        }

        void ConstantBuffer::Map( void* pData, int size )
        {
            // map
            memcpy( m_pDataBegin, pData, size );
        }
    }
}