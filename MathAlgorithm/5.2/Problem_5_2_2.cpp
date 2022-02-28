#include <bits/stdc++.h>

int main()
{
    std::uint64_t n;
    std::cin >> n;

    std::uint64_t tmp = 2;
    while (tmp < n)
        tmp *= 2;

    if (tmp - 1 == n)
        std::cout << "Second" << std::endl;
    else
        std::cout << "First" << std::endl;

    return 0;
}