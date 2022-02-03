#include <bits/stdc++.h>

namespace alg
{
    template <typename T>
    struct Point
    {
        T x;
        T y;
    };

    template <typename T>
    std::double_t FindLength(Point<T> const &s, Point<T> const &e)
    {
        auto const x = static_cast<std::double_t>(e.x - s.x);
        auto const y = static_cast<std::double_t>(e.y - s.y);

        return std::sqrt(x * x + y * y);
    }
}

int main()
{
    std::int32_t a, b, h, m;
    std::cin >> a >> b >> h >> m;

    auto tmp = (2 * M_PI) / 12.0;
    std::double_t hRad = tmp * h + (tmp / 60.0) * m;
    std::double_t mRad = (2 * M_PI) / 60.0 * m;

    alg::Point<std::double_t> p1 = {a * std::sin(hRad), a * std::cos(hRad)};
    alg::Point<std::double_t> p2 = {b * std::sin(mRad), b * std::cos(mRad)};

    std::cout << std::fixed << std::setprecision(28) << alg::FindLength(p1, p2) << std::endl;

    return 0;
}