#pragma once

namespace acLib
{
    namespace quat
    {
        using namespace std;

        template<class T>
        struct Quat
        {
        public:
            static const Quat ZERO;

            Quat();
            Quat(T _t, vec3<T> _v);
            Quat(T _t, T _x, T _y, T _z);
            Quat(const Quat& quat);
            ~Quat();

            Quat operator+(const Quat& v) const;
            Quat operator-(const Quat& v) const;
            Quat operator*( const Quat& v ) const;
            Quat operator*( const T s ) const;
            Quat operator/(const T s) const;

            const Quat& operator+=(const Quat& v);
            const Quat& operator-=(const Quat& v);
            const Quat& operator*=( const Quat& v );
            const Quat& operator*=( const T s );
            const Quat& operator/=(const T s);

            bool operator==(const Quat& v) const;
            bool operator!=(const Quat& v) const;

            Quat operator-() const;

            T norm() const;
            T normSq() const;

            Quat Inverse() const;
            const Quat& Inversed();

            Quat Conjugate() const;
            const Quat& Conjugated();
            T MulConjugate( const Quat& q ) const;

            friend Quat operator* ( const T s, const Quat& q )
            {
                Quat res( q );
                res = res * s;
                return res;
            }

            friend Quat operator/ ( const T s, const Quat& q )
            {
                Quat res( q );
                res = res / s;
                return res;
            }

            friend ostream& operator<<(ostream& os, const Quat& q)
            {
                os << q.t << " " << q.v;
                return os;
            }

        public:
            T       t;
            vec3<T> v;
        };
    }
}

typedef acLib::quat::Quat<float>  Quatf;
typedef acLib::quat::Quat<double> Quatd;