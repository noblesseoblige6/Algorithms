#include <bits/stdc++.h>

int main()
{
    std::uint32_t w, h;
    std::cin >> h >> w;

    std::uint64_t res = 1;
    if (w != 1 && h != 1)
    {
        auto tmp = static_cast<std::uint64_t>(w) * h;
        res = (tmp % 2 != 0) ? (tmp / 2) + 1 : tmp / 2;
    }

    std::cout << res << std::endl;

    return 0;
}