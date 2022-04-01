#include <bits/stdc++.h>

int main()
{
    std::int64_t n, s;
    std::cin >> n >> s;

    std::vector<std::uint32_t> a(n + 1);
    std::copy_n(std::istream_iterator<std::uint64_t>{std::cin}, n, a.begin() + 1);

    for (std::int64_t i = 0; i < (1LL << n); ++i)
    {
        std::int64_t sum = 0;
        for (std::int32_t j = 1; j <= n; ++j)
        {
            if ((i & (1LL << (j - 1))) != 0LL)
                sum += a[j];
        }

        if (sum == s)
        {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }

    std::cout << "No" << std::endl;

    return 0;
}