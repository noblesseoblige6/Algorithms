namespace acLib
{
    namespace arithmetic
    {
        using namespace vec;

        template <typename T>
        segment<T>::segment() : segment<T>( vec2<T>::ZERO, vec2<T>::ZERO )
        {}

        template <typename T>
        segment<T>::segment( const vec2<T>& start, const vec2<T>& end )
            : m_start( start )
            , m_end( end )
        {}

        template <typename T>
        bool segment<T>::IntersectPoint( const vec2<T>& point ) const
        {
            //@comment point is on segment start point or end point
            if (m_start == point || m_end == point)
            {
                return true;
            }

            const vec2<T> a = m_end - m_start;
            const vec2<T> b = point - m_start;

            return a.norm() >= b.norm() && vec2<T>::cross( a, b ) == 0 && vec2<T>::dot( a, b ) > 0;
        }

        template <typename T>
        bool segment<T>::Intersect( const segment<T>& seg ) const
        {
            //@comment point on the segment
            if (IntersectPoint( seg.m_start ) || IntersectPoint( seg.m_end ))
            {
                return true;
            }
            else if (seg.IntersectPoint( m_start ) || seg.IntersectPoint( m_end ))
            {
                return true;
            }

            vec2<T> line1 = m_end - m_start, line2 = seg.m_end - seg.m_start;
            if ((vec2<T>::cross( line1, seg.m_start - m_start )*vec2<T>::cross( line1, seg.m_end - m_start ) < 0) &&
                (vec2<T>::cross( line2, m_start - seg.m_start )*vec2<T>::cross( line2, m_end - seg.m_start ) < 0))
            {
                return true;
            }

            return false;
        }

        template <typename T>
        vec2<T> segment<T>::CrossPoint( const segment<T>& seg ) const
        {
            const vec2<T> base = m_end - m_start;
            const vec2<T> cSeg = seg.m_end - seg.m_start;
            const vec2<T> s1 = m_start - seg.m_start;
            const vec2<T> s2 = m_end - seg.m_end;

            //@comment Find the height from base vector to p2 and p3
            //@comment To reduce error, dividing by norm is ommited
            // double d1 = abs(cross(cSeg, s1))/norm(base);
            // double d2 = abs(cross(cSeg, s2))/norm(base);
            T d1 = abs( vec2<T>::cross( cSeg, s1 ) );
            T d2 = abs( vec2<T>::cross( cSeg, s2 ) );

            //@comment Accroding to the ratio, t:(1-t) = d1:d2
            return  d1 + d2 == static_cast<T>(0) ? m_start : m_start + base * (d1 / (d1 + d2));
        }

        template segment<int>;
        template segment<double>;
        template segment<float>;
    }
}