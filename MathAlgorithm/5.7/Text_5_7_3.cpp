#include <bits/stdc++.h>

int main()
{
    std::int64_t n;
    std::cin >> n;

    std::vector<std::uint32_t> a(n, 0);
    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, n, a.begin());

    std::int64_t sum = 0;
    for(decltype(n) i = 0; i < n; ++i)
    {
        sum += a[i] * (-n + (2 * i + 1));
    }

    std::cout << sum << std::endl;

    return 0;
}