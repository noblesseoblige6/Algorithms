#include <bits/stdc++.h>

int main()
{
    std::uint32_t n, q;
    std::cin >> n >> q;
    
    std::vector<std::uint32_t> snows(q, 0);
    std::vector<std::pair<std::uint32_t, std::uint32_t>> districts(q);
    for(auto i = 0; i < q; ++i)
    {
        std::uint32_t l, r, x;
        std::cin >> l >> r >> x;
        districts[i] = {l, r};
        snows[i] = x;
    }

    std::vector<std::int32_t> res(n+2, 0);
    for(auto i = 0; i < q; ++i)
    {
        res[districts[i].first] += snows[i];
        res[districts[i].second+1] -= snows[i];
    }

    for(auto i = 1; i < n; ++i)
    {
        if (res[i+1] > 0)
            std::cout << "<";
        else if (res[i+1] < 0)
            std::cout << ">";
        else
            std::cout << "=";
    }
    std::cout << std::endl;
}