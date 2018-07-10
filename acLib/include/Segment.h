#pragma once

namespace acLib
{
    using namespace vec;

    namespace seg
    {
        template <typename T>
        struct segment
        {
        public: // static
            static bool IntersectPoint( const segment<T>& seg,
                                        const vec2<T>& point ) 
            { return seg.IntersectPoint( point ); }

            static bool Intersect( const segment<T>& seg1,
                                   const segment<T>& seg2 )
            { return seg1.Intersect( seg2 ); }

            static vec2<T> CrossPoint( const segment<T>& seg1,
                                       const segment<T>& seg2 )
            { return seg1.CrossPoint( seg2 ); }

        public:
            segment();
            segment(const vec2<T>& start, const vec2<T>& end);
            
        public:
            bool IntersectPoint(const vec2<T>& point) const;
            bool Intersect(const segment<T>& seg) const;
            vec2<T> CrossPoint(const segment<T>& seg) const;

        public:
            vec2<T> m_start;
            vec2<T> m_end;
        };
    }
}

typedef acLib::seg::segment<double> Segment;