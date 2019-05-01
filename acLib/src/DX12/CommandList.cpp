namespace acLib
{
    using namespace util;

    namespace DX12
    {
        CommandList::CommandList( ID3D12Device* pDevice, D3D12_COMMAND_LIST_TYPE listType )
        {
            Create( pDevice, listType );
        }

        CommandList::~CommandList()
        {
            m_pCommandList.Reset();
            m_pCommandAllocator.Reset();
        }

        bool CommandList::Create( ID3D12Device* pDevice, D3D12_COMMAND_LIST_TYPE listType )
        {
            HRESULT hr = S_OK;

            // create command allocator
            hr = pDevice->CreateCommandAllocator( listType,
                                                  IID_ID3D12CommandAllocator,
                                                  (void**)(m_pCommandAllocator.ReleaseAndGetAddressOf()) );

            if (FAILED( hr ))
            {
                Log::Output( Log::LOG_LEVEL_ERROR, "CreateCommandAllocator() Failed." );
                return false;
            }

            hr = pDevice->CreateCommandList( 1,
                                             listType,
                                             m_pCommandAllocator.Get(),
                                             nullptr,
                                             IID_ID3D12GraphicsCommandList,
                                             (void**)m_pCommandList.ReleaseAndGetAddressOf() );

            if (FAILED( hr ))
            {
                Log::Output( Log::LOG_LEVEL_ERROR, "CreateCommandList() Failed." );
                return false;
            }

            m_pCommandList->Close();

            return true;
        }

        void CommandList::SetDescriptorHeaps( int count, shared_ptr<DescriptorHeap> pDescHeap )
        {
            m_pCommandList->SetDescriptorHeaps( count, pDescHeap->GetDescHeapAddress() );
            m_pCommandList->SetGraphicsRootDescriptorTable( 0, pDescHeap->GetGPUHandle() );
        }

        void CommandList::SetRootSignature( shared_ptr<RootSignature> pRootSignature )
        {
            m_pCommandList->SetGraphicsRootSignature( pRootSignature->GetRootSignature() );
        }

        void CommandList::SetPipelineState( shared_ptr<PipelineState> pPipelineState )
        {
            m_pCommandList->SetPipelineState( pPipelineState->GetPipelineState() );
        }

        void CommandList::SetViewport( const D3D12_VIEWPORT& vp )
        {
            D3D12_RECT sr;
            sr.left   = static_cast<long>(vp.TopLeftX);
            sr.top    = static_cast<long>(vp.TopLeftY);
            sr.right  = static_cast<long>(vp.Width);
            sr.bottom = static_cast<long>(vp.Height);

            SetViewport( vp, sr );
        }

        void CommandList::SetViewport( const D3D12_VIEWPORT& vp, D3D12_RECT& sr )
        {
            m_pCommandList->RSSetViewports( 1, &vp );
            m_pCommandList->RSSetScissorRects( 1, &sr );
        }

        void CommandList::SetTargets( D3D12_CPU_DESCRIPTOR_HANDLE* pHandleRTV, D3D12_CPU_DESCRIPTOR_HANDLE* pHandleDSV )
        {
            int countRT = pHandleRTV != nullptr ? 1 : 0;
            m_pCommandList->OMSetRenderTargets( countRT, pHandleRTV, FALSE, pHandleDSV );
        }

        void CommandList::ClearTargets( D3D12_CPU_DESCRIPTOR_HANDLE* pHandleRTV, float* clearColor,
                                        D3D12_CPU_DESCRIPTOR_HANDLE* pHandleDSV, D3D12_CLEAR_FLAGS flag, float val )
        {
            if(pHandleRTV != nullptr)
                m_pCommandList->ClearRenderTargetView( *pHandleRTV, clearColor, 0, nullptr );

            if(pHandleDSV != nullptr)
                m_pCommandList->ClearDepthStencilView( *pHandleDSV, D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr );
        }

        void CommandList::Draw( D3D_PRIMITIVE_TOPOLOGY topology, 
                                shared_ptr<VertexBuffer> pVertexBuffer,
                                shared_ptr<IndexBuffer> pIndexBuffer,
                                int indexCount, 
                                int instanceCount )
        {
            m_pCommandList->IASetPrimitiveTopology( topology );

            m_pCommandList->IASetVertexBuffers( 0, 1, &pVertexBuffer->GetVertexBV() );
            m_pCommandList->IASetIndexBuffer( &pIndexBuffer->GetIndexBV() );

            m_pCommandList->DrawIndexedInstanced( indexCount, instanceCount, 0, 0, 0 );
        }

        void CommandList::Begin( shared_ptr<Buffer>    pResource,
                                 D3D12_RESOURCE_STATES resourceStateFrom,
                                 D3D12_RESOURCE_STATES resourceStateTo )
        {
            m_pResource = pResource;
            m_resourceStateFrom = resourceStateFrom;
            m_resourceStateTo = resourceStateTo;

            SetResourceBarrier( m_pResource, m_resourceStateFrom, m_resourceStateTo );
        }

        void CommandList::End()
        {
            SetResourceBarrier( m_pResource, m_resourceStateTo, m_resourceStateFrom );
            m_pCommandList->Close();
        }

        void CommandList::Reset( shared_ptr<PipelineState> pPipelineState )
        {
            HRESULT hr = S_OK;

            hr = m_pCommandAllocator->Reset();
            if (FAILED( hr ))
                Log::Output( Log::LOG_LEVEL_DEBUG, "ID3D12CommandAllocator::Reset Failed" );

            hr = m_pCommandList->Reset( m_pCommandAllocator.Get(), pPipelineState->GetPipelineState() );
            if (FAILED( hr ))
                Log::Output( Log::LOG_LEVEL_DEBUG, "ID3D12GraphicsCommandList::Reset Failed" );
        }

        void CommandList::SetResourceBarrier( shared_ptr<Buffer>     pResource,
                                              D3D12_RESOURCE_STATES  stateBefore,
                                              D3D12_RESOURCE_STATES  stateAfter )
        {
            D3D12_RESOURCE_BARRIER desc = {};
            desc.Type                   = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
            desc.Transition.pResource   = pResource->GetBuffer();
            desc.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
            desc.Transition.StateBefore = stateBefore;
            desc.Transition.StateAfter  = stateAfter;

            m_pCommandList->ResourceBarrier( 1, &desc );
        }

    }
}