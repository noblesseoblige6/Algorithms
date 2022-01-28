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

    std::double_t FindNearestDistanceBF(std::vector<Point> const& ps)
    {
        auto dis = std::numeric_limits<std::double_t>::max();
        for(std::size_t i = 0; i < ps.size(); ++i)
            for (std::size_t j = i+1; j < ps.size(); ++j)
                dis = (i == j) ? dis : std::min(dis, FindLength(ps[i], ps[j]));

        return dis;
    }

    std::double_t FindNearestDistance(std::vector<Point> const& ps, std::size_t s, std::size_t e)
    {
        if (e - s == 1)
            return FindLength(ps[s], ps[e]);

        auto h = s + (e - s) / 2;
        return std::min(std::min(FindNearestDistance(ps, s, h), FindNearestDistance(ps, h, e)), FindLength(ps[s], ps[e]));
    }

    std::double_t FindNearestDistanceDC(std::vector<Point> const& ps)
    {
        auto sorted_pos = ps;
        std::sort(sorted_pos.begin(), sorted_pos.end(), [](Point const &lhv, Point const &rhv){ return lhv.x < rhv.x; });

        return FindNearestDistance(sorted_pos, 0, sorted_pos.size()-1);
    }
}

int main()
{
    std::uint32_t n;
    std::cin >> n;

    std::vector<alg::Point> ps(n);
    for (decltype(n) i = 0; i < n; ++i)
        std::cin >> ps[i].x >> ps[i].y;

    auto res = alg::FindNearestDistanceBF(ps);
    // auto res = alg::FindNearestDistanceDC(ps);
    std::cout << std::fixed << std::setprecision(28) << res << std::endl;

    return 0;
}