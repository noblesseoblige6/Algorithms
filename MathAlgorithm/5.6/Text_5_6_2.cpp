#include <bits/stdc++.h>

int main()
{
    std::uint32_t a, b;
    std::cin >> a >> b;

    std::uint32_t res = 1;
    for (decltype(a) i = 1; i <= b; ++i)
    {
        if (std::floor(static_cast<std::float_t>(b) / i) - std::ceil(static_cast<std::float_t>(a) / i) >= 1)
        {
            res = i;
        }
    }

    std::cout << res << std::endl;

    return 0;
}