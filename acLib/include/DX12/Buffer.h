#pragma once

namespace acLib
{
    namespace DX12
    {
        using namespace Microsoft::WRL;
        using namespace std;

        class Buffer
        {
        public:
            Buffer();
            ~Buffer();

            void SetDescHeap( shared_ptr<DescriptorHeap> heap ) { m_pDescHeap = heap; }
            shared_ptr<DescriptorHeap> GetDescHeap() const { return m_pDescHeap; }

            bool Create( ID3D12Device* pDevice, D3D12_HEAP_PROPERTIES& prop, D3D12_RESOURCE_DESC& desc, D3D12_RESOURCE_STATES initState, D3D12_CLEAR_VALUE* pClearValue = nullptr);
            virtual bool CreateBufferView( ID3D12Device* pDevice, const D3D12_RESOURCE_DESC& desc );

            virtual bool Map( void* pData, int size );
            virtual void Unmap();

            ID3D12Resource* GetBuffer() { return m_pBuffer.Get(); }
            ID3D12Resource** GetBufferAddressOf() { return m_pBuffer.GetAddressOf(); }


            D3D12_CPU_DESCRIPTOR_HANDLE GetHadle() const
            {
                return m_handle;
            }

        protected:
            bool AdvanceHadle();

        protected:
            ComPtr<ID3D12Resource>          m_pBuffer;
            UINT8*                          m_pDataBegin;
            shared_ptr<DescriptorHeap>      m_pDescHeap;
            D3D12_CPU_DESCRIPTOR_HANDLE     m_handle;
        };


        class VertexBuffer : public Buffer
        {
        public:
            VertexBuffer();
            ~VertexBuffer();

            virtual bool CreateBufferView( ID3D12Device* pDevice, const D3D12_RESOURCE_DESC& desc );

            void SetDataStride( size_t stride ) { m_dataStride = stride; }
            const D3D12_VERTEX_BUFFER_VIEW& GetVertexBV() const
            {
                return m_vertexBufferView;
            }

        private:
            size_t                          m_dataStride;
            D3D12_VERTEX_BUFFER_VIEW        m_vertexBufferView;
        };

        class IndexBuffer : public Buffer
        {
        public:
            IndexBuffer();
            ~IndexBuffer();

            virtual bool CreateBufferView( ID3D12Device* pDevice, const D3D12_RESOURCE_DESC& desc );

            void SetDataFormat( DXGI_FORMAT format ) { m_dataFormat = format; }
            const D3D12_INDEX_BUFFER_VIEW& GetIndexBV() const
            {
                return m_depthStencilBufferView;
            }

        private:
            DXGI_FORMAT                    m_dataFormat;
            D3D12_INDEX_BUFFER_VIEW        m_depthStencilBufferView;
        };

        class ConstantBuffer : public Buffer
        {
        public:
            ConstantBuffer();
            ~ConstantBuffer();

            virtual bool CreateBufferView( ID3D12Device* pDevice, const D3D12_RESOURCE_DESC& desc  );

        private:
            size_t                          m_bufferSize;
        };

        class DepthStencilBuffer : public Buffer
        {
        public:
            DepthStencilBuffer();
            ~DepthStencilBuffer();

            virtual bool CreateBufferView( ID3D12Device* pDevice, const D3D12_RESOURCE_DESC& desc );

        private:
            D3D12_DEPTH_STENCIL_VIEW_DESC        m_depthStencilBufferView;
        };

        class RenderTarget : public Buffer
        {
        public:
            RenderTarget();
            ~RenderTarget();

            virtual bool CreateBufferView( ID3D12Device* pDevice, const D3D12_RESOURCE_DESC& desc );

        private:
            D3D12_RENDER_TARGET_VIEW_DESC        m_renderTargetBufferView;
        };
    }
}
