#include <iostream>
#include <array>

/// プログラミングコンテストチャレンジブックp42 硬貨の問題

namespace algorithm::greedy
{
    int Solve(int total, const std::array<int, 6> &coins, const std::array<int, 6> &counts)
    {
        int res = 0;
        int tmp = total;
        for (int i = 5; i >= 0; --i)
        {
            int p = std::min(tmp / coins[i], counts[i]);
            tmp -= p * coins[i];
            res += p;
        }

        return res;
    }
}

int main()
{
    std::array<int, 6> coins = {1, 5, 10, 50, 100, 500};
    std::array<int, 6> counts = {0};
    int total;

    std::cin >> counts[0] >> counts[1] >> counts[2] >> counts[3] >> counts[4] >> counts[5] >> total;
    std::cout << algorithm::greedy::Solve(total, coins, counts) << std::endl;

    return 0;
}