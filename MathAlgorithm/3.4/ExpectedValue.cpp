#include <iostream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <vector>

int main()
{
    std::uint32_t n;
    std::cin >> n;

    std::vector<std::uint32_t> a(n);
    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, a.size(), a.begin());

    std::vector<std::uint32_t> b(n);
    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, b.size(), b.begin());

    std::double_t res = 0;
    for (decltype(n) i = 0; i < n; ++i)
        res += (a[i]+ (2.0 * b[i])) / 3.0;

    std::cout << res << std::endl;

    return 0;
}