#include <bits/stdc++.h>

int main()
{
    std::uint32_t n;
    std::cin >> n;

    std::vector<std::uint32_t> a(n, 0);
    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, n, a.begin());

    std::uint64_t res = 0;
    std::uint64_t num = 1;
    for (decltype(n) i = 0; i < n; ++i)
    {
        res += a[i] * num;
        num *= 2;
        res %= 1000000007;
    }

    std::cout << res << std::endl;

    return 0;
}