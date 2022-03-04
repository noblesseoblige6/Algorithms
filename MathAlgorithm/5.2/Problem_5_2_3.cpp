#include <bits/stdc++.h>

int main()
{
    std::uint32_t n;
    std::uint64_t k;
    std::cin >> n >> k;

    std::vector<std::uint32_t> dests(n+1, 0);
    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, n, dests.begin()+1);

    std::vector<std::uint32_t> route;
    route.push_back(1);
    for (decltype(n) i = 1; i <= n; ++i)
    {
        auto dest = dests[route[i-1]];
        if(dest == 1)
            break;
        route.push_back(dest);
    }

    auto index = k % static_cast<std::uint64_t>(route.size());
    std::cout << route[index] << std::endl;

    return 0;
}