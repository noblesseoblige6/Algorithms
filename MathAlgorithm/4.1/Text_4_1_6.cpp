#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <vector>

namespace alg
{
    struct Vec2
    {
        std::int64_t x = 0;
        std::int64_t y = 0;
    };

    Vec2 operator-(Vec2 const &a, Vec2 const &b)
    {
        return {a.x - b.x, a.y - b.y};
    }

    std::double_t Length(Vec2 const& a)
    {
        return std::sqrt(a.x * a.x + a.y * a.y);
    }

    std::double_t Dot(Vec2 const& a, Vec2 const& b)
    {
        return a.x * b.x + a.y * b.y;
    }
}

int main()
{
    alg::Vec2 a, b, c;
    std::cin >> a.x >> a.y;
    std::cin >> b.x >> b.y;
    std::cin >> c.x >> c.y;

    std::double_t res = 0;
    auto ab = a-b;
    auto ac = a-c;
    auto cb = c-b;
    auto bc = b-c;
    if(alg::Dot(ab, cb) < 0)
    {
        res = alg::Length(ab);
    }
    else if (alg::Dot(ac, bc) < 0)
    {
        res = alg::Length(ac);
    }
    else
    {
        res = std::fabs(ab.x * cb.y - ab.y * cb.x) / alg::Length(cb);
    }

    std::cout << std::fixed << std::setprecision(12) << res << std::endl;

    return 0;
}