#include <cstdint>
#include <vector>
#include <atomic>
#include <chrono>
#include <thread>
#include <iostream>

class RingBuffer0
{
public:
    explicit RingBuffer0(std::uint64_t size)
        : m_buffer(size)
    {
    }

public:
    bool enqueue(std::int32_t item)
    {
        const auto size = m_buffer.size();
        if (m_writeIndex - m_readIndex == size)
            return false;

        m_buffer[m_writeIndex % size] = item;
        ++m_writeIndex;
        return true;
    }

    bool dequeue(std::int32_t *dest)
    {
        if (m_writeIndex == m_readIndex)
            return false;
        *dest = m_buffer[m_readIndex % m_buffer.size()];
        ++m_readIndex;
        return true;
    }

private:
    std::vector<std::int32_t> m_buffer;
    std::uint64_t m_readIndex{};
    std::uint64_t m_writeIndex{};
};

class RingBuffer1
{
public:
    explicit RingBuffer1(std::uint64_t size)
        : m_buffer(size)
    {
    }

public:
    bool enqueue(std::int32_t item)
    {
        const auto size = m_buffer.size();
        if (m_writeIndex - m_readIndex == size)
            return false;

        m_buffer[m_writeIndex & (size - 1)] = item;
        ++m_writeIndex;
        return true;
    }

    bool dequeue(std::int32_t *dest)
    {
        if (m_writeIndex == m_readIndex)
            return false;
        *dest = m_buffer[m_readIndex & (m_buffer.size() - 1)];
        ++m_readIndex;
        return true;
    }

private:
    std::vector<std::int32_t> m_buffer;
    std::uint64_t m_readIndex{};
    std::uint64_t m_writeIndex{};
};

class RingBuffer2
{
public:
    explicit RingBuffer2(std::uint64_t size)
        : m_buffer(size)
    {
    }

public:
    bool enqueue(std::int32_t item)
    {
        const auto size = m_buffer.size();
        auto writeIndex = m_writeIndex.load(std::memory_order_relaxed);
        auto readIndex = m_readIndex.load(std::memory_order_acquire);
        if (writeIndex - readIndex == size)
            return false;

        m_buffer[writeIndex & (size - 1)] = item;
        m_writeIndex.store(writeIndex + 1, std::memory_order_release);
        return true;
    }

    bool dequeue(std::int32_t *dest)
    {
        auto readIndex = m_readIndex.load(std::memory_order_relaxed);
        auto writeIndex = m_writeIndex.load(std::memory_order_acquire);
        if (writeIndex == readIndex)
            return false;
        *dest = m_buffer[readIndex % m_buffer.size()];
        m_readIndex.store(readIndex + 1, std::memory_order_release);
        return true;
    }

private:
    std::vector<std::int32_t> m_buffer;
    std::atomic<std::uint64_t> m_readIndex{};
    std::atomic<std::uint64_t> m_writeIndex{};
};

class RingBuffer3
{
public:
    explicit RingBuffer3(std::uint64_t size)
        : m_buffer(size)
    {
    }

public:
    bool enqueue(std::int32_t item)
    {
        const auto size = m_buffer.size();
        auto writeIndex = m_writeIndex.load(std::memory_order_relaxed);
        auto readIndex = m_readIndex.load(std::memory_order_acquire);
        if (writeIndex - readIndex == size)
            return false;

        m_buffer[writeIndex & (size - 1)] = item;
        m_writeIndex.store(writeIndex + 1, std::memory_order_release);
        return true;
    }

    bool dequeue(std::int32_t *dest)
    {
        auto readIndex = m_readIndex.load(std::memory_order_relaxed);
        auto writeIndex = m_writeIndex.load(std::memory_order_acquire);
        if (writeIndex == readIndex)
            return false;
        *dest = m_buffer[readIndex % m_buffer.size()];
        m_readIndex.store(readIndex + 1, std::memory_order_release);
        return true;
    }

private:
    std::vector<std::int32_t> m_buffer;
    alignas(64) std::atomic<std::uint64_t> m_readIndex{};
    alignas(64) std::atomic<std::uint64_t> m_writeIndex{};
};

constexpr uint64_t kCount = 500000;
template <typename RingBufferType>
double benchmark_single(RingBufferType &rb)
{
    auto start = std::chrono::system_clock::now();
    int result;
    for (uint64_t i = 0; i < kCount; ++i)
    {
        for (int j = 0; j < 1000; ++j)
        {
            rb.enqueue(j);
        }
        for (int j = 0; j < 1000; ++j)
        {
            rb.dequeue(&result);
        }
    }
    auto end = std::chrono::system_clock::now();
    double duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
            .count();
    const int count = kCount * (1000 + 1000);
    // std::cout << count << " ops in " << duration << " ms \t" << std::endl;
    return count / duration;
}

template <typename RingBufferType>
double benchmark_multi(RingBufferType &rb)
{
    auto start = std::chrono::system_clock::now();
    std::thread workers[2] =
        {
            std::thread([&]()
                        {
        cpu_set_t cpuset;
        CPU_ZERO(&cpuset);
        CPU_SET(0, &cpuset);
        if (pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t),
                                   &cpuset) == -1) {
          perror("pthread_setaffinity_no");
          exit(1);
        }
        for (uint64_t i = 0; i < kCount; ++i) 
        {
          int count = 1000;
          while (0 < count)
          {
            if (rb.enqueue(count))
            {
              count--;
            }
          }
        } }),
            std::thread([&]()
                        {
        cpu_set_t cpuset;
        CPU_ZERO(&cpuset);
        CPU_SET(1, &cpuset);
        if (pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t),
                                   &cpuset) == -1) {
          perror("pthread_setaffinity_no");
          exit(1);
        }
        int result;
        for (uint64_t i = 0; i < kCount; ++i)
        {
          int count = 1000;
          while (0 < count)
          {
            if (rb.dequeue(&result))
            {
              count--;
            }
          }
        } })};

    for_each(std::begin(workers), std::end(workers), [](auto& w){w.join();});

    auto end = std::chrono::system_clock::now();
    double duration =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    const int count = kCount * (1000 + 1000);
    //std::cerr << count << " ops in " << duration << " ns \t";
    return 1000000000.0 * kCount * (1000 + 1000) / duration;
}

int main()
{
    RingBuffer0 rb0(2 * 1024 * 1024);
    RingBuffer1 rb1(2 * 1024 * 1024);
    RingBuffer2 rb2(2 * 1024 * 1024);
    RingBuffer3 rb3(2 * 1024 * 1024);

    std::cout << "Single thread" << std::endl;
    std::cout << "Simplest Ring Buffer: " << benchmark_single(rb0) << " ops/ms" << std::endl;
    std::cout << "Ring Buffer without modulo: " << benchmark_single(rb1) << " ops/ms" << std::endl;
    std::cout << "Ring Buffer with atomic: " << benchmark_single(rb2) << " ops/ms" << std::endl;

    std::cout << "Multi-threads" << std::endl;
    std::cout << "Ring Buffer with atomic: " << benchmark_single(rb2) << " ops/ms" << std::endl;
    std::cout << "Ring Buffer with atomic: " << benchmark_single(rb3) << " ops/ms" << std::endl;

    return 0;
}