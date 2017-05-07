#include "Vec.h"

using namespace acLib::vec;
using namespace acLib::mat;

Vec2::Vec2() :x(0), y(0)
{}
Vec2::Vec2(double _v) : x(_v), y(_v)
{}
Vec2::Vec2(double _x, double _y) : x(_x), y(_y)
{}
Vec2::Vec2(const Vec2& orig)
{
    x = orig.x;
    y = orig.y;
}
Vec2::~Vec2()
{}

Vec2 Vec2::operator+(const Vec2& v) const
{
    Vec2 res;
    res.x = x + v.x;
    res.y = y + v.y;
    return res;
}

Vec2 Vec2::operator-(const Vec2& v) const
{
    Vec2 res;
    res.x = x - v.x;
    res.y = y - v.y;
    return res;
}

Vec2 Vec2::operator*(const double s)
{
    Vec2 res;
    res.x = x * s;
    res.y = y * s;
    return res;
}

Vec2 Vec2::operator*(const Vec2& v) const
{
    Vec2 res;
    res.x = x * v.x;
    res.y = y * v.y;
    return res;
}

Vec2 Vec2::operator/(const double s)
{
    Vec2 res;
    res.x = x / s;
    res.y = y / s;

    return res;
}

const Vec2& Vec2::operator+=(const Vec2& v)
{
    x += v.x;
    y += v.y;

    return *this;
}

const Vec2& Vec2::operator-=(const Vec2& v)
{
    x -= v.x;
    y -= v.y;

    return *this;
}

const Vec2& Vec2::operator*=(const Vec2& v)
{
    x *= v.x;
    y *= v.y;

    return *this;
}

const Vec2& Vec2::operator*=(const double s)
{
    x *= s;
    y *= s;

    return *this;
}

const Vec2& Vec2::operator/=(const double s)
{
    x /= s;
    y /= s;

    return *this;
}

bool Vec2::operator==(const Vec2& v) const
{
    return (x == v.x && y == v.y);
}
bool Vec2::operator<(const Vec2& v) const
{
    if (y == v.y)
        return x < v.x;
    return y < v.y;
}
bool Vec2::operator<=(const Vec2& v) const
{
    return y <= v.y;
}

Vec2 Vec2::operator-() const
{
    Vec2 res(*this);
    res *= -1.0;
    return res;
}

double Vec2::norm()
{
    return sqrt(x*x + y*y);
}

const Vec2& Vec2::normalized()
{
    *this /= this->norm();
    return *this;
}

Vec3::Vec3() :x(0), y(0), z(0) {}
Vec3::Vec3(double _v) : x(_v), y(_v), z(_v)
{}
Vec3::Vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z)
{}
Vec3::Vec3(const Vec3& vec) : x(vec.x), y(vec.y), z(vec.z)
{
}
Vec3::~Vec3()
{}

Vec3 Vec3::operator+(const Vec3& v) const
{
    Vec3 res;
    res.x = x + v.x;
    res.y = y + v.y;
    res.z = z + v.z;
    return res;
}

Vec3 Vec3::operator-(const Vec3& v) const
{
    Vec3 res;
    res.x = x - v.x;
    res.y = y - v.y;
    res.z = z - v.z;
    return res;
}

Vec3 Vec3::operator*(const double s) const
{
    Vec3 res;
    res.x = x * s;
    res.y = y * s;
    res.z = z * s;
    return res;
}

Vec3 Vec3::operator*(const Vec3& v) const
{
    Vec3 res;
    res.x = x * v.x;
    res.y = y * v.y;
    res.z = z * v.z;
    return res;
}

Vec3 Vec3::operator/(const double s) const
{
    Vec3 res;
    res.x = x / s;
    res.y = y / s;
    res.z = z / s;

    return res;
}

const Vec3& Vec3::operator+=(const Vec3& v)
{
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
}

const Vec3& Vec3::operator-=(const Vec3& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;

    return *this;
}

const Vec3& Vec3::operator*=(const Vec3& v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;

    return *this;
}

const Vec3& Vec3::operator*=(const double s)
{
    x *= s;
    y *= s;
    z *= s;

    return *this;
}

const Vec3& Vec3::operator/=(const double s)
{
    x /= s;
    y /= s;
    z /= s;

    return *this;
}

bool Vec3::operator==(const Vec3& v) const
{
    return (x == v.x && y == v.y && z == v.z);
}
bool Vec3::operator<(const Vec3& v) const
{
    if (y == v.y)
        return x < v.x;
    return y < v.y;
}
bool Vec3::operator<=(const Vec3& v) const
{
    return y <= v.y;
}

