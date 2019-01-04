#pragma once

namespace acLib
{
    namespace vec
    {
        using namespace std;

        enum VEC_INDEX
        {
            X = 0,
            Y = 1,
            Z = 2,
            W = 3
        };

        template<typename T>
        struct vec2
        {
        public:
            static const vec2 ZERO;
            static const vec2 ONE;
            static const vec2 XAXIS;
            static const vec2 YAXIS;

            vec2();
            vec2(T _v);
            vec2(T _x, T _y);
            vec2(const vec2& vec);
            ~vec2();

            vec2 operator+(const vec2& v) const;
            vec2 operator-(const vec2& v) const;
            vec2 operator*(const T s);
            vec2 operator*(const vec2& v) const;
            vec2 operator/(const T s);

            const vec2& operator+=(const vec2& v);
            const vec2& operator-=(const vec2& v);
            const vec2& operator*=(const vec2& v);

            const vec2& operator*=(const T s);
            const vec2& operator/=(const T s);

            bool operator==(const vec2& v) const;
            bool operator!=(const vec2& v) const;
            bool operator<(const vec2& v) const;
            bool operator<=(const vec2& v) const;

            vec2 operator-() const;

            T norm() const;
            const vec2& normalized();

            friend vec2 operator+ (const T s, const vec2& v)
            {
                vec2 res(v);
                res = res + s;
                return res;
            }

            friend vec2 operator- (const T s, const vec2& v)
            {
                vec2 res(v);
                res = res - s;
                return res;
            }

            friend vec2 operator* (const T s, const vec2& v)
            {
                vec2 res(v);
                res = res*s;
                return res;
            }

            friend ostream& operator<<(ostream& os, const vec2& v)
            {
                os << v.x << " " << v.y;
                return os;
            }

            static vec2<float> normalize(vec2<int> a)
            {
                vec2<float> tmp( static_cast<float>(a.x),
                                 static_cast<float>(a.y) );
                float len = static_cast<float>(a.norm());
                return (len != 0.0) ? tmp / len : vec2<float>::ZERO;
            }

            static vec2<float> normalize( vec2<float> a )
            {
                float len = static_cast<float>(a.norm());
                return (len != 0.0) ? a / len : vec2<float>::ZERO;
            }

            static vec2<double> normalize( vec2<double> a )
            {
                double len = a.norm();
                return (len != 0.0) ? a / len : vec2<double>::ZERO;
            }

            static T dot(const vec2<T>& a, const vec2<T>& b)
            {
                return a.x*b.x + a.y*b.y;
            }

            static T cross(const vec2& a, const vec2& b)
            {
                return a.x*b.y - a.y*b.x;
            }

        public:
            T x;
            T y;
        };

        template<typename T>
        struct vec3
        {
        public:
            static const vec3 ZERO;
            static const vec3 ONE;
            static const vec3 XAXIS;
            static const vec3 YAXIS;
            static const vec3 ZAXIS;

            vec3();
            vec3(T _v);
            vec3(T _x, T _y, T _z);
            vec3(const vec3<T>& vec);
            ~vec3();

            vec3<T> operator+(const vec3<T>& v) const;
            vec3<T> operator-(const vec3<T>& v) const;
            vec3<T> operator*(const T s) const;
            vec3<T> operator*(const vec3<T>& v) const;
            vec3<T> operator/(const T s) const;

            const vec3<T>& operator+=(const vec3<T>& v);
            const vec3<T>& operator-=(const vec3<T>& v);
            const vec3<T>& operator*=(const vec3<T>& v);
            const vec3<T>& operator*=(const T s);
            const vec3<T>& operator/=(const T s);

            bool operator==(const vec3<T>& v) const;
            bool operator!=(const vec3<T>& v) const;
            bool operator<(const vec3<T>& v) const;
            bool operator<=(const vec3<T>& v) const;
            vec3<T> operator-() const;

            T norm() const;
            T normSq() const;

            const vec3<T>& normalized();

            T operator[](const int& idx) const;

            friend vec3<T> operator+ (const T s, const vec3<T>& v)
            {
                return v + s;
            }

            friend vec3<T> operator- (const T s, const vec3<T>& v)
            {
                return v - s;
            }

            friend vec3<T> operator* (const T s, const vec3<T>& v)
            {
                return v * s;
            }


            friend ostream& operator<<(ostream& os, const vec3<T>& v)
            {
                os << v.x << " " << v.y << " " << v.z;
                return os;
            }

            static vec3<float> normalize( vec3<int> a )
            {
                vec3<float> tmp( static_cast<float>(a.x),
                                 static_cast<float>(a.y),
                                 static_cast<float>(a.z) );
                float len = static_cast<float>(tmp.norm());
                return (len != 0.0f) ? tmp / len : vec3<float>::ZERO;
            }

