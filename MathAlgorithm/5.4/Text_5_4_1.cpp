#include <bits/stdc++.h>

int main()
{
    std::int32_t n, k;
    std::cin >> n >> k;

    std::int64_t complementary = 0;
    for(decltype(n) a = 1; a <= n; ++a)
    {
        const auto lower = std::max(1, a - (k - 1));
        const auto upper = std::min(n, a + (k - 1));

        for (decltype(n) b = lower; b <= upper; ++b)
        {
            for (decltype(n) c = lower; c <= upper; ++c)
            {
                if (std::abs(b - c) <= k - 1)
                    ++complementary;
            }
        }
    }

    auto total = static_cast<std::int64_t>(n) * n * n;
    std::cout << total - complementary << std::endl;

    return 0;
}