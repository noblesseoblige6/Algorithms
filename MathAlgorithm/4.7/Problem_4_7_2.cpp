#include <bits/stdc++.h>

namespace alg
{
    struct Matrix
    {
        std::uint64_t p[2][2] = {{1, 0}, {0, 1}};
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
                    c.p[i][k] %= 1000000007;
                }
            }
        }

        return c;
    }

    Matrix Power(Matrix const& a, std::uint64_t n)
    {
        Matrix tmp = a;
        Matrix res = ((n & 1) != 0) ? tmp : Matrix();
        for(auto i = 1; i < 64; ++i)
        {
            tmp = Multiply(tmp, tmp);
            if ((n & (1ULL << i)) != 0ULL)
                res = Multiply(res, tmp);
        }

        return res;
    }
}

int main()
{
    std::uint64_t n;
    std::cin >> n;

    alg::Matrix a = {2, 1, 1, 0};
    auto res = alg::Power(a, n-1);
    std::cout << (res.p[1][0] + res.p[1][1]) % 1000000007 << std::endl;

    return 0;
}