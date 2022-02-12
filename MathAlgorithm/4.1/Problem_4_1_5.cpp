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
        auto v1 = Normalize(s1.e - s1.s);

        auto v2 = Normalize(s2.s - s1.s);
        auto v3 = Normalize(s2.e - s1.s);

        if (std::fabs(1-std::fabs(Dot(v1, v2))) < 1e-9)
            return true;

        if (std::fabs(1 - std::fabs(Dot(v1, v3))) < 1e-9)
            return true;

        if(Cross(v1, v2) < 0 && Cross(v1, v3) < 0)
            return false;
        if(Cross(v1, v2) >= 0 && Cross(v1, v3) >= 0)
            return false;

        return true;
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