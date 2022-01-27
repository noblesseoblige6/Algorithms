#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

namespace alg
{
    struct Point
    {
        std::int32_t x;
        std::int32_t y;
    };

    std::double_t FindNearestDistanceBF(std::vector<Point> const& ps)
    {
        std::double_t dis = 0;
        for(std::size_t i = 0; i < ps.size(); ++i)
        {
            for (std::size_t j = 0; j < ps.size(); ++j)
            {
                if (i == j)
                    continue;

                auto x = ps[j].x - ps[i].x;
                auto y = ps[j].y - ps[i].y;
                dis = std::min(dis, std::sqrt(x * x + y * y));
            }
        }
        return dis;
    }

    std::double_t FindNearestDistance(std::vector<Point> const& ps, std::size_t s, std::size_t e)
    {
        if (e - s == 1)
        {
            auto x = ps[e].x - ps[s].x;
            auto y = ps[e].y - ps[s].y;
            return std::sqrt(x * x + y * y);
        }

        auto h = s + (e - s) / 2;
        return std::min(FindNearestDistance(ps, s, h), FindNearestDistance(ps, h, e));
    }

    std::double_t FindNearestDistanceDC(std::vector<Point> const& ps)
    {
        auto sorted_pos = ps;
        std::sort(sorted_pos.begin(), sorted_pos.end(), [](Point const &lhv, Point const &rhv){return lhv.x < rhv.x});

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

    std::cout << alg::FindNearestDistanceBF(ps) << std::endl;
    // std::cout << alg::FindNearestDistanceDC(ps) << std::endl;

    return 0;
}