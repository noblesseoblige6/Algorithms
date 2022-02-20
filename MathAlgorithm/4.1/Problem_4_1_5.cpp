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
    bool IsIntersect(Segment<T> const& s1, Segment<T> const& s2)
    {
        if ((s1.s == s2.s || s1.s == s2.e) ||
            (s1.e == s2.s || s1.e == s2.e))
            return true;

        auto v1 = s1.e - s1.s;
        auto v2 = s2.e - s2.s;

        auto v1_1 = s2.s - s1.s;
        auto v1_2 = s2.e - s1.s;

        auto v2_1 = s1.s - s2.s;
        auto v2_2 = s1.e - s2.s;

        auto isOnLine = [](auto const &a, auto const &b)
        {
            if (1-Dot(Normalize(a), Normalize(b)) < 1e-9)
            {
                if (Length(b) <= Length(a))
                    return true;
            }
            return false;
        };

        if (isOnLine(v1, v1_1))
            return true;

        if (isOnLine(v1, v1_2))
            return true;

        auto isSeparated = [](auto const &a, auto const &b)
        {
            if (a < 0.0 && b > 0.0)
                return true;
            if (a > 0.0 && b < 0.0)
                return true;

            return false;
        };

        if(isSeparated(Cross(v1, v1_1), Cross(v1, v1_2)) &&
           isSeparated(Cross(v2, v2_1), Cross(v2, v2_2)))
            return true;

        return false;
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