            static vec3<float> normalize( vec3<float> a)
            {
                float len = static_cast<float>(a.norm());
                return (len != 0.0) ? a / len : vec3<float>::ZERO;
            }

            static vec3<double> normalize( vec3<double> a )
            {
                double len = a.norm();
                return (len != 0.0) ? a / len : vec3<double>::ZERO;
            }

            static T dot(const vec3<T>& a, const vec3<T>& b)
            {
                return a.x*b.x + a.y*b.y + a.z * b.z;
            }

            static vec3<T> cross(const vec3<T>& a, const vec3<T>& b)
            {
                vec3<T> res(a.y*b.z - a.z*b.y,
                            a.z*b.x - a.x*b.z,
                            a.x*b.y - a.y*b.x);

                return res;
            }

            static bool approxEqual(const vec3<T>& v1, const vec3<T>& v2, const T err = kEps)
            {
                return abs(v1.x - v2.x) < err && abs(v1.y - v2.y) < err && abs(v1.z - v2.z) < err;
            }

        public:
            T x;
            T y;
            T z;
        };

        template<typename T>
        struct vec4
        {
        public:
            static const vec4 ZERO;
            static const vec4 ONE;
            static const vec4 XAXIS;
            static const vec4 YAXIS;
            static const vec4 ZAXIS;

            vec4();
            vec4(T _v);
            vec4(T _x, T _y, T _z, T _w);
            vec4(const vec4<T>& vec);
            vec4(const vec3<T>& vec, T _w);
            ~vec4();

            vec4 operator+(const vec4& v) const;
            vec4 operator-(const vec4& v) const;
            vec4 operator*(const T s) const;
            vec4 operator*(const vec4& v) const;
            vec4 operator/(const T s) const;

            const vec4& operator+=(const vec4& v);
            const vec4& operator-=(const vec4& v);
            const vec4& operator*=(const vec4& v);
            const vec4& operator*=(const T s);
            const vec4& operator/=(const T s);

            bool operator==(const vec4& v) const;
            bool operator!=(const vec4& v) const;
            bool operator<(const vec4& v) const;
            bool operator<=(const vec4& v) const;
            vec4 operator-() const;

            T norm() const;
            T normSq() const;

            const vec4& normalized();

            T operator[](const int& idx) const;

            friend vec4 operator+ (const T s, const vec4& v)
            {
                vec4 res(v);
                res = res + s;
                return res;
            }

            friend vec4 operator- (const T s, const vec4& v)
            {
                vec4 res(v);
                res = res - s;
                return res;
            }

            friend vec4 operator* (const T s, const vec4& v)
            {
                vec4 res(v);
                res = res*s;
                return res;
            }


            friend ostream& operator<<(ostream& os, const vec4& v)
            {
                os << v.x << " " << v.y << " " << v.z<<" "<<v.w;
                return os;
            }

            static vec4<float> normalize( vec4<int> a )
            {
                vec4<float> tmp(static_cast<float>(a.x),
                                static_cast<float>(a.y), 
                                static_cast<float>(a.z), 
                                static_cast<float>(a.w));
                float len = static_cast<float>(a.norm());
                return (len != 0.0) ? tmp / len : vec4<float>::ZERO;
            }

            static vec4<float> normalize(vec4<float> a)
            {
                float len = (float)a.norm();
                return (len != 0.0) ? a / len : vec4<float>::ZERO;
            }

            static vec4<double> normalize( vec4<double> a )
            {
                double len = (double)a.norm();
                return (len != 0.0) ? a / len : vec4<double>::ZERO;
            }

            static T dot(const vec4<T>& a, const vec4<T>& b)
            {
                return a.x*b.x + a.y*b.y + a.z * b.z + a.w * b.w;
            }

            static bool approxEqual(const vec4& v1, const vec4& v2, const T err = kEps)
            {
                return abs(v1.x - v2.x) < err && abs(v1.y - v2.y) < err && abs(v1.z - v2.z) < err && abs(v1.w - v2.w) < err;
            }

        public:
            T x;
            T y;
            T z;
            T w;
        };
    }
}

typedef acLib::vec::vec2<double> Vec2;
typedef acLib::vec::vec2<int>    Vec2i;
typedef acLib::vec::vec2<float>  Vec2f;
typedef acLib::vec::vec2<double> Vec2d;

typedef acLib::vec::vec3<double> Vec3;
typedef acLib::vec::vec3<double> Color;
typedef acLib::vec::vec3<int>    Vec3i;
typedef acLib::vec::vec3<float>  Vec3f;
typedef acLib::vec::vec3<double> Vec3d;

typedef acLib::vec::vec4<double> Vec4;
typedef acLib::vec::vec4<int>    Vec4i;
typedef acLib::vec::vec4<float>  Vec4f;
typedef acLib::vec::vec4<double> Vec4d;