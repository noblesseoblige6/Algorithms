#include <cstdint>
#include <atomic>
#include <thread>
#include <iostream>
#include <algorithm>

void no_consistency()
{
    std::int32_t x = 0;
    std::atomic<std::int32_t> a(0);

    std::thread workers[] = 
    {
        std::thread([&]()
        {
            x = 100;
            a.store(10, std::memory_order_relaxed);
        }),
        std::thread([&]()
        {
            auto r = a.load(std::memory_order_relaxed);
            if(r == 10)
            {
                // x may be 0 or 100 even if r is 10
                std::cout << x << std::endl;
            }
        }),
    };

    std::for_each(std::begin(workers), std::end(workers), [](auto& w){w.join();});
}

void causal_consistency()
{
    std::int32_t x = 0;
    std::atomic<std::int32_t> a(0);

    std::thread workers[] = 
    {
        std::thread([&]()
        {
            x = 100;
            a.store(10, std::memory_order_release);
        }),
        std::thread([&]()
        {
            auto r = a.load(std::memory_order_acquire);
            if(r == 10)
            {
                // guarantee that x is 100 if r is 10
                std::cout << x << std::endl;
            }
        }),
    };

    std::for_each(std::begin(workers), std::end(workers), [](auto& w){w.join();});

}

int main()
{
    no_consistency();
    //causal_consistency();
    return 0;
}