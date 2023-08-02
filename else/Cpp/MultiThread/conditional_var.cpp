#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

namespace
{
    std::mutex _mtx;
    std::condition_variable _cv;
    bool _wake = false; // spurious wakeup防止用
}

void threadA(void)
{
    // cv_.notify_allが呼ばれるまで待機
    std::cout << "ThreadA待機\n";
    std::unique_lock<std::mutex> lock(_mtx);
    _cv.wait(lock, []{return _wake;});
    std::cout << "ThreadA待機解除\n";
}

void threadB(void)
{
    // Aが待機するまで待つ
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::unique_lock<std::mutex> lock(_mtx);
    std::cout << "ThreadB待機解除\n";
    _wake = true;
    _cv.notify_all();
    std::cout << "ThreadB終了\n";
}

int main()
{
    std::thread th_a(threadA);
    std::thread th_b(threadB);

    th_b.join();
    th_a.join();

    return 0;
}