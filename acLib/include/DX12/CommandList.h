#pragma once

namespace acLib
{
    namespace DX12
    {
        using namespace Microsoft::WRL;

        class CommandList
        {
        public:
            CommandList( ID3D12Device* pDevice, D3D12_COMMAND_LIST_TYPE listType);
            ~CommandList();

            bool Create( ID3D12Device* pDevice, D3D12_COMMAND_LIST_TYPE listType );

            ID3D12GraphicsCommandList* GetCommandList() { return m_pCommandList.Get(); };
            ID3D12GraphicsCommandList** GetGetCommandListAddress() { return m_pCommandList.GetAddressOf(); };

            void SetDescriptorHeaps( int count, shared_ptr<DescriptorHeap> pDescHeap );
            void SetRootSignature( shared_ptr<RootSignature> pRootSignature );
            void SetPipelineState( shared_ptr<PipelineState> pPipelineState );

            void SetViewport( const D3D12_VIEWPORT& vp);
            void SetViewport( const D3D12_VIEWPORT& vp, D3D12_RECT& sr );

            void SetTargets( D3D12_CPU_DESCRIPTOR_HANDLE* pHandleRTV, D3D12_CPU_DESCRIPTOR_HANDLE* pHandleDSV );
            void ClearTargets( D3D12_CPU_DESCRIPTOR_HANDLE* pHandleRTV, float* clearColor, 
                               D3D12_CPU_DESCRIPTOR_HANDLE* pHandleDSV, D3D12_CLEAR_FLAGS flag, float val);

            void Draw( D3D_PRIMITIVE_TOPOLOGY topology, shared_ptr<VertexBuffer> pVertexBuffer, shared_ptr<IndexBuffer> pIndexBuffer, int indexCount, int instanceCount = 1 );

            void Begin( shared_ptr<Buffer>    pResource,
                        D3D12_RESOURCE_STATES resourceStateFrom,
                        D3D12_RESOURCE_STATES resourceStateTo );
            void End();

            void Reset( shared_ptr<PipelineState> pPipelineState );

        protected:
            void SetResourceBarrier( shared_ptr<Buffer>    pResource,
                                     D3D12_RESOURCE_STATES stateBefore,
                                     D3D12_RESOURCE_STATES stateAfter );

        private:
            ComPtr<ID3D12CommandAllocator>       m_pCommandAllocator;
            ComPtr<ID3D12GraphicsCommandList>    m_pCommandList;

            shared_ptr<Buffer>    m_pResource;
            D3D12_RESOURCE_STATES m_resourceStateFrom;
            D3D12_RESOURCE_STATES m_resourceStateTo;
        };
    }
}
