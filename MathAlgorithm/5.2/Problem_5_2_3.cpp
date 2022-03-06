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
    std::uint32_t loopIndex = 0;
    bool hasLoop = false;
    for (decltype(n) i = 1; i <= n; ++i)
    {
        auto dest = dests[route[i-1]];
        for(decltype(n) j = 0; j < route.size(); ++j)
        {
            if(route[j] == dest)
            {
                loopIndex = j;
                hasLoop = true;
                break;
            }
        }

        if(hasLoop)
            break;

        route.push_back(dest);
    }

    auto index = k;
    if (hasLoop)
    {
        if(k >= loopIndex)
        {
            auto length = route.size() - loopIndex;
            index = (k + length) % route.size();
        }
    }
    std::cout << route[index] << std::endl;

    return 0;
}