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

    std::array<std::double_t, 12> hours;
    for (auto i = 0; i < 12; ++i)
    {
        constexpr auto pi = -(2 * M_PI) / 12.0;
        hours[(i + 3) % 12] = i * pi;
    }

    std::array<std::double_t, 60> mins;
    for (auto i = 0; i < 60; ++i)
    {
        constexpr auto pi = -(2 * M_PI) / 60.0;
        mins[(i + 15) % 60] = i * pi;
    }

    alg::Point<std::double_t> p1 = {a * std::cos(hours[h]), a * std::sin(hours[h])};
    alg::Point<std::double_t> p2 = {b * std::cos(mins[m]), b * std::sin(mins[m])};

    std::cout << alg::FindLength(p1, p2) << std::endl;

    return 0;
}