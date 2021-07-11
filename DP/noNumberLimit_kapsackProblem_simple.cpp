#include <iostream>
#include <vector>

namespace DP
{
    int Solve(int n, int w, const std::vector<std::pair<int, int>> &items)
    {
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(w+1, 0));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= w; ++j)
            {
                for(int k = 0; k*items[i].first <= j; ++k)
                {
                    dp[i+1][j] = std::max(dp[i+1][j], dp[i][j-k*items[i].first] + k*items[i].second);
                }
            }
        }

        return dp[n][w];
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> items;
    for (int i = 0; i < n; ++i)
    {
        int weight, value;
        std::cin >> weight >> value;
        items.emplace_back(weight, value);
    }

    int w;
    std::cin >> w;
    std::cout << DP::Solve(n, w, items) << std::endl;
    return 0;
}