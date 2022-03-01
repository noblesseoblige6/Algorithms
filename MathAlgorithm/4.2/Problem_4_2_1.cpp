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

    std::vector<std::int64_t> cusum(n, 0);
    for(decltype(n) i = 1; i < n; ++i)
        cusum[i] = cusum[i - 1] + a[i];

    std::uint64_t res = 0;
    for (decltype(m) i = 1; i < m; ++i)
        res += std::abs(cusum[b[i]-1] - cusum[b[i - 1]-1]);

    std::cout << res << std::endl;
}