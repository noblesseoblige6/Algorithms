#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cmath>

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
}

int main()
{
    std::cout << alg::Fractorial<3>() << std::endl;
    std::cout << alg::Permutation<4, 2>() << std::endl;
    std::cout << alg::Combination<4, 2>() << std::endl;
    // std::uint64_t n;
    // std::cin >> n;

    // std::vector<std::uint64_t> v(n);
    // std::copy_n(std::istream_iterator<std::uint64_t>{std::cin}, v.size(), v.begin());

    // // 3.2.2
    //  auto res = alg::GCD(v);
    // // 3.2.3
    // // auto res = alg::LCM(v);
    // std::cout << res << std::endl;

    return 0;
}