#include <bits/stdc++.h>

namespace alg
{
    struct Matrix
    {
        std::int32_t p[2][2] = {{1, 0}, {0, 1}};
    };

    Matrix Multiply(Matrix const &a, Matrix const &b)
    {
        Matrix c = {0};
        for (auto i = 0; i < 2; ++i)
        {
            for (auto j = 0; j < 2; ++j)
            {
                for (auto k = 0; k < 2; ++k)
                {
                    c.p[i][k] += a.p[i][j] * b.p[j][k];
                    c.p[i][k] %= static_cast<std::int32_t>(1e9);
                }
            }
        }

        return c;
    }

    Matrix Power(Matrix const& a, std::uint64_t n)
    {
        Matrix tmp = a;
        Matrix res = ((n & 1) != 0) ? tmp : Matrix();
        for(decltype(n) i = 1; i < 64; ++i)
        {
            if ((n & (1ULL << i)) != 0ULL)
                res = Multiply(res, tmp);

            tmp = Multiply(tmp, tmp);
        }

        return res;
    }
}

int main()
{
    std::uint64_t n;
    std::cin >> n;

    alg::Matrix a = {1, 1, 1, 0};
    auto mat = alg::Power(a, n-1);
    std::cout << (mat.p[1][0] + mat.p[1][1]) % static_cast<std::int32_t>(1e9) << std::endl;

    return 0;
}