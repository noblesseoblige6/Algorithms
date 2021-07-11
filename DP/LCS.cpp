#include <iostream>
#include <string>
#include <vector>

namespace DP
{
    int Solve(const std::string &s, const std::string &t)
    {
        int n = static_cast<int>(s.size());
        int m = static_cast<int>(t.size());
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if(s[i] == t[j])
                {
                    dp[i+1][j+1] = std::max(dp[i][j]+1, std::max(dp[i + 1][j], dp[i][j + 1]));
                }
                else
                {
                    dp[i+1][j+1] = std::max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[n][m];
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::string s, t;
    std::cin >> s >> t;

    std::cout << DP::Solve(s, t) << std::endl;
    return 0;
}