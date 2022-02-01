#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>

namespace alg
{
    struct Point
    {
        std::int64_t x;
        std::int64_t y;
    };

    std::double_t FindLength(Point const &s, Point const &e)
    {
        auto const x = static_cast<std::double_t>(e.x - s.x);
        auto const y = static_cast<std::double_t>(e.y - s.y);

        return std::sqrt(x * x + y * y);
    }

    std::uint32_t FindCircles(Point const &p1, std::int32_t r1, Point const& p2, std::int32_t r2)
    {
        auto const d = FindLength(p1, p2);
        if (d < std::abs(r2 - r1))
            return 1;
        else if (d == std::abs(r2 - r1))
            return 2;
        else if (std::abs(r2 - r1) < d)
            return 3;
        else if (d == r1 + r2)
            return 4;
        else // d > r1 + r2
            return 5;
    }
}

int main()
{
    alg::Point p1, p2;
    std::int32_t r1, r2;
    std::cin >> p1.x >> p1.y >> r1;
    std::cin >> p2.x >> p2.y >> r2;

    auto res = alg::FindCircles(p1, r1, p2, r2);
    std::cout << res << std::endl;

    return 0;
}