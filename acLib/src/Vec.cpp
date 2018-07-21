namespace acLib
{
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
        double vec2<T>::norm() const
        {
            return (double)sqrt( x*x + y * y );
        }

        template<typename T>
        const vec2<T>& vec2<T>::normalized()
        {
            *this /= (T)this->norm();
            return *this;
        }

        const vec2<int> vec2<int>::ZERO = vec2( 0, 0 );
        const vec2<float> vec2<float>::ZERO = vec2( 0.0f, 0.0f );
        const vec2<double> vec2<double>::ZERO = vec2( 0.0, 0.0 );

        const vec2<int> vec2<int>::ONE = vec2( 1, 1 );
        const vec2<float> vec2<float>::ONE = vec2( 1.0f, 1.0f);
        const vec2<double> vec2<double>::ONE = vec2( 1.0, 1.0 );

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
        double vec3<T>::norm() const
        {
            return (double)sqrt( normSq() );
        }

        template<typename T>
        T vec3<T>::normSq() const
        {
            return x * x + y * y + z * z;
        }

        template<typename T>
        const vec3<T>& vec3<T>::normalized()
        {
            *this /= (T)this->norm();
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

        vec3<int> vec3<int>::ZERO = vec3( 0, 0, 0 );
        vec3<float> vec3<float>::ZERO = vec3( 0.0f, 0.0f, 0.0f );
        vec3<double> vec3<double>::ZERO = vec3( 0.0, 0.0, 0.0 );

        vec3<int> vec3<int>::ONE = vec3( 1, 1, 1);
        vec3<float> vec3<float>::ONE = vec3( 1.0f, 1.0f, 1.0f );
        vec3<double> vec3<double>::ONE = vec3( 1.0, 1.0, 1.0 );

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
        double vec4<T>::norm() const
        {
            return (double)sqrt( normSq() );
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

        vec4<int> vec4<int>::ZERO = vec4( 0, 0, 0, 0 );
        template<typename T>
        vec4<T> vec4<T>::ZERO = vec4( 0.0, 0.0, 0.0, 0.0 );

        vec4<int> vec4<int>::ONE = vec4( 1, 1, 1, 1 );
        template<typename T>
        vec4<T> vec4<T>::ONE = vec4( 1.0, 1.0, 1.0, 1.0 );

        template vec4<int>;
        template vec4<float>;
        template vec4<double>;
    }
}