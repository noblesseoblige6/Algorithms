#pragma once
#include <iostream>
#include <cmath>

#include "Constant.h"
#include "Mat.h"

namespace acLib
{
    namespace vec
    {
        using namespace std;
        using namespace acLib::constant;
        
        enum VEC_INDEX
        {
            X,
            Y,
            Z,
            W
        };

        struct Vec2
        {
        public:
            Vec2();
            Vec2(double _v);
            Vec2(double _x, double _y);
            Vec2(const Vec2& orig);
            ~Vec2();

            Vec2 operator+(const Vec2& v) const;
            Vec2 operator-(const Vec2& v) const;
            Vec2 operator*(const double s);
            Vec2 operator*(const Vec2& v) const;
            Vec2 operator/(const double s);

            const Vec2& operator+=(const Vec2& v);
            const Vec2& operator-=(const Vec2& v);
            const Vec2& operator*=(const double s);
            const Vec2& operator/=(const double s);

            bool operator==(const Vec2& v) const;
            bool operator<(const Vec2& v) const;
            bool operator<=(const Vec2& v) const;

            Vec2 operator-() const;

            double norm();
            const Vec2& normalized();

            friend Vec2 operator+ (const double s, const Vec2& v)
            {
                Vec2 res(v);
                res = res + s;
                return res;
            }

            friend Vec2 operator- (const double s, const Vec2& v)
            {
                Vec2 res(v);
                res = res - s;
                return res;
            }

            friend Vec2 operator* (const double s, const Vec2& v)
            {
                Vec2 res(v);
                res = res*s;
                return res;
            }

            friend ostream& operator<<(ostream& os, const Vec2& v)
            {
                os << v.x << " " << v.y;
                return os;
            }

            static Vec2 normalize(Vec2 a)
            {
                Vec2 res;
                double len = a.norm();
                if (len != 0.0) {
                    res = a / len;
                }
                else {
                    res = Vec2(0.0);
                }

                return res;
            }

            static double dot(const Vec2& a, const Vec2& b)
            {
                return a.x*b.x + a.y*b.y;
            }

            static double cross(const Vec2& a, const Vec2& b)
            {
                return a.x*b.y - a.y*b.x;
            }

        public:
            double x;
            double y;
        };

        struct Vec3
        {
        public:
            static Vec3 ZERO;
            static Vec3 ONE;

            static int X;
            static int Y;
            static int Z;

            Vec3();
            Vec3(double _v);
            Vec3(double _x, double _y, double _z);
            Vec3(const Vec3& vec);
            ~Vec3();

            Vec3 operator+(const Vec3& v) const;
            Vec3 operator-(const Vec3& v) const;
            Vec3 operator*(const double s) const;
            Vec3 operator*(const Vec3& v) const;
            Vec3 operator/(const double s) const;

            const Vec3& operator+=(const Vec3& v);
            const Vec3& operator-=(const Vec3& v);
            const Vec3& operator*=(const double s);
            const Vec3& operator/=(const double s);

            bool operator==(const Vec3& v) const;
            bool operator<(const Vec3& v) const;
            bool operator<=(const Vec3& v) const;
            Vec3 operator-() const;

            double norm() const;
            double normSq() const;

            const Vec3& normalized();
            const Vec3& transform(const acLib::mat::Mat33& mat);

            double operator[](const int& idx) const;

            friend Vec3 operator+ (const double s, const Vec3& v)
            {
                Vec3 res(v);
                res = res + s;
                return res;
            }

            friend Vec3 operator- (const double s, const Vec3& v)
            {
                Vec3 res(v);
                res = res - s;
                return res;
            }

            friend Vec3 operator* (const double s, const Vec3& v)
            {
                Vec3 res(v);
                res = res*s;
                return res;
            }


            friend ostream& operator<<(ostream& os, const Vec3& v)
            {
                os << v.x << " " << v.y << " " << v.z;
                return os;
            }

            static Vec3 normalize(Vec3 a)
            {
                Vec3 res;
                double len = a.norm();
                if (len != 0.0) {
                    res = a / len;
                }
                else {
                    res = Vec3(0.0);
                }

                return res;
            }

            static double dot(const Vec3& a, const Vec3& b)
            {
                return a.x*b.x + a.y*b.y + a.z * b.z;
            }

            static Vec3 cross(const Vec3& a, const Vec3& b)
            {
                Vec3 res(a.y*b.z - a.z*b.y,
                    a.z*b.x - a.x*b.z,
                    a.x*b.y - a.y*b.x);

                return res;
            }

            static bool approxEqual(const Vec3& v1, const Vec3& v2, const double err = kEps)
            {
                return abs(v1.x - v2.x) < err && abs(v1.y - v2.y) < err && abs(v1.z - v2.z) < err;
            }

        public:
            double x;
            double y;
            double z;
        };

        struct Vec4
        {
        public:
            static Vec4 ZERO;
            static Vec4 ONE;

            Vec4();
            Vec4(double _v);
            Vec4(double _x, double _y, double _z, double _w);
            Vec4(const Vec4& vec);
            ~Vec4();

            Vec4 operator+(const Vec4& v) const;
            Vec4 operator-(const Vec4& v) const;
            Vec4 operator*(const double s) const;
            Vec4 operator*(const Vec4& v) const;
            Vec4 operator/(const double s) const;

            const Vec4& operator+=(const Vec4& v);
            const Vec4& operator-=(const Vec4& v);
            const Vec4& operator*=(const double s);
            const Vec4& operator/=(const double s);

            bool operator==(const Vec4& v) const;
            bool operator<(const Vec4& v) const;
            bool operator<=(const Vec4& v) const;
            Vec4 operator-() const;

            double norm() const;
            double normSq() const;

            const Vec4& normalized();
            const Vec4& transform(const acLib::mat::Mat44& mat);

            double operator[](const int& idx) const;

            friend Vec4 operator+ (const double s, const Vec4& v)
            {
                Vec4 res(v);
                res = res + s;
                return res;
            }

            friend Vec4 operator- (const double s, const Vec4& v)
            {
                Vec4 res(v);
                res = res - s;
                return res;
            }

            friend Vec4 operator* (const double s, const Vec4& v)
            {
                Vec4 res(v);
                res = res*s;
                return res;
            }


            friend ostream& operator<<(ostream& os, const Vec4& v)
            {
                os << v.x << " " << v.y << " " << v.z<<" "<<v.w;
                return os;
            }

            static Vec4 normalize(Vec4 a)
            {
                Vec4 res;
                double len = a.norm();
                if (len != 0.0) {
                    res = a / len;
                }
                else {
                    res = Vec4::ZERO;
                }

                return res;
            }

            static double dot(const Vec4& a, const Vec4& b)
            {
                return a.x*b.x + a.y*b.y + a.z * b.z + a.w * b.w;
            }

            static bool approxEqual(const Vec4& v1, const Vec4& v2, const double err = kEps)
            {
                return abs(v1.x - v2.x) < err && abs(v1.y - v2.y) < err && abs(v1.z - v2.z) < err && abs(v1.w - v2.w) < err;
            }

        public:
            double x;
            double y;
            double z;
            double w;
        };
    }
}

typedef acLib::vec::Vec3 Vec;
typedef acLib::vec::Vec3 Color;