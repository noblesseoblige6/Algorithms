#include <iostream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <vector>

int main()
{
    std::uint32_t n;
    std::cin >> n;

    std::vector<std::int32_t> h(n);
    std::copy_n(std::istream_iterator<std::int32_t>{std::cin}, h.size(), h.begin());

    std::vector<std::int32_t> dp(n);
    dp[0] = 0;
    dp[1] = std::abs(h[1]-h[0]);
    for (decltype(n) i = 2; i < n; ++i)
        dp[i] = std::min(dp[i-1] + std::abs(h[i]-h[i-1]), dp[i-2] + std::abs(h[i]-h[i-2]));

    std::cout << dp.back() << std::endl;

    return 0;
}