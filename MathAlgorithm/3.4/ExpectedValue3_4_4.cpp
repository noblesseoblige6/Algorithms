#include <iostream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <vector>

int main()
{
    std::uint32_t n;
    std::cin >> n;

    std::double_t res = 0;
    for (decltype(n) i = 0; i < n; ++i)
        res += static_cast<double_t>(i+1)/(n-i);

    std::cout << res << std::endl;

    return 0;
}