#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cmath>
#include <array>
#include <vector>

namespace alg
{
    template<std::size_t N>
    std::size_t Fractorial()
    {
        if constexpr (N == 0)
            return 1;
        else
            return N * Fractorial<N - 1>();
    }

    template<std::size_t N, std::size_t R>
    std::double_t Permutation()
    {
        return Fractorial<N>()/Fractorial<N-R>();
    }

    template<std::size_t N, std::size_t R>
    std::double_t Combination()
    {
        return Fractorial<N>()/(Fractorial<R>()*Fractorial<N-R>());
    }

    std::uint64_t Combination(std::uint64_t n, std::uint64_t k)
    {
        if (n == k || k == 0)
            return 1;

        return Combination(n - 1, k - 1) + Combination(n - 1, k);
    }
}

int main()
{
    std::uint64_t n;
    std::cin >> n;

    std::vector<std::uint64_t> v(n);
    std::copy_n(std::istream_iterator<std::uint64_t>{std::cin}, v.size(), v.begin());

    constexpr std::uint64_t minVal = 1;
    constexpr std::uint64_t maxVal = 99999;
    constexpr std::uint64_t total = 100000;

    std::array<std::uint64_t, maxVal+1> counts = {};
    for(auto const& val : v)
        ++counts[val];

    std::uint64_t res = 0;
    for (auto i = minVal; i <= maxVal/2; ++i)
    {
        auto tmp = total - i;
        res += counts[i] * counts[tmp];
    }
    res += (counts[total/2] * (counts[total/2]-1))/2;

    std::cout << res << std::endl;

    return 0;
}