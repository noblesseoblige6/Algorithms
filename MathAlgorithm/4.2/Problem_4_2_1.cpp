#include <bits/stdc++.h>

int main()
{
    std::uint32_t n, m;
    std::cin >> n;
    
    std::vector<std::uint32_t> a(n, 0);
    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, n-1, a.begin()+1);

    std::cin >> m;
    std::vector<std::uint32_t> b(m, 0);
    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, m, b.begin());

    std::vector<std::uint32_t> cusum(n, 0);
    for(decltype(n) i = 1; i < n; ++i)
        cusum[i] = cusum[i - 1] + a[i];

    std::uint64_t res = 0;
    for (decltype(m) i = 1; i < m; ++i)
    {
        auto i_big = std::max(b[i]-1, b[i - 1]-1);
        auto i_less = std::min(b[i]-1, b[i - 1]-1);
        res += cusum[i_big] - cusum[i_less];
    }

    std::cout << res << std::endl;
}