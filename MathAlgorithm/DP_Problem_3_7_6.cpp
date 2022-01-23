#include <iostream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <vector>

int main()
{
    std::uint32_t n;
    std::cin >> n;

    std::vector<std::int32_t> a(n+1, 0);
    std::copy_n(std::istream_iterator<std::int32_t>{std::cin}, n, a.begin()+1);

    std::vector<std::vector<std::uint64_t>> dp(n+1, std::vector<std::uint64_t>(n+1, 0));
    for (auto i = 1; i <= n; ++i)
        for (auto j = 0; j <= n; ++j)
        {
            if(j < 2)
                dp[i][j] = (j < 1) ? dp[i - 1][j] : dp[i - 1][0] + a[i];
            else
                dp[i][j] = (j >= 2) ? dp[i - 1][j] : std::max(dp[i - 1][j], dp[i - 1][j-2] + a[i]);
        }

    std::cout << dp[n][n] << std::endl;

    return 0;
}