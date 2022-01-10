#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cmath>
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
    std::vector<std::uint64_t> counts(maxVal+1, 0);
    for(auto const& val : v)
        ++counts[val];

    constexpr std::uint64_t total = 100000;
    std::uint64_t res = 0;
    for (auto i = minVal; i <= (minVal+maxVal)/2; ++i)
    {
        auto tmp = total - i;
        if (i == tmp)
            res += alg::Combination(counts[i], 2);
        else
            res += counts[i] * counts[tmp];
    }

    std::cout << res << std::endl;

    return 0;
}