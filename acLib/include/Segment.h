#pragma once
#include "Vec.h"

namespace acLib
{
    namespace segment
    {
        using namespace acLib::vec;

        struct Segment
        {
        public:
            Segment();
            Segment(const Vec2& start, const Vec2& end);

            bool IntersectPoint(const Vec2& point) const;
            bool Intersect(const Segment& seg) const;
            Vec2 CrossPoint(const Segment& seg) const;

            static bool IntersectPoint(const Segment& seg, const Vec2& point);
            static bool Intersect(const Segment& seg1, const Segment& seg2);
            static Vec2 CrossPoint(const Segment& seg1, const Segment& seg2);

        public:
            Vec2 m_start;
            Vec2 m_end;
        };
    }
}
