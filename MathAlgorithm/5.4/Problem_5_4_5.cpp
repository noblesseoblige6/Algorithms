#include <bits/stdc++.h>

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
        // Note: divide first to avoid overflow
        return (a / GCD(a, b)) * b;
    }

    std::uint64_t LCM(std::vector<std::uint64_t> const &values)
    {
        auto res = LCM(values[0], values[1]);
        for (std::int32_t i = 2; i < static_cast<std::int32_t>(values.size()); ++i)
            res = LCM(res, values[i]);

        return res;
    }

    template <typename T>
    bool is_pow2(T x)
    {
        if (x == 0)
            return false;

        return (x & (x - 1)) == 0;
    }
}

int main()
{
    std::uint64_t n, k;
    std::cin >> n >> k;

    std::vector<std::uint32_t> v(k);
    std::copy_n(std::istream_iterator<std::uint64_t>{std::cin}, k, v.begin());

    std::uint32_t res = 0;
    for (std::uint32_t i = 1; i < (1 << k); ++i)
    {
        std::uint32_t count = 0;
        std::uint32_t lcm = 1;
        for (std::uint32_t j = 0; j < k; ++j)
        {
            if ((i & (1 << j)) == 0)
                continue;

            ++count;
            lcm = alg::LCM(lcm, v[j]);
        }

        std::uint32_t multi = static_cast<std::uint32_t>(n / lcm);
        if (count % 2 != 0)
            res += multi;
        else
            res -= multi;
    }

    std::cout << res << std::endl;

    return 0;
}