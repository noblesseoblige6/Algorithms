namespace acLib
{
    using namespace util;

    namespace DX12
    {
        Buffer::Buffer()
            : m_pBuffer( nullptr )
            , m_pDataBegin( 0 )
            , m_pDescHeap( nullptr )
            , m_handle( {} )
        {
        };


        Buffer::~Buffer()
        {
            if (m_pBuffer != nullptr)
            {
                Unmap();
                m_pBuffer.Reset();
            }
        };

        bool Buffer::Create( ID3D12Device* pDevice, D3D12_HEAP_PROPERTIES& prop, D3D12_RESOURCE_DESC& desc )
        {
            HRESULT hr = S_OK;

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

            CreateBufferView( pDevice, desc );

            return true;
        };

        bool Buffer::CreateBufferView( ID3D12Device* pDevice, const D3D12_RESOURCE_DESC& desc )
        {
            if (!AdvanceHadle())
                return false;

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

        bool Buffer::AdvanceHadle()
        {
            if (m_pDescHeap == nullptr)
            {
                Log::Output( Log::LOG_LEVEL_ERROR, "Buffer::AdvanceHadle --> No descriptor heap." );
                return false;
            }
            
            size_t count = m_pDescHeap->GetBufferCount();
            m_handle = m_pDescHeap->GetCPUStartHandle();
            m_handle.ptr += m_pDescHeap->GetIncrementSize() * count;

            m_pDescHeap->SetBufferCount( count + 1 );

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

        bool VertexBuffer::CreateBufferView( ID3D12Device* pDevice, const D3D12_RESOURCE_DESC& desc )
        {
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

        bool IndexBuffer::CreateBufferView( ID3D12Device* pDevice, const D3D12_RESOURCE_DESC& desc )
        {
            m_depthStencilBufferView.BufferLocation = m_pBuffer->GetGPUVirtualAddress();
            m_depthStencilBufferView.Format         = m_dataFormat;
            m_depthStencilBufferView.SizeInBytes    = (UINT)desc.Width;

            return true;
        }

        //----------------------------------------------
        ConstantBuffer::ConstantBuffer()
            : Buffer()
            , m_bufferSize( 0 )
        {}


        ConstantBuffer::~ConstantBuffer()
        {}

        bool ConstantBuffer::Create( ID3D12Device* pDevice, D3D12_HEAP_PROPERTIES& prop, D3D12_RESOURCE_DESC& desc )
        {
            HRESULT hr = S_OK;

            Buffer::Create( pDevice, prop, desc );

            return true;
        };

        bool ConstantBuffer::CreateBufferView( ID3D12Device* pDevice, const D3D12_RESOURCE_DESC& desc )
        {
            if (!Buffer::CreateBufferView( pDevice, desc ))
            {
                return false;
            }

            m_bufferSize = desc.Width;

            // 定数バッファビューの設定.
            D3D12_CONSTANT_BUFFER_VIEW_DESC bufferDesc = {};
            bufferDesc.BufferLocation = m_pBuffer->GetGPUVirtualAddress();
            bufferDesc.SizeInBytes    = m_bufferSize;

            // 定数バッファビューを生成.
            pDevice->CreateConstantBufferView( &bufferDesc, m_handle );

            return true;
        }



        DepthStencilBuffer::DepthStencilBuffer()
            : Buffer()
        {
        };


        DepthStencilBuffer::~DepthStencilBuffer()
        {
        };

        bool DepthStencilBuffer::Create( ID3D12Device* pDevice, D3D12_HEAP_PROPERTIES& prop, D3D12_RESOURCE_DESC& desc, D3D12_CLEAR_VALUE& clearValue )
        {
            HRESULT hr = S_OK;

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

            CreateBufferView( pDevice, desc );

            return true;
        };

        bool DepthStencilBuffer::CreateBufferView( ID3D12Device* pDevice, const D3D12_RESOURCE_DESC& desc )
        {
            if (!Buffer::CreateBufferView( pDevice, desc ))
            {
                return false;
            }

            D3D12_DEPTH_STENCIL_VIEW_DESC bufferDesc = {};
            bufferDesc.ViewDimension      = D3D12_DSV_DIMENSION_TEXTURE2D;
            bufferDesc.Format             = DXGI_FORMAT_D32_FLOAT;
            bufferDesc.ViewDimension      = D3D12_DSV_DIMENSION_TEXTURE2D;
            bufferDesc.Texture2D.MipSlice = 0;
            bufferDesc.Flags              = D3D12_DSV_FLAG_NONE;

            pDevice->CreateDepthStencilView( m_pBuffer.Get(), &bufferDesc, m_handle );

            return true;
        }

        RenderTarget::RenderTarget()
            : Buffer()
        {
        };


        RenderTarget::~RenderTarget()
        {
        };

        bool RenderTarget::CreateBufferView( ID3D12Device* pDevice, const D3D12_RESOURCE_DESC& desc )
        {
            if (!Buffer::CreateBufferView( pDevice, desc ))
            {
                return false;
            }

            D3D12_RENDER_TARGET_VIEW_DESC bufferDesc;
            bufferDesc.Format               = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
            bufferDesc.ViewDimension        = D3D12_RTV_DIMENSION_TEXTURE2D;
            bufferDesc.Texture2D.MipSlice   = 0;
            bufferDesc.Texture2D.PlaneSlice = 0;

            pDevice->CreateRenderTargetView( m_pBuffer.Get(), &bufferDesc, m_handle );

            return true;
        }
    }
}