#include <bits/stdc++.h>

int main()
{
    std::uint32_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::uint32_t>> g(n+1, std::vector<std::uint32_t>(0));
    for(decltype(m) i = 0; i < m; ++i)
    {
        std::uint32_t a, b;
        std::cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    std::uint32_t res = 0;
    for (decltype(n) i = 1; i <= n; ++i)
    {
        std::uint32_t count = 0;
        for (auto const& v : g[i])
        {
            if(v < i)
                ++count;
        }

        if(count == 1)
            ++res;
    }

    std::cout << res << std::endl;
}