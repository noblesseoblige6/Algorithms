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
    bool operator==(Point<T> const &a, Point<T> const &b)
    {
        return (a.x == b.x && a.y == b.y);
    }

    template <typename T>
    Point<T> operator-(Point<T> const &a, Point<T> const &b)
    {
        return {a.x - b.x, a.y - b.y};
    }

    template <typename T>
    bool operator<(Point<T> const &a, Point<T> const &b)
    {
        return (a.x == b.x) ? a.y < b.y : a.x < b.y;
    }

    template <typename T>
    bool operator>(Point<T> const &a, Point<T> const &b)
    {
        return (a.x == b.x) ? a.y > b.y : a.x > b.y;
    }

    template <typename T>
    bool operator<=(Point<T> const &a, Point<T> const &b)
    {
        return (a.x == b.x) ? a.y <= b.y : a.x <= b.y;
    }

    template <typename T>
    bool operator>=(Point<T> const &a, Point<T> const &b)
    {
        return (a.x == b.x) ? a.y >= b.y : a.x >= b.y;
    }

    template <typename T>
    T Length(Point<T> const &a)
    {
        return std::sqrt(a.x * a.x + a.y * a.y);
    }

    template <typename T>
    Point<std::double_t> Normalize(Point<T> const &a)
    {
        auto l = static_cast<std::double_t>(Length(a));
        return {a.x/l, a.y/l};
    }

    template <typename T>
    T Dot(Point<T> const &a, Point<T> const &b)
    {
        return a.x * b.x + a.y * b.y;
    }

    template <typename T>
    T Cross(Point<T> const &a, Point<T> const &b)
    {
        return a.x * b.y - a.y * b.x;
    }

    template <typename T>
    struct Segment
    {
        Point<T> s;
        Point<T> e;
    };


    template <typename T>
    std::double_t Length(Point<T> const &s, Point<T> const &e)
    {
        auto const x = static_cast<std::double_t>(e.x - s.x);
        auto const y = static_cast<std::double_t>(e.y - s.y);

        return std::sqrt(x * x + y * y);
    }

    template <typename T>
    bool IsLineAligned(Segment<T> const& s1, Segment<T> const& s2)
    {
        auto a = s1.s;
        auto b = s1.e;
        auto c = s2.s;
        auto d = s2.e;

        if (a > b)
            std::swap(a, b);
        if (c > d)
            std::swap(c, d);

        return std::max(a, c) <= std::min(b, d);
    }

    template <typename T>
    bool IsIntersect(Segment<T> const& s1, Segment<T> const& s2)
    {
        auto v1 = s1.e - s1.s;
        auto v2 = s2.e - s2.s;

        auto v1_1 = s2.s - s1.s;
        auto v1_2 = s2.e - s1.s;

        auto v2_1 = s1.s - s2.s;
        auto v2_2 = s1.e - s2.s;

        auto a = Cross(v1, v1_1);
        auto b = Cross(v1, v1_2);
        auto c = Cross(v2, v2_1);
        auto d = Cross(v2, v2_2);

        if(a == 0 && b == 0 && c == 0 && d == 0)
            return IsLineAligned(s1, s2);

        auto isSeparated = [](auto const &a, auto const &b)
        {
            if (a <= 0.0 && b >= 0.0)
                return true;
            if (a >= 0.0 && b <= 0.0)
                return true;

            return false;
        };

        return isSeparated(a, b) &&
               isSeparated(c, d);
    }
}

int main()
{
    alg::Point<std::double_t> p1, p2, p3, p4;
    std::cin >> p1.x >> p1.y;
    std::cin >> p2.x >> p2.y;
    std::cin >> p3.x >> p3.y;
    std::cin >> p4.x >> p4.y;

    alg::Segment<std::double_t> s1 = {p1, p2};
    alg::Segment<std::double_t> s2 = {p3, p4};


    std::cout << (alg::IsIntersect(s1, s2) ? "Yes" : "No") << std::endl;

    return 0;
}