#include <iostream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <vector>

int main()
{
    std::uint32_t n, s;
    std::cin >> n >> s;

    std::vector<std::int32_t> a(n);
    std::copy_n(std::istream_iterator<std::int32_t>{std::cin}, a.size(), a.begin());

    std::vector<std::vector<std::int32_t>> dp(n+1, std::vector<std::int32_t>(s+1, 0));
    for (decltype(n) i = 1; i <= n; ++i)
        for (decltype(n) j = 0; j <= s; ++j)
            if (j >= dp[i - 1][j])
                dp[i][j] = dp[i - 1][j] + a[i];

    if (dp[n][s] > 0)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;
}