Vec3 Vec3::operator-() const
{
    Vec3 res(*this);
    res *= -1.0;
    return res;
}

double Vec3::norm() const
{
    return sqrt(normSq());
}

double Vec3::normSq() const
{
    return x*x + y*y + z*z;
}

const Vec3& Vec3::normalized()
{
    *this /= this->norm();
    return *this;
}

const Vec3& Vec3::transform(const Mat33& mat)
{
    *this = Vec3(Vec3::dot(mat.GetRow(0), *this), Vec3::dot(mat.GetRow(1), *this), Vec3::dot(mat.GetRow(2), *this));
    return *this;
}

double Vec3::operator[](const int& idx) const
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
    else
    {
        cerr << "Vec3 Out of bounds:" << idx << endl;
    }

    return 0.0;
}

Vec3 Vec3::ZERO = Vec3(0.0, 0.0, 0.0);
Vec3 Vec3::ONE = Vec3(1.0, 1.0, 1.0);


Vec4::Vec4()
{
    *this = Vec4::ZERO;
}
Vec4::Vec4(double _v) : x(_v), y(_v), z(_v), w(_v)
{}
Vec4::Vec4(double _x, double _y, double _z, double _w) : x(_x), y(_y), z(_z), w(_w)
{}
Vec4::Vec4(const Vec4& vec)
{
    *this = vec;
}
Vec4::Vec4(const Vec3& vec, double _w)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
    w = _w;
}
Vec4::~Vec4()
{}

Vec4 Vec4::operator+(const Vec4& v) const
{
    Vec4 res;
    res.x = x + v.x;
    res.y = y + v.y;
    res.z = z + v.z;
    res.w = w + v.w;

    return res;
}

Vec4 Vec4::operator-(const Vec4& v) const
{
    Vec4 res;
    res.x = x - v.x;
    res.y = y - v.y;
    res.z = z - v.z;
    res.w = w - v.w;

    return res;
}

Vec4 Vec4::operator*(const double s) const
{
    Vec4 res;
    res.x = x * s;
    res.y = y * s;
    res.z = z * s;
    res.w = w * s;

    return res;
}

Vec4 Vec4::operator*(const Vec4& v) const
{
    Vec4 res;
    res.x = x * v.x;
    res.y = y * v.y;
    res.z = z * v.z;
    return res;
}

Vec4 Vec4::operator/(const double s) const
{
    Vec4 res;
    res.x = x / s;
    res.y = y / s;
    res.z = z / s;
    res.w = w / s;

    return res;
}

const Vec4& Vec4::operator+=(const Vec4& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;

    return *this;
}

const Vec4& Vec4::operator-=(const Vec4& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;

    return *this;
}

const Vec4& Vec4::operator*=(const Vec4& v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
    w *= v.w;

    return *this;
}

const Vec4& Vec4::operator*=(const double s)
{
    x *= s;
    y *= s;
    z *= s;
    w *= s;

    return *this;
}

const Vec4& Vec4::operator/=(const double s)
{
    x /= s;
    y /= s;
    z /= s;
    w /= s;

    return *this;
}

bool Vec4::operator==(const Vec4& v) const
{
    return (x == v.x && y == v.y && z == v.z);
}
bool Vec4::operator<(const Vec4& v) const
{
    if (y == v.y)
        return x < v.x;
    return y < v.y;
}
bool Vec4::operator<=(const Vec4& v) const
{
    return y <= v.y;
}

Vec4 Vec4::operator-() const
{
    Vec4 res(*this);
    res *= -1.0;
    return res;
}

double Vec4::norm() const
{
    return sqrt(normSq());
}

double Vec4::normSq() const
{
    return x*x + y*y + z*z;
}

const Vec4& Vec4::normalized()
{
    *this /= this->norm();
    return *this;
}

const Vec4& Vec4::transform(const Mat44& mat)
{
    *this = Vec4(Vec4::dot(mat.GetRow(0), *this), 
                 Vec4::dot(mat.GetRow(1), *this), 
                 Vec4::dot(mat.GetRow(2), *this), 
                 Vec4::dot(mat.GetRow(3), *this));

    return *this;
}

double Vec4::operator[](const int& idx) const
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
    else
    {
        cerr << "Vec4 Out of bounds:" << idx << endl;
    }

    return 0.0;
}

Vec4 Vec4::ZERO = Vec4(0.0, 0.0, 0.0, 0.0);
Vec4 Vec4::ONE = Vec4(1.0, 1.0, 1.0, 1.0);
