#include <iostream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <vector>

int main()
{
    std::uint32_t n, w;
    std::cin >> n >> w;

    std::vector<std::uint64_t> ws(n+1, 0);
    std::vector<std::uint64_t> vs(n+1, 0);
    for (auto i = 1; i <= n; ++i)
        std::cin >> ws[i] >> vs[i];

    std::vector<std::vector<std::uint64_t>> dp(n+1, std::vector<std::uint64_t>(w+1, 0));
    for (auto i = 1; i <= n; ++i)
        for (auto j = 0; j <= w; ++j)
            dp[i][j] = (j < ws[i]) ? dp[i - 1][j] : std::max(dp[i - 1][j], dp[i - 1][j - ws[i]] + vs[i]);

    std::cout << dp[n][w] << std::endl;

    return 0;
}