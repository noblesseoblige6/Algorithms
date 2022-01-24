#include <iostream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <vector>

int main()
{
    std::uint32_t n;
    std::cin >> n;

    std::vector<std::uint32_t> a(n+1, 0);
    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, n, a.begin()+1);

    std::vector<std::uint64_t> dp(n+1, 0);

    dp[1] = a[1];
    for (decltype(n) i = 2; i <= n; ++i)
    {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + a[i]);
    }

    std::cout << dp[n] << std::endl;

    return 0;
}