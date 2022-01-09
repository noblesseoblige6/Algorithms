#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>

namespace alg
{
    std::uint64_t GCD(std::uint64_t a, std::uint64_t b)
    {
        if (a == 0 || b == 0)
            return std::max(a, b);

        auto bigger = std::max(a, b);
        auto less = std::min(a, b);

        return GCD(bigger % less, less);
    }

    std::uint64_t GCD(std::vector<std::uint64_t> const &values)
    {
        auto res = GCD(values[0], values[1]);
        for (std::int32_t i = 2; i < static_cast<std::int32_t>(values.size()); ++i)
            res = GCD(res, values[i]);

        return res;
    }

    std::uint64_t LCM(std::uint64_t a, std::uint64_t b)
    {
        return (a / GCD(a, b)) * b;
    }

    std::uint64_t LCM(std::vector<std::uint64_t> const& values)
    {
        auto res = LCM(values[0], values[1]);
        for (std::int32_t i = 2; i < static_cast<std::int32_t>(values.size()); ++i)
            res = LCM(res, values[i]);

        return res;
    }
}

int main()
{
    std::uint64_t n;
    std::cin >> n;

    std::vector<std::uint64_t> v(n);
    std::copy_n(std::istream_iterator<std::uint64_t>{std::cin}, v.size(), v.begin());

    // 3.2.2
    //  auto res = alg::GCD(v);
    // 3.2.3
    auto res = alg::LCM(v);
    std::cout << res << std::endl;

    return 0;
}