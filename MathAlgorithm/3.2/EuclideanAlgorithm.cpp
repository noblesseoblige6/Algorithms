#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>

namespace alg
{
    std::uint32_t GDC(std::uint32_t a, std::uint32_t b)
    {
        if (a == 0 || b == 0)
            return std::max(a, b);

        auto bigger = std::max(a, b);
        auto less = std::min(a, b);

        return GDC(bigger % less, less);
    }

    std::uint32_t GDC(std::vector<std::uint32_t> const &values)
    {
        auto res = values.front();
        for (std::int32_t i = 1; i < static_cast<std::int32_t>(values.size()); ++i)
        {
            res = GDC(res, values[i]);
        }

        return res;
    }

    std::uint32_t LCM(std::vector<std::uint32_t> const& values)
    {
        auto gdc = values.front();
        for (std::int32_t i = 1; i < static_cast<std::int32_t>(values.size()); ++i)
        {
            gdc = GDC(gdc, values[i]);
        }

        auto res = *(values.end()-1) * *(values.end()-2) / gdc;
        return res;
    }
}

int main()
{
    std::uint32_t n;
    std::cin >> n;

    std::vector<std::uint32_t> v(n);
    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, v.size(), v.begin());

    // 3.2.2
    // auto res = alg::GDC(v);
    // 3.2.33
    auto res = alg::LCM(v);
    std::cout << res << std::endl;

    return 0;
}