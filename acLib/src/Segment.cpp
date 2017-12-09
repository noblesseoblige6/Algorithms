#include "Segment.h"

using namespace acLib::segment;

Segment::Segment()
    : Segment(Vec2::ZERO, Vec2::ZERO)
{}

Segment::Segment(const Vec2& start, const Vec2& end)
    : m_start(start)
    , m_end(end)
{}

bool Segment::IntersectPoint(const Vec2& point) const
{
    //@comment point is on segment start point or end point
    if (m_start == point || m_end == point)
    {
        return true;
    }

    const Vec2 a = m_end - m_start;
    const Vec2 b = point - m_start;

    return a.norm() >= b.norm() && Vec2::cross(a, b) == 0 && Vec2::dot(a, b) > 0;
}

bool Segment::Intersect(const Segment& seg) const
{
    //@comment point on the segment
    if (IntersectPoint(seg.m_start) || IntersectPoint(seg.m_end))
    {
        return true;
    }
    else if (seg.IntersectPoint(m_start) || seg.IntersectPoint(m_end))
    {
        return true;
    }

    Vec2 line1 = m_end - m_start, line2 = seg.m_end - seg.m_start;
    if ((Vec2::cross(line1, seg.m_start - m_start)*Vec2::cross(line1, seg.m_end - m_start) < 0) &&
        (Vec2::cross(line2, m_start - seg.m_start)*Vec2::cross(line2, m_end - seg.m_start) < 0))
    {
        return true;
    }

    return false;
}

Vec2 Segment::CrossPoint(const Segment& seg) const
{
    const Vec2 base = m_end - m_start;
    const Vec2 cSeg = seg.m_end - seg.m_start;
    const Vec2 s1 = m_start - seg.m_start;
    const Vec2 s2 = m_end - seg.m_end;

    //@comment Find the height from base vector to p2 and p3
    //@comment To reduce error, dividing by norm is ommited
    // double d1 = abs(cross(cSeg, s1))/norm(base);
    // double d2 = abs(cross(cSeg, s2))/norm(base);
    double d1 = abs(Vec2::cross(cSeg, s1));
    double d2 = abs(Vec2::cross(cSeg, s2));

    //@comment Accroding to the ratio, t:(1-t) = d1:d2
    return  d1 + d2 == 0 ? m_start : m_start + base * (d1 / (d1 + d2));
}

bool Segment::IntersectPoint(const Segment& seg, const Vec2& point)
{
    return seg.IntersectPoint(point);
}

bool Segment::Intersect(const Segment& seg1, const Segment& seg2)
{
    return seg1.Intersect(seg2);
}

Vec2 Segment::CrossPoint(const Segment& seg1, const Segment& seg2)
{
    return seg1.CrossPoint(seg2);
}