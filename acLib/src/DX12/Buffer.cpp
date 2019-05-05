namespace acLib
{
    using namespace util;

    namespace DX12
    {
        Buffer::Buffer()
            : m_pBuffer( nullptr )
            , m_pDataBegin( 0 )
            , m_pDescHeap()
            , m_handle()
        {
            m_pDescHeap.clear();
            m_handle.clear();
        };


        Buffer::~Buffer()
        {
            if (m_pBuffer != nullptr)
            {
                m_pBuffer.Reset();
            }
        };

        D3D12_CPU_DESCRIPTOR_HANDLE Buffer::GetHandleFromHeap( const shared_ptr<DescriptorHeap>& pHeap )
        {
            for (int i = 0; i < m_pDescHeap.size(); ++i)
            {
                if (m_pDescHeap[i].get() == pHeap.get())
                {
                    return m_handle[i];
                }
            }

            Log::Output( Log::LOG_LEVEL_WARNING, "Buffer::GetHandleFromHeap --> Cannot find descriptor heap." );
            return m_handle[0];
        }

        bool Buffer::Create( ID3D12Device* pDevice, D3D12_HEAP_PROPERTIES& prop, D3D12_RESOURCE_DESC& desc, D3D12_RESOURCE_STATES initState, D3D12_CLEAR_VALUE* pClearValue )
        {
            HRESULT hr = S_OK;

            // リソースを生成.
            hr = pDevice->CreateCommittedResource( &prop,
                                                   D3D12_HEAP_FLAG_NONE,
                                                   &desc,
                                                   initState,
                                                   pClearValue,
                                                   IID_PPV_ARGS( m_pBuffer.ReleaseAndGetAddressOf() ) );

            if (FAILED( hr ))
            {
                Log::Output( Log::LOG_LEVEL_ERROR, "ID3D12Device::CreateCommittedResource() Failed." );
                return false;
            }

            return true;
        };

        bool Buffer::CreateBufferView( ID3D12Device* pDevice, shared_ptr<DescriptorHeap> pHeap, BUFFER_VIEW_TYPE type )
        {
            D3D12_CPU_DESCRIPTOR_HANDLE handle;
            if (!AdvanceHadle(pHeap.get(), handle))
                return false;

            switch (type)
            {
            case BUFFER_VIEW_TYPE_RENDER_TARGET:
            {
                D3D12_RENDER_TARGET_VIEW_DESC bufferDesc;
                bufferDesc.Format               = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
                bufferDesc.ViewDimension        = D3D12_RTV_DIMENSION_TEXTURE2D;
                bufferDesc.Texture2D.MipSlice   = 0;
                bufferDesc.Texture2D.PlaneSlice = 0;

                pDevice->CreateRenderTargetView( m_pBuffer.Get(), &bufferDesc, handle );
            }
            break;
            case BUFFER_VIEW_TYPE_DEPTH_STENCIL:
            {
                D3D12_DEPTH_STENCIL_VIEW_DESC bufferDesc = {};
                bufferDesc.ViewDimension        = D3D12_DSV_DIMENSION_TEXTURE2D;
                bufferDesc.Format               = DXGI_FORMAT_D32_FLOAT;
                bufferDesc.ViewDimension        = D3D12_DSV_DIMENSION_TEXTURE2D;
                bufferDesc.Texture2D.MipSlice   = 0;
                bufferDesc.Flags                = D3D12_DSV_FLAG_NONE;

                pDevice->CreateDepthStencilView( m_pBuffer.Get(), &bufferDesc, handle );
            }
            break;
            case BUFFER_VIEW_TYPE_SHADER_RESOURCE:
            {
                D3D12_SHADER_RESOURCE_VIEW_DESC  bufferDesc = {};
                bufferDesc.Format                           = DXGI_FORMAT_R32_FLOAT;
                bufferDesc.ViewDimension                    = D3D12_SRV_DIMENSION_TEXTURE2D;
                bufferDesc.Texture2D.MipLevels              = 1;
                bufferDesc.Texture2D.MostDetailedMip        = 0;
                bufferDesc.Texture2D.PlaneSlice             = 0;
                bufferDesc.Texture2D.ResourceMinLODClamp    = 0.0F;
                bufferDesc.Shader4ComponentMapping          = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;

                pDevice->CreateShaderResourceView( m_pBuffer.Get(), &bufferDesc, handle );
            }
            break;
            case BUFFER_VIEW_TYPE_CONSTANT:
            case BUFFER_VIEW_TYPE_VERTEX:
            case BUFFER_VIEW_TYPE_INDEX:
            default:
                break;
            }

            m_handle.push_back( handle );
            m_pDescHeap.push_back( pHeap );

            return true;
        }

        bool Buffer::Map( void* pData, int size )
        {
            HRESULT hr = S_OK;

            if (m_pDataBegin == 0)
            {
                hr = m_pBuffer->Map( 0, nullptr, reinterpret_cast<void**>(&m_pDataBegin) );
                if (FAILED( hr ))
                {
                    Log::Output( Log::LOG_LEVEL_ERROR, "ID3D12Resource::Map() Failed." );
                    return false;
                }
            }

            memcpy( m_pDataBegin, pData, size );

            return true;
        }

        void Buffer::Unmap()
        {
            m_pBuffer->Unmap( 0, nullptr );
        }

        bool Buffer::AdvanceHadle( DescriptorHeap* pHeap, D3D12_CPU_DESCRIPTOR_HANDLE& handle )
        {
            size_t count = pHeap->GetBufferCount();
            
            handle = pHeap->GetCPUStartHandle();
            handle.ptr += pHeap->GetIncrementSize() * count;

            pHeap->SetBufferCount( count + 1 );

            return true;
        }

        //----------------------------------------------
        VertexBuffer::VertexBuffer()
            : Buffer()
        {
        }


        VertexBuffer::~VertexBuffer()
        {
            m_vertexBufferView.BufferLocation = 0;
            m_vertexBufferView.SizeInBytes = 0;
            m_vertexBufferView.StrideInBytes = 0;
        }

        bool VertexBuffer::Create( ID3D12Device* pDevice, int size, D3D12_RESOURCE_STATES initState, D3D12_CLEAR_VALUE* pClearValue )
        {
            // ヒーププロパティの設定.
            D3D12_HEAP_PROPERTIES prop;
            prop.Type = D3D12_HEAP_TYPE_UPLOAD;
            prop.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
            prop.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
            prop.CreationNodeMask = 1;
            prop.VisibleNodeMask = 1;

            // リソースの設定.
            D3D12_RESOURCE_DESC desc;
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

            return Buffer::Create( pDevice, prop, desc, initState, pClearValue );
        }

        bool VertexBuffer::CreateBufferView( ID3D12Device* pDevice, shared_ptr<DescriptorHeap> heap, BUFFER_VIEW_TYPE type )
        {
            const auto& desc = m_pBuffer->GetDesc();

            m_vertexBufferView.BufferLocation = m_pBuffer->GetGPUVirtualAddress();
            m_vertexBufferView.StrideInBytes  = (UINT)m_dataStride;
            m_vertexBufferView.SizeInBytes    = (UINT)desc.Width;

            return true;
        }

        //----------------------------------------------
        IndexBuffer::IndexBuffer()
            : Buffer()
        {
        }


        IndexBuffer::~IndexBuffer()
        {
            m_depthStencilBufferView.BufferLocation = 0;
            m_depthStencilBufferView.SizeInBytes = 0;
        }

        bool IndexBuffer::Create( ID3D12Device* pDevice, int size, D3D12_RESOURCE_STATES initState, D3D12_CLEAR_VALUE* pClearValue )
        {
            // ヒーププロパティの設定.
            D3D12_HEAP_PROPERTIES prop;
            prop.Type = D3D12_HEAP_TYPE_UPLOAD;
            prop.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
            prop.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
            prop.CreationNodeMask = 1;
            prop.VisibleNodeMask = 1;

            // リソースの設定.
            D3D12_RESOURCE_DESC desc;
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

            return Buffer::Create( pDevice, prop, desc, initState, pClearValue );
        }

        bool IndexBuffer::CreateBufferView( ID3D12Device* pDevice, shared_ptr<DescriptorHeap> heap, BUFFER_VIEW_TYPE type )
        {
            const auto& desc = m_pBuffer->GetDesc();

            m_depthStencilBufferView.BufferLocation = m_pBuffer->GetGPUVirtualAddress();
            m_depthStencilBufferView.Format         = m_dataFormat;
            m_depthStencilBufferView.SizeInBytes    = (UINT)desc.Width;

            return true;
        }

        //----------------------------------------------
        ConstantBuffer::ConstantBuffer()
            : Buffer()
            , m_bufferSize( 0 )
        {
        }


        ConstantBuffer::~ConstantBuffer()
        {
            Unmap();
        }

        bool ConstantBuffer::Create( ID3D12Device* pDevice, int size, D3D12_RESOURCE_STATES initState, D3D12_CLEAR_VALUE* pClearValue )
        {
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
            desc.Width = (sizeof( size ) + 255) &~255;
            desc.Height = 1;
            desc.DepthOrArraySize = 1;
            desc.MipLevels = 1;
            desc.Format = DXGI_FORMAT_UNKNOWN;
            desc.SampleDesc.Count = 1;
            desc.SampleDesc.Quality = 0;
            desc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
            desc.Flags = D3D12_RESOURCE_FLAG_NONE;

           return Buffer::Create( pDevice, prop, desc, initState, pClearValue );
        }

        bool ConstantBuffer::CreateBufferView( ID3D12Device* pDevice, shared_ptr<DescriptorHeap> heap, BUFFER_VIEW_TYPE type )
        {
            if (!Buffer::CreateBufferView( pDevice, heap, type ))
            {
                return false;
            }

            if (type != BUFFER_VIEW_TYPE_CONSTANT)
                return true;

            const auto& desc = m_pBuffer->GetDesc();

            m_bufferSize = desc.Width;

            // 定数バッファビューの設定.
            D3D12_CONSTANT_BUFFER_VIEW_DESC bufferDesc = {};
            bufferDesc.BufferLocation = m_pBuffer->GetGPUVirtualAddress();
            bufferDesc.SizeInBytes = (UINT)m_bufferSize;

            // 定数バッファビューを生成.
            pDevice->CreateConstantBufferView( &bufferDesc, m_handle.back() );

            return true;
        }



        DepthStencilBuffer::DepthStencilBuffer()
            : Buffer()
        {
        };


        DepthStencilBuffer::~DepthStencilBuffer()
        {
        };

        bool DepthStencilBuffer::Create( ID3D12Device* pDevice, int width, int height, D3D12_RESOURCE_STATES initState, D3D12_CLEAR_VALUE* pClearValue )
        {
            // ヒーププロパティの設定.
            D3D12_HEAP_PROPERTIES prop = {};
            prop.Type = D3D12_HEAP_TYPE_DEFAULT;
            prop.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
            prop.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
            prop.CreationNodeMask = 0;
            prop.VisibleNodeMask = 0;

            // リソースの設定.
            D3D12_RESOURCE_DESC desc = {};
            desc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
            desc.Alignment = 0;
            desc.Width = width;
            desc.Height = height;
            desc.DepthOrArraySize = 1;
            desc.MipLevels = 1;
            desc.Format = DXGI_FORMAT_R32_TYPELESS;
            desc.SampleDesc.Count = 1;
            desc.SampleDesc.Quality = 0;
            desc.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;
            desc.Flags = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL;

            return Buffer::Create( pDevice, prop, desc, initState, pClearValue );
        }

        RenderTarget::RenderTarget()
            : Buffer()
        {
        };


        RenderTarget::~RenderTarget()
        {
        };
    }
}