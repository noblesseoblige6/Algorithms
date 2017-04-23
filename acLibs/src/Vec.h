#pragma once
#include <iostream>
#include <cmath>

namespace acLib
{
  namespace vec
  {
    using namespace std;

    struct Vec2
    {
      public:
        Vec2():x(0), y(0)
      {}
        Vec2(double _v) : x(_v), y(_v)
      {}
        Vec2(double _x, double _y) : x(_x), y(_y)
      {}
        //@comment copy constructor
        Vec2(const Vec2& orig)
        {
          x = orig.x;
          y = orig.y;
        }
        ~Vec2()
        {}

        Vec2 operator+(const Vec2& v) const
        {
            Vec2 res;
            res.x = x + v.x;
            res.y = y + v.y;
            return res;
        }

        Vec2 operator-(const Vec2& v) const
        {
            Vec2 res;
            res.x = x - v.x;
            res.y = y - v.y;
            return res;
        }

        Vec2 operator*(const double s)
        {
            Vec2 res;
            res.x = x * s;
            res.y = y * s;
            return res;
        }

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

        Vec2 operator/(const double s)
        {
            Vec2 res;
            res.x = x / s;
            res.y = y / s;

            return res;
        }

        const Vec2& operator+=(const Vec2& v)
        {
            x += v.x;
            y += v.y;

            return *this;
        }

        const Vec2& operator-=(const Vec2& v)
        {
            x -= v.x;
            y -= v.y;

            return *this;
        }

        const Vec2& operator*=(const double s)
        {
            x *= s;
            y *= s;

            return *this;
        }

        const Vec2& operator/=(const double s)
        {
            x /= s;
            y /= s;

            return *this;
        }

        bool operator==(const Vec2& v) const
        {
            return (x == v.x && y == v.y);
        }
        bool operator<(const Vec2& v) const
        {
            if (y == v.y)
                return x < v.x;
            return y < v.y;
        }
        bool operator<=(const Vec2& v) const
        {
            return y <= v.y;
        }

        Vec2 operator-() const
        {
            Vec2 res(*this);
            res *= -1.0;
            return res;
        }

        double norm()
        {
            return sqrt(x*x + y*y);
        }

        const Vec2& normalized()
        {
            *this /= this->norm();
            return *this;
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
        Vec3():x(0), y(0), z(0)
      {}
        Vec3(double _v) : x(_v), y(_v), z(_v)
        {}
        Vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z)
      {}
        ~Vec3()
        {}

        Vec3 operator+(const Vec3& v) const
        {
          Vec3 res;
          res.x = x + v.x;
          res.y = y + v.y;
          res.z = z + v.z;
          return res;
        }

        Vec3 operator-(const Vec3& v) const
        {
          Vec3 res;
          res.x = x - v.x;
          res.y = y - v.y;
          res.z = z - v.z;
          return res;
        }

        Vec3 operator*(const double s) const
        {
          Vec3 res;
          res.x = x * s;
          res.y = y * s;
          res.z = z * s;
          return res;
        }

        friend Vec3 operator+ (const double s, const Vec3& v)
        {
            Vec3 res(v);
            res = res+s;
            return res;
        }

        friend Vec3 operator- (const double s, const Vec3& v)
        {
            Vec3 res(v);
            res = res-s;
            return res;
        }

        friend Vec3 operator* (const double s, const Vec3& v)
        {
            Vec3 res(v);
            res = res*s;
            return res;
        }

        Vec3 operator/(const double s) const
        {
          Vec3 res;
          res.x = x / s;
          res.y = y / s;
          res.z = z / s;

          return res;
        }

        const Vec3& operator+=(const Vec3& v)
        {
            x += v.x;
            y += v.y;
            z += v.z;

            return *this;
        }

        const Vec3& operator-=(const Vec3& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;

            return *this;
        }

        const Vec3& operator*=(const double s)
        {
            x *= s;
            y *= s;
            z *= s;

            return *this;
        }

        const Vec3& operator/=(const double s)
        {
            x /= s;
            y /= s;
            z /= s;

            return *this;
        }

        bool operator==(const Vec3& v) const
        {
          return (x == v.x && y == v.y && z == v.z);
        }
        bool operator<(const Vec3& v) const
        {
          if(y == v.y)
            return x < v.x;
          return y < v.y;
        }
        bool operator<=(const Vec3& v) const
        {
          return y <= v.y;
        }

        Vec3 operator-() const
        {
            Vec3 res(*this);
            res *= -1.0;
            return res;
        }

        double norm()
        {
            return sqrt(x*x + y*y + z*z);
        }

        const Vec3& normalized()
        {
            *this /= this->norm();
            return *this;
        }

        friend ostream& operator<<(ostream& os, const Vec3& v)
        {
          os<<v.x<<" "<<v.y<<" "<<v.z;
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

      public:
        double x;
        double y;
        double z;
    };
  }
}
