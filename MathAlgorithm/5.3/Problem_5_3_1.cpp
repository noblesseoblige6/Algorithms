#include <bits/stdc++.h>

int main()
{
    std::uint32_t w, h;
    std::cin >> h >> w;

    auto num = static_cast<std::uint64_t>(w) * h;
    auto res =  static_cast<std::uint64_t>(num / 2);
    res = (num % 2 != 0) ? res + 1 : res;

    std::cout << res << std::endl;

    return 0;
}