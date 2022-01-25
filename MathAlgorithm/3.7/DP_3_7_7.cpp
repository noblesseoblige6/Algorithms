#include <iostream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <vector>

int main()
{
    std::uint32_t n;
    std::cin >> n;

    std::vector<std::int32_t> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for (decltype(n) i = 2; i <= n; ++i)
        dp[i] = dp[i-2]+dp[i-1];

    std::cout << dp.back() << std::endl;

    return 0;
}