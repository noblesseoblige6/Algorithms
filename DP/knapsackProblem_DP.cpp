#include <iostream>
#include <vector>

namespace DP
{
    int Solve(int n, int w, const std::vector<std::pair<int, int>> &items)
    {
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(w+1, 0));

        for (int i = n-1; i >= 0; --i)
        {
            for (int j = 0; j <= w; ++j)
            {
                if(j < items[i].first)
                {
                    dp[i][j] = dp[i+1][j];
                }
                else
                {
                    dp[i][j] = std::max(dp[i + 1][j], dp[i + 1][j - items[i].first] + items[i].second);
                }
            }
        }

        return dp[0][w];
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