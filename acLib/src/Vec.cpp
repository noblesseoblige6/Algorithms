namespace acLib
{
    using namespace util;

    namespace vec
    {
        template<typename T>
        vec2<T>::vec2() :x( 0 ), y( 0 )
        {
        }

        template<typename T>
        vec2<T>::vec2( T _v ) : x( _v ), y( _v )
        {
        }

        template<typename T>
        vec2<T>::vec2( T _x, T _y ) : x( _x ), y( _y )
        {
        }

        template<typename T>
        vec2<T>::vec2( const vec2<T>& vec ) : x( vec.x ), y( vec.y )
        {
        }

        template<typename T>
        vec2<T>::~vec2()
        {
        }

        template<typename T>
        vec2<T> vec2<T>::operator+( const vec2<T>& v ) const
        {
            vec2 res;
            res.x = x + v.x;
            res.y = y + v.y;
            return res;
        }

        template<typename T>
        vec2<T> vec2<T>::operator-( const vec2<T>& v ) const
        {
            vec2 res;
            res.x = x - v.x;
            res.y = y - v.y;
            return res;
        }
        template<typename T>
        vec2<T> vec2<T>::operator*( const T s )
        {
            vec2 res;
            res.x = x * s;
            res.y = y * s;
            return res;
        }
        template<typename T>
        vec2<T> vec2<T>::operator*( const vec2<T>& v ) const
        {
            vec2 res;
            res.x = x * v.x;
            res.y = y * v.y;
            return res;
        }
        template<typename T>
        vec2<T> vec2<T>::operator/( const T s )
        {
            vec2 res;
            res.x = x / s;
            res.y = y / s;

            return res;
        }
        template<typename T>
        const vec2<T>& vec2<T>::operator+=( const vec2<T>& v )
        {
            x += v.x;
            y += v.y;

            return *this;
        }
        template<typename T>
        const vec2<T>& vec2<T>::operator-=( const vec2<T>& v )
        {
            x -= v.x;
            y -= v.y;

            return *this;
        }
        template<typename T>
        const vec2<T>& vec2<T>::operator*=( const vec2<T>& v )
        {
            x *= v.x;
            y *= v.y;

            return *this;
        }
        template<typename T>
        const vec2<T>& vec2<T>::operator*=( const T s )
        {
            x *= s;
            y *= s;

            return *this;
        }
        template<typename T>
        const vec2<T>& vec2<T>::operator/=( const T s )
        {
            x /= s;
            y /= s;

            return *this;
        }
        template<typename T>
        bool vec2<T>::operator==( const vec2<T>& v ) const
        {
            return (x == v.x && y == v.y);
        }
        template<typename T>
        bool vec2<T>::operator!=( const vec2<T>& v ) const
        {
            return !(*this == v);
        }
        template<typename T>
        bool vec2<T>::operator<( const vec2<T>& v ) const
        {
            if (y == v.y)
                return x < v.x;
            return y < v.y;
        }

        template<typename T>
        bool vec2<T>::operator<=( const vec2<T>& v ) const
        {
            return y <= v.y;
        }

        template<typename T>
        vec2<T> vec2<T>::operator-() const
        {
            vec2<T> res( *this );
            res *= -1;
            return res;
        }

        template<typename T>
        T vec2<T>::norm() const
        {
            return (T)sqrt( x*x + y * y );
        }

        template<typename T>
        const vec2<T>& vec2<T>::normalized()
        {
            *this /= (T)this->norm();
            return *this;
        }

        template<typename T>
        const vec2<T> vec2<T>::ZERO = vec2( static_cast<T>(0), static_cast<T>(0) );

        template<typename T>
        const vec2<T> vec2<T>::ONE = vec2( static_cast<T>(1), static_cast<T>(1) );

        template<typename T>
        const vec2<T> vec2<T>::XAXIS = vec2( static_cast<T>(1), static_cast<T>(0) );

        template<typename T>
        const vec2<T> vec2<T>::YAXIS = vec2( static_cast<T>(0), static_cast<T>(1) );

        template vec2<int>;
        template vec2<float>;
        template vec2<double>;

        template<typename T>
        vec3<T>::vec3() :x( 0 ), y( 0 ), z( 0 ) {}

        template<typename T>
        vec3<T>::vec3( T _v ) : x( _v ), y( _v ), z( _v )
        {
        }

        template<typename T>
        vec3<T>::vec3( T _x, T _y, T _z ) : x( _x ), y( _y ), z( _z )
        {
        }

        template<typename T>
        vec3<T>::vec3( const vec3<T>& vec ) : x( vec.x ), y( vec.y ), z( vec.z )
        {
        }

        template<typename T>
        vec3<T>::~vec3()
        {
        }

        template<typename T>
        vec3<T>vec3<T>::operator+( const vec3<T>& v ) const
        {
            vec3 res;
            res.x = x + v.x;
            res.y = y + v.y;
            res.z = z + v.z;
            return res;
        }

        template<typename T>
        vec3<T>vec3<T>::operator-( const vec3<T>& v ) const
        {
            vec3 res;
            res.x = x - v.x;
            res.y = y - v.y;
            res.z = z - v.z;
            return res;
        }

        template<typename T>
        vec3<T>vec3<T>::operator*( const T s ) const
        {
            vec3 res;
            res.x = x * s;
            res.y = y * s;
            res.z = z * s;
            return res;
        }

        template<typename T>
        vec3<T>vec3<T>::operator*( const vec3<T>& v ) const
        {
            vec3 res;
            res.x = x * v.x;
            res.y = y * v.y;
            res.z = z * v.z;
            return res;
        }

        template<typename T>
        vec3<T>vec3<T>::operator/( const T s ) const
        {
            vec3 res;
            res.x = x / s;
            res.y = y / s;
            res.z = z / s;

            return res;
        }

        template<typename T>
        const vec3<T>& vec3<T>::operator+=( const vec3<T>& v )
        {
            x += v.x;
            y += v.y;
            z += v.z;

            return *this;
        }

        template<typename T>
        const vec3<T>& vec3<T>::operator-=( const vec3<T>& v )
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;

            return *this;
        }

        template<typename T>
        const vec3<T>& vec3<T>::operator*=( const vec3<T>& v )
        {
            x *= v.x;
            y *= v.y;
            z *= v.z;

            return *this;
        }

        template<typename T>
        const vec3<T>& vec3<T>::operator*=( const T s )
        {
            x *= s;
            y *= s;
            z *= s;

            return *this;
        }

        template<typename T>
        const vec3<T>& vec3<T>::operator/=( const T s )
        {
            x /= s;
            y /= s;
            z /= s;

            return *this;
        }

        template<typename T>
        bool vec3<T>::operator==( const vec3<T>& v ) const
        {
            return (x == v.x && y == v.y && z == v.z);
        }

        template<typename T>
        bool vec3<T>::operator!=( const vec3<T>& v ) const
        {
            return !(*this == v);
        }

        template<typename T>
        bool vec3<T>::operator<( const vec3<T>& v ) const
        {
            if (y == v.y)
                return x < v.x;
            return y < v.y;
        }
        template<typename T>
        bool vec3<T>::operator<=( const vec3<T>& v ) const
        {
            return y <= v.y;
        }

        template<typename T>
        vec3<T> vec3<T>::operator-() const
        {
            vec3<T> res( *this );
            res *= static_cast<T>(-1.0);
            return res;
        }

        template<typename T>
        T vec3<T>::norm() const
        {
            return (T)sqrt( normSq() );
        }

        template<typename T>
        T vec3<T>::normSq() const
        {
            return x * x + y * y + z * z;
        }

        template<typename T>
        const vec3<T>& vec3<T>::normalized()
        {
            T deno = (T)this->norm();
            if (deno == (T)0)
            {
                Log::Output( Log::LOG_LEVEL_ERROR, "Zero division!" );
                return *this;
            }

            *this /= deno;
            return *this;
        }

        /*template<typename T>
        const vec3<T>& vec3<T>::transform( const Mat33& mat )
        {
            *this = vec3( vec3<T>::dot( mat.GetRow( 0 ), *this ), vec3<T>::dot( mat.GetRow( 1 ), *this ), vec3<T>::dot( mat.GetRow( 2 ), *this ) );
            return *this;
        }*/

        template<typename T>
        T vec3<T>::operator[]( const int& idx ) const
        {
            if (idx == VEC_INDEX::X)
            {
                return x;
            }
            else if (idx == VEC_INDEX::Y)
            {
                return y;
            }
            else if (idx == VEC_INDEX::Z)
            {
                return z;
            }

            cerr << "vec3 Out of bounds:" << idx << endl;
            return x;
        }

        template<typename T>
        const vec3<T> vec3<T>::ZERO = vec3( static_cast<T>(0), static_cast<T>(0), static_cast<T>(0) );

        template<typename T>
        const vec3<T> vec3<T>::ONE = vec3( static_cast<T>(1), static_cast<T>(1), static_cast<T>(1) );

        template<typename T>
        const vec3<T> vec3<T>::XAXIS = vec3( static_cast<T>(1), static_cast<T>(0), static_cast<T>(0) );

        template<typename T>
        const vec3<T> vec3<T>::YAXIS = vec3( static_cast<T>(0), static_cast<T>(1), static_cast<T>(0) );

        template<typename T>
        const vec3<T> vec3<T>::ZAXIS = vec3( static_cast<T>(0), static_cast<T>(0), static_cast<T>(1) );

        template vec3<int>;
        template vec3<float>;
        template vec3<double>;

        template<typename T>
        vec4<T>::vec4()
        {
            *this = vec4<T>::ZERO;
        }

        template<typename T>
        vec4<T>::vec4( T _v ) : x( _v ), y( _v ), z( _v ), w( _v )
        {
        }

        template<typename T>
        vec4<T>::vec4( T _x, T _y, T _z, T _w ) : x( _x ), y( _y ), z( _z ), w( _w )
        {
        }

        template<typename T>
        vec4<T>::vec4( const vec4<T>& vec )
        {
            *this = vec;
        }

        template<typename T>
        vec4<T>::vec4( const vec3<T>& vec, T _w )
        {
            x = vec.x;
            y = vec.y;
            z = vec.z;
            w = _w;
        }

        template<typename T>
        vec4<T>::~vec4()
        {
        }

        template<typename T>
        vec4<T> vec4<T>::operator+( const vec4<T>& v ) const
        {
            vec4 res;
            res.x = x + v.x;
            res.y = y + v.y;
            res.z = z + v.z;
            res.w = w + v.w;

            return res;
        }

        template<typename T>
        vec4<T> vec4<T>::operator-( const vec4<T>& v ) const
        {
            vec4 res;
            res.x = x - v.x;
            res.y = y - v.y;
            res.z = z - v.z;
            res.w = w - v.w;

            return res;
        }

        template<typename T>
        vec4<T> vec4<T>::operator*( const T s ) const
        {
            vec4 res;
            res.x = x * s;
            res.y = y * s;
            res.z = z * s;
            res.w = w * s;

            return res;
        }

        template<typename T>
        vec4<T> vec4<T>::operator*( const vec4<T>& v ) const
        {
            vec4 res;
            res.x = x * v.x;
            res.y = y * v.y;
            res.z = z * v.z;
            return res;
        }

        template<typename T>
        vec4<T> vec4<T>::operator/( const T s ) const
        {
            vec4 res;
            res.x = x / s;
            res.y = y / s;
            res.z = z / s;
            res.w = w / s;

            return res;
        }

        template<typename T>
        const vec4<T>& vec4<T>::operator+=( const vec4<T>& v )
        {
            x += v.x;
            y += v.y;
            z += v.z;
            w += v.w;

            return *this;
        }

        template<typename T>
        const vec4<T>& vec4<T>::operator-=( const vec4<T>& v )
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            w -= v.w;

            return *this;
        }

        template<typename T>
        const vec4<T>& vec4<T>::operator*=( const vec4<T>& v )
        {
            x *= v.x;
            y *= v.y;
            z *= v.z;
            w *= v.w;

            return *this;
        }

        template<typename T>
        const vec4<T>& vec4<T>::operator*=( const T s )
        {
            x *= s;
            y *= s;
            z *= s;
            w *= s;

            return *this;
        }

        template<typename T>
        const vec4<T>& vec4<T>::operator/=( const T s )
        {
            x /= s;
            y /= s;
            z /= s;
            w /= s;

            return *this;
        }

        template<typename T>
        bool vec4<T>::operator==( const vec4<T>& v ) const
        {
            return (x == v.x && y == v.y && z == v.z);
        }

        template<typename T>
        bool vec4<T>::operator!=( const vec4<T>& v ) const
        {
            return !(*this == v);
        }

        template<typename T>
        bool vec4<T>::operator<( const vec4<T>& v ) const
        {
            if (y == v.y)
                return x < v.x;
            return y < v.y;
        }
        template<typename T>
        bool vec4<T>::operator<=( const vec4<T>& v ) const
        {
            return y <= v.y;
        }

        template<typename T>
        vec4<T> vec4<T>::operator-() const
        {
            vec4<T> res( *this );
            res *= -1;
            return res;
        }

        template<typename T>
        T vec4<T>::norm() const
        {
            return (T)sqrt( normSq() );
        }

        template<typename T>
        T vec4<T>::normSq() const
        {
            return x * x + y * y + z * z;
        }

        template<typename T>
        const vec4<T>& vec4<T>::normalized()
        {
            *this /= (T)this->norm();
            return *this;
        }

        template<typename T>
        T vec4<T>::operator[]( const int& idx ) const
        {
            if (idx == VEC_INDEX::X)
            {
                return x;
            }
            else if (idx == VEC_INDEX::Y)
            {
                return y;
            }
            else if (idx == VEC_INDEX::Z)
            {
                return z;
            }
            else if (idx == VEC_INDEX::W)
            {
                return w;
            }
            cerr << "vec4 Out of bounds:" << idx << endl;

            return x;
        }

        template <typename T>
        const vec4<T> vec4<T>::ZERO = vec4( static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0) );

        template<typename T>
        const vec4<T> vec4<T>::ONE = vec4( static_cast<T>(1), static_cast<T>(1), static_cast<T>(1), static_cast<T>(1) );

        template<typename T>
        const vec4<T> vec4<T>::XAXIS = vec4( static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1) );

        template<typename T>
        const vec4<T> vec4<T>::YAXIS = vec4( static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(1) );

        template<typename T>
        const vec4<T> vec4<T>::ZAXIS = vec4( static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(1) );

        template vec4<int>;
        template vec4<float>;
        template vec4<double>;
    }
}