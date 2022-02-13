#include <bits/stdc++.h>

int main()
{
    std::uint32_t n, q;
    std::cin >> n >> q;
    
    std::vector<std::uint32_t> a(n+1, 0);
    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, n, a.begin()+1);

    std::vector<std::pair<std::uint32_t, std::uint32_t>> days;
    for(auto i = 0; i < q; ++i)
    {
        std::uint32_t l, r;
        std::cin >> l >> r;
        days.emplace_back(l, r);
    }

    std::vector<std::uint32_t> cusum(n+1, 0);
    for(auto i = 1; i <= n; ++i )
    {
        cusum[i] = cusum[i-1] + a[i];
    }

    for(auto day_i = 0; day_i < q; ++day_i )
    {
        std::cout << cusum[days[day_i].second] - cusum[days[day_i].first-1] << std::endl;
    }
}