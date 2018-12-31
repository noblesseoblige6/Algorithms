namespace acLib
{
    using namespace vec;

    namespace quat
    {
        template<typename T>
        Quat<T>::Quat()
            : t( 0 )
            , v( vec3<T>( 0 ) )
        {
        }

        template<typename T>
        Quat<T>::Quat( T _t, vec3<T> _v ) : t( _t ), v( _v )
        {
        }

        template<typename T>
        Quat<T>::Quat( T _t, T _x, T _y, T _z ) : t( _t ), v( vec3<T>( _x, _y, _z ) )
        {
        }

        template<typename T>
        Quat<T>::Quat( const Quat<T>& q ) : t( q.t ), v( q.v )
        {
        }

        template<typename T>
        Quat<T>::~Quat()
        {
        }

        template<typename T>
        Quat<T> Quat<T>::operator+( const Quat<T>& q ) const
        {
            Quat res;
            res.t = t + q.t;
            res.v = v + q.v;
            return res;
        }

        template<typename T>
        Quat<T> Quat<T>::operator-( const Quat<T>& q ) const
        {
            Quat res;
            res.t = t - q.t;
            res.v = v - q.v;
            return res;
        }

        template<typename T>
        Quat<T> Quat<T>::operator*( const Quat<T>& q ) const
        {
            Quat res;
            res.t = t * q.t - vec3<T>::dot( v, q.v );
            res.v = t * q.v + q.t*v + vec3<T>::cross( v, q.v );
            return res;
        }

        template<typename T>
        Quat<T> Quat<T>::operator*( const T s ) const
        {
            Quat<T> res;
            res.t = t * s;
            res.v = v * s;
            return res;
        }

        template<typename T>
        Quat<T> Quat<T>::operator/( const T s ) const
        {
            Quat<T> res;
            res.t = t / s;
            res.v = v / s;
            return res;
        }

        template<typename T>
        const Quat<T>& Quat<T>::operator+=( const Quat<T>& q )
        {
            t += q.t;
            v += q.v;

            return *this;
        }

        template<typename T>
        const Quat<T>& Quat<T>::operator-=( const Quat<T>& q )
        {
            t -= q.t;
            v -= q.v;

            return *this;
        }

        template<typename T>
        const Quat<T>& Quat<T>::operator*=( const Quat<T>& q )
        {
            t *= q.t;
            v *= q.v;
            return *this;
        }

        template<typename T>
        const Quat<T>& Quat<T>::operator*=( const T s )
        {
            t *= s;
            v *= s;
            return *this;
        }

        template<typename T>
        const Quat<T>& Quat<T>::operator/=( const T s )
        {
            t /= s;
            v /= s;
            return *this;
        }

        template<typename T>
        bool Quat<T>::operator==( const Quat<T>& q ) const
        {
            return (t == q.t && v == q.v);
        }

        template<typename T>
        bool Quat<T>::operator!=( const Quat<T>& q ) const
        {
            return !(*this == q);
        }

        template<typename T>
        Quat<T> Quat<T>::operator-() const
        {
            Quat<T> res( *this );
            res *= -1;
            return res;
        }

        template<typename T>
        T Quat<T>::norm() const
        {
            return sqrt( normSq() );
        }

        template<typename T>
        T Quat<T>::normSq() const
        {
            return MulConjugate( *this );
        }

        template<typename T>
        Quat<T> Quat<T>::Inverse() const
        {
            Quat<T> res;
            res = Conjugate() / normSq();
            return res;
        }

        template<typename T>
        const Quat<T>& Quat<T>::Inversed()
        {
            *this = Inverse();
            return *this;
        }

        template<typename T>
        Quat<T> Quat<T>::Conjugate() const
        {
            Quat<T> res;
            res.t = t;
            res.v = -v;
            return res;
        }

        template<typename T>
        const Quat<T>& Quat<T>::Conjugated()
        {
            *this = Conjugate();
            return *this;
        }

        template<typename T>
        T Quat<T>::MulConjugate( const Quat& q ) const
        {
           return t*q.t + v.x*q.v.x + v.x*q.v.x + v.y*q.v.y + v.z*q.v.z;
        }

        const Quat<float> Quat<float>::ZERO = Quat( 0.0f, 0.0f );
        const Quat<double> Quat<double>::ZERO = Quat( 0.0, 0.0 );

        template Quat<float>;
        template Quat<double>;
    }
}