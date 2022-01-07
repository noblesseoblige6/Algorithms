#include <iostream>
#include <algorithm>
#include <vector>

namespace alg
{
    std::uint64_t GDC(std::uint64_t a, std::uint64_t b)
    {
        if (a == 0 || b == 0)
            return std::max(a, b);

        auto bigger = std::max(a, b);
        auto less = std::min(a, b);

        return GDC(bigger % less, less);
    }

    std::uint64_t GDC(std::vector<std::uint64_t> const &values)
    {
        auto res = values.front();
        for (std::int32_t i = 1; i < static_cast<std::int32_t>(values.size()); ++i)
        {
            res = GDC(res, values[i]);
        }

        return res;
    }
}

int main()
{
    std::uint64_t n;
    std::cin >> n;

    std::vector<std::uint64_t> v(n);
    std::copy_n(std::istream_iterator<std::uint64_t>{std::cin}, v.size(), v.begin());

    auto res = alg::GDC(v);
    std::cout << res << std::endl;

    return 0;
}