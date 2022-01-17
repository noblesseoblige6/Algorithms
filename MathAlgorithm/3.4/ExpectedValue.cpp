#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cmath>
#include <array>
#include <vector>

int main()
{
    std::uint64_t n;
    std::cin >> n;

    std::vector<std::uint64_t> a(n);
    std::copy_n(std::istream_iterator<std::uint64_t>{std::cin}, a.size(), a.begin());

    std::vector<std::uint64_t> b(n);
    std::copy_n(std::istream_iterator<std::uint64_t>{std::cin}, b.size(), b.begin());

    decltype(n) res = 0;
    for (decltype(n) i = 0; i < n; ++i)
    {
        res += (1.0f / 3.0f) * a[i] + (2.0f / 3.0f) * b[i];
    }

    std::cout << res << std::endl;

    return 0;
}