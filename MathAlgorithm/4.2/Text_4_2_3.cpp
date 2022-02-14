#include <bits/stdc++.h>

int main()
{
    std::uint32_t n, q;
    std::cin >> n >> q;
    
    std::vector<std::uint32_t> snows(q, 0);
    std::vector<std::pair<std::uint32_t, std::uint32_t>> districts(q);
    for(auto i = 0; i < q; ++i)
        std::cin >> districts[i].first >> districts[i].second >> snows[i];

    std::vector<std::int32_t> res(n+1, 0);
    for(auto i = 0; i < q; ++i)
    {
        res[districts[i].first-1] += snows[i];
        res[districts[i].second] -= snows[i];
    }

    for(auto i = 0; i < n-1; ++i)
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