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
            enum BUFFER_VIEW_TYPE 
            {
                BUFFER_VIEW_TYPE_RENDER_TARGET = 0,
                BUFFER_VIEW_TYPE_DEPTH_STENCIL,
                BUFFER_VIEW_TYPE_CONSTANT,
                BUFFER_VIEW_TYPE_SHADER_RESOURCE,
                BUFFER_VIEW_TYPE_VERTEX,
                BUFFER_VIEW_TYPE_INDEX,
            };
        public:
            Buffer();
            ~Buffer();

            shared_ptr<DescriptorHeap> GetDescHeap(int index = 0) const { return m_pDescHeap[index]; }
            D3D12_CPU_DESCRIPTOR_HANDLE GetHadle( int index = 0 ) const { return m_handle[index]; }

            bool Create( ID3D12Device* pDevice, D3D12_HEAP_PROPERTIES& prop, D3D12_RESOURCE_DESC& desc, D3D12_RESOURCE_STATES initState, D3D12_CLEAR_VALUE* pClearValue = nullptr);
            virtual bool CreateBufferView( ID3D12Device* pDevice, const D3D12_RESOURCE_DESC& desc, shared_ptr<DescriptorHeap> heap, BUFFER_VIEW_TYPE type );

            virtual bool Map( void* pData, int size );
            virtual void Unmap();

            ID3D12Resource* GetBuffer() { return m_pBuffer.Get(); }
            ID3D12Resource** GetBufferAddressOf() { return m_pBuffer.GetAddressOf(); }

        protected:
            bool AdvanceHadle( DescriptorHeap* pHeap, D3D12_CPU_DESCRIPTOR_HANDLE& handle );

        protected:
            ComPtr<ID3D12Resource>          m_pBuffer;
            UINT8*                          m_pDataBegin;
            
            vector<shared_ptr<DescriptorHeap> >     m_pDescHeap;
            vector<D3D12_CPU_DESCRIPTOR_HANDLE>     m_handle;
        };


        class VertexBuffer : public Buffer
        {
        public:
            VertexBuffer();
            ~VertexBuffer();

            virtual bool CreateBufferView( ID3D12Device* pDevice, const D3D12_RESOURCE_DESC& desc, shared_ptr<DescriptorHeap> heap, BUFFER_VIEW_TYPE type );

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

            virtual bool CreateBufferView( ID3D12Device* pDevice, const D3D12_RESOURCE_DESC& desc, shared_ptr<DescriptorHeap> heap, BUFFER_VIEW_TYPE type );

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

            virtual bool CreateBufferView( ID3D12Device* pDevice, const D3D12_RESOURCE_DESC& desc, shared_ptr<DescriptorHeap> heap, BUFFER_VIEW_TYPE type );

        private:
            size_t                          m_bufferSize;
        };

        class DepthStencilBuffer : public Buffer
        {
        public:
            DepthStencilBuffer();
            ~DepthStencilBuffer();

        private:
            D3D12_DEPTH_STENCIL_VIEW_DESC        m_depthStencilBufferView;
        };

        class RenderTarget : public Buffer
        {
        public:
            RenderTarget();
            ~RenderTarget();

        private:
            D3D12_RENDER_TARGET_VIEW_DESC        m_renderTargetBufferView;
        };
    }
}
