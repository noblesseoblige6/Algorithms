namespace acLib
{
    namespace quat
    {
        template<typename T>
        Quat<T>::Quat()
            : t( 0 )
            , v( vec3<T>( 0 ) )
        {
        }

        template<typename T>
        Quat<T>::Quat( T _t, vec3<T> _v ) : t( cos( _t*0.5f ) ), v( vec3<T>(_v.x * sin(_t*0.5f), _v.y * sin( _t*0.5f ) , _v.z * sin( _t*0.5f )))
        {
        }

        template<typename T>
        Quat<T>::Quat( T _t, T _x, T _y, T _z ) : t( cos( _t*0.5f ) ), v( vec3<T>( _x * sin( _t*0.5f ), _y * sin( _t*0.5f ), _z * sin( _t*0.5f )))
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
        T Quat<T>::Norm() const
        {
            return sqrt( NormSq() );
        }

        template<typename T>
        T Quat<T>::NormSq() const
        {
            return MulConjugate( *this );
        }

        template<typename T>
        Quat<T> Quat<T>::Inverse() const
        {
            Quat<T> res;
            res = Conjugate() / NormSq();
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

        template<typename T>
        void Quat<T>::Rotate( vec3<T>& point )
        {
            Quat<T> res;

            Quat<T> q;
            q.t = 0;
            q.v = point;

            res = Conjugate() * q * (*this);

            point = res.v;
        }

        template<typename T>
        mat33<T> Quat<T>::GetRotationMatrix() const
        {
            T xSq = v.x*v.x;
            T ySq = v.y*v.y;
            T zSq = v.z*v.z;

            mat33<T> mat = mat33<T>( vec3<T>( 1 - 2*ySq - 2*zSq    , 2*v.x*v.y + 2*t*v.z , 2 * v.x*v.z - 2*t*v.y ),
                                     vec3<T>( 2*v.x*v.y - 2*t*v.z, 1 - 2*xSq - 2*zSq   , 2 * v.y*v.z + 2*t*v.x ),
                                     vec3<T>( 2*v.x*v.z + 2*t*v.y  , 2*v.y*v.z - 2*t*v.x , 1 - 2*xSq - 2*ySq ));
            return mat;
        }

        const Quat<float> Quat<float>::ZERO = Quat( static_cast<float>(kPI), 0.0f );
        const Quat<double> Quat<double>::ZERO = Quat( kPI, 0.0 );

        template Quat<float>;
        template Quat<double>;
    }
}