#pragma once

namespace acLib
{
    namespace DX12
    {
        using namespace Microsoft::WRL;

        class DescriptorHeap
        {
        public:
            DescriptorHeap();
            ~DescriptorHeap();

            bool Create( ID3D12Device* pDevice, const D3D12_DESCRIPTOR_HEAP_DESC& desc );

            ID3D12DescriptorHeap** GetDescHeapAddress() { return m_pDescHeap.GetAddressOf(); };
            D3D12_GPU_DESCRIPTOR_HANDLE GetGPUHandle() const { return m_pDescHeap->GetGPUDescriptorHandleForHeapStart(); }
            D3D12_CPU_DESCRIPTOR_HANDLE GetCPUStartHandle() const { return m_pDescHeap->GetCPUDescriptorHandleForHeapStart(); }

            size_t GetIncrementSize() const { return m_DescHeapCBSize; }

            void SetBufferCount( size_t count ) { m_bufferCount = count; }
            size_t GetBufferCount() const { return m_bufferCount; }

        private:
            ComPtr<ID3D12DescriptorHeap>    m_pDescHeap;
            size_t m_DescHeapCBSize;
            size_t m_bufferCount;

        };
    }
}
