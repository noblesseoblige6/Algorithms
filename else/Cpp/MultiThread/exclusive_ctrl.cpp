#include <cstdint>
#include <iostream>
#include <mutex>
#include <thread>
#include <algorithm>

namespace
{
    std::uint32_t _count{};
    std::mutex _mutex;
}

void threadA()
{
    for(int i=0; i<100000; ++i)
        ++_count;
}

void threadB()
{
    for (int i = 0; i<50000; ++i)
        ++_count;
}

void add()
{
    std::lock_guard<std::mutex> lock(_mutex);
    ++_count;
}

void threadMutexA()
{
    for (int i = 0; i<100000; ++i)
        add();
}

void threadMutexB()
{
    for (int i = 0; i<50000; ++i)
        add();
}

template<class Func>
void run_thread(Func func1, Func func2)
{
    _count = 0;

    std::thread workers[] = 
    {
        std::thread(func1),
        std::thread(func2),
    };

    std::for_each(std::begin(workers), std::end(workers), [](auto& w){w.join();});
}

int main()
{
    run_thread(threadA, threadB);
    std::cout << "Simple threads --> " << _count << std::endl;

    run_thread(threadMutexA, threadMutexB);
    std::cout << "Threads with exclusive cotrol --> " << _count << std::endl;

    return 0;
}