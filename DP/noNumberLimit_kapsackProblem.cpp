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
                dp[i + 1][j] = (j - items[i].first < 0) ? dp[i][j] : std::max(dp[i][j], dp[i + 1][j - items[i].first] + items[i].second);
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