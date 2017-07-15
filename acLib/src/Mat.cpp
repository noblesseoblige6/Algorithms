#include "Mat.h"
#include "Vec.h"

using namespace acLib::mat;
using namespace acLib::vec;

Mat33::Mat33()
{
    *this = Mat33::IDENTITY;
}

Mat33::Mat33(const double* row0, const double* row1, const double* row2)
{
    m[0][0] = row0[0];
    m[0][1] = row0[1];
    m[0][2] = row0[2];

    m[1][0] = row1[0];
    m[1][1] = row1[1];
    m[1][2] = row1[2];

    m[2][0] = row2[0];
    m[2][1] = row2[1];
    m[2][2] = row2[2];
}

Mat33::Mat33(const Vec3& row0, const Vec3& row1, const Vec3& row2)
{
    m[0][0] = row0.x;
    m[0][1] = row0.y;
    m[0][2] = row0.z;

    m[1][0] = row1.x;
    m[1][1] = row1.y;
    m[1][2] = row1.z;

    m[2][0] = row2.x;
    m[2][1] = row2.y;
    m[2][2] = row2.z;
}

Mat33::Mat33(double m00, double m01, double m02,
             double m10, double m11, double m12,
             double m20, double m21, double m22)
{
    m[0][0] = m00;
    m[0][1] = m01;
    m[0][2] = m02;

    m[1][0] = m10;
    m[1][1] = m11;
    m[1][2] = m12;

    m[2][0] = m20;
    m[2][1] = m21;
    m[2][2] = m22;
}

Mat33::Mat33(const Mat33& mat)
{
    *this = mat;
}

Mat33::~Mat33()
{}

const Mat33& Mat33::operator=(const Mat33& mat)
{
    m[0][0] = mat.m[0][0];
    m[0][1] = mat.m[0][1];
    m[0][2] = mat.m[0][2];

    m[1][0] = mat.m[1][0];
    m[1][1] = mat.m[1][1];
    m[1][2] = mat.m[1][2];

    m[2][0] = mat.m[2][0];
    m[2][1] = mat.m[2][1];
    m[2][2] = mat.m[2][2];

    return *this;
}

Mat33 Mat33::operator+(const double& v) const
{
    Mat33 res;
    res.m[0][0] = m[0][0] + v;
    res.m[0][1] = m[0][1] + v;
    res.m[0][2] = m[0][2] + v;

    res.m[1][0] = m[1][0] + v;
    res.m[1][1] = m[1][1] + v;
    res.m[1][2] = m[1][2] + v;

    res.m[2][0] = m[2][0] + v;
    res.m[2][1] = m[2][1] + v;
    res.m[2][2] = m[2][2] + v;

    return res;
}

Mat33 Mat33::operator+(const Mat33& mat) const
{
    Mat33 res;
    res.m[0][0] = m[0][0] + mat.m[0][0];
    res.m[0][1] = m[0][1] + mat.m[0][1];
    res.m[0][2] = m[0][2] + mat.m[0][2];

    res.m[1][0] = m[1][0] + mat.m[1][0];
    res.m[1][1] = m[1][1] + mat.m[1][1];
    res.m[1][2] = m[1][2] + mat.m[1][2];

    res.m[2][0] = m[2][0] + mat.m[2][0];
    res.m[2][1] = m[2][1] + mat.m[2][1];
    res.m[2][2] = m[2][2] + mat.m[2][2];

    return res;
}

Mat33 Mat33::operator-(const double& v) const
{
    Mat33 res;
    res.m[0][0] = m[0][0] - v;
    res.m[0][1] = m[0][1] - v;
    res.m[0][2] = m[0][2] - v;

    res.m[1][0] = m[1][0] - v;
    res.m[1][1] = m[1][1] - v;
    res.m[1][2] = m[1][2] - v;

    res.m[2][0] = m[2][0] - v;
    res.m[2][1] = m[2][1] - v;
    res.m[2][2] = m[2][2] - v;

    return res;
}

Mat33 Mat33::operator-(const Mat33& mat) const
{
    Mat33 res;
    res.m[0][0] = m[0][0] - mat.m[0][0];
    res.m[0][1] = m[0][1] - mat.m[0][1];
    res.m[0][2] = m[0][2] - mat.m[0][2];

    res.m[1][0] = m[1][0] - mat.m[1][0];
    res.m[1][1] = m[1][1] - mat.m[1][1];
    res.m[1][2] = m[1][2] - mat.m[1][2];

    res.m[2][0] = m[2][0] - mat.m[2][0];
    res.m[2][1] = m[2][1] - mat.m[2][1];
    res.m[2][2] = m[2][2] - mat.m[2][2];

    return res;
}

Mat33 Mat33::operator*(const double s) const
{
    Mat33 res;
    res.m[0][0] = m[0][0] * s;
    res.m[0][1] = m[0][1] * s;
    res.m[0][2] = m[0][2] * s;

    res.m[1][0] = m[1][0] * s;
    res.m[1][1] = m[1][1] * s;
    res.m[1][2] = m[1][2] * s;

    res.m[2][0] = m[2][0] * s;
    res.m[2][1] = m[2][1] * s;
    res.m[2][2] = m[2][2] * s;

    return res;
}

Mat33 Mat33::operator/(const double s) const
{
    Mat33 res;
    res.m[0][0] = m[0][0] / s;
    res.m[0][1] = m[0][1] / s;
    res.m[0][2] = m[0][2] / s;

    res.m[1][0] = m[1][0] / s;
    res.m[1][1] = m[1][1] / s;
    res.m[1][2] = m[1][2] / s;

    res.m[2][0] = m[2][0] / s;
    res.m[2][1] = m[2][1] / s;
    res.m[2][2] = m[2][2] / s;

    return res;
}

bool Mat33::operator==(const Mat33& mat) const
{
    return (m[0][0] == mat.m[0][0] && m[0][1] == mat.m[0][1] && m[0][2] == mat.m[0][2]) &&
        (m[1][0] == mat.m[1][0] && m[1][1] == mat.m[1][1] && m[1][2] == mat.m[1][2]) &&
        (m[2][0] == mat.m[2][0] && m[2][1] == mat.m[2][1] && m[2][2] == mat.m[2][2]);
}

bool Mat33::operator!=(const Mat33& mat) const
{
    return !(*this == mat);
}

Mat33 Mat33::operator-() const
{
    Mat33 res(*this);
    res = -1.0 * res;
    return res;
}

double Mat33::Determinant() const
{
    double det = m[0][0] * m[1][1] * m[2][2]
               + m[0][1] * m[1][2] * m[2][0]
               + m[0][2] * m[1][0] * m[2][1]
               - m[0][2] * m[1][1] * m[2][0]
               - m[0][1] * m[1][0] * m[2][2]
               - m[0][0] * m[1][2] * m[2][1];

    return det;
}

Mat33 Mat33::Inverse()
{
    Mat33 res;

    double det = Determinant();
    if (det == 0.0)
    {
        return *this;
    }

    res.m[0][0] = (m[1][1] * m[2][2] - m[1][2] * m[2][1]) / det;
    res.m[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) / det;
    res.m[2][0] = (m[1][0] * m[2][1] - m[1][1] * m[2][0]) / det;

    res.m[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) / det;
    res.m[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) / det;
    res.m[2][1] = (m[0][1] * m[2][0] - m[0][0] * m[2][1]) / det;

    res.m[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) / det;
    res.m[1][2] = (m[0][2] * m[1][0] - m[0][0] * m[1][2]) / det;
    res.m[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) / det;

    return res;
}

Vec3 Mat33::GetRow(const int row) const
{
    return Vec3(m[row][0], m[row][1], m[row][2]);
}

Vec3 Mat33::GetColumn(const int column) const
{
    return Vec3(m[0][column], m[1][column], m[2][column]);
}

double Mat33::GetElement(const int row, const int column) const
{
    return m[row][column];
}

Mat33 Mat33::IDENTITY = Mat33(1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0);

Mat33 Mat33::ZERO = Mat33(0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0);


Mat44::Mat44()
{
    *this = Mat44::IDENTITY;
}

Mat44::Mat44(const double* row0, const double* row1, const double* row2, const double* row3)
{
    m[0][0] = row0[0];
    m[0][1] = row0[1];
    m[0][2] = row0[2];
    m[0][3] = row0[3];

    m[1][0] = row1[0];
    m[1][1] = row1[1];
    m[1][2] = row1[2];
    m[1][3] = row1[3];

    m[2][0] = row2[0];
    m[2][1] = row2[1];
    m[2][2] = row2[2];
    m[2][3] = row2[3];

    m[3][0] = row3[0];
    m[3][1] = row3[1];
    m[3][2] = row3[2];
    m[3][3] = row3[3];
}

Mat44::Mat44(const Vec4& row0, const Vec4& row1, const Vec4& row2, const Vec4& row3)
{
    m[0][0] = row0.x;
    m[0][1] = row0.y;
    m[0][2] = row0.z;
    m[0][3] = row0.w;

    m[1][0] = row1.x;
    m[1][1] = row1.y;
    m[1][2] = row1.z;
    m[1][3] = row1.w;

    m[2][0] = row2.x;
    m[2][1] = row2.y;
    m[2][2] = row2.z;
    m[2][3] = row2.w;

    m[3][0] = row3.x;
    m[3][1] = row3.y;
    m[3][2] = row3.z;
    m[3][3] = row3.w;
}

Mat44::Mat44(double m00, double m01, double m02, double m03,
             double m10, double m11, double m12, double m13,
             double m20, double m21, double m22, double m23,
             double m30, double m31, double m32, double m33)
{
    m[0][0] = m00;
    m[0][1] = m01;
    m[0][2] = m02;
    m[0][3] = m03;

    m[1][0] = m10;
    m[1][1] = m11;
    m[1][2] = m12;
    m[1][3] = m13;

    m[2][0] = m20;
    m[2][1] = m21;
    m[2][2] = m22;
    m[2][3] = m23;

    m[3][0] = m30;
    m[3][1] = m31;
    m[3][2] = m32;
    m[3][3] = m33;
}

Mat44::Mat44(const Mat44& mat)
{
    *this = mat;
}

Mat44::~Mat44()
{}

const Mat44& Mat44::operator=(const Mat44& mat)
{
    m[0][0] = mat.m[0][0];
    m[0][1] = mat.m[0][1];
    m[0][2] = mat.m[0][2];
    m[0][3] = mat.m[0][3];

    m[1][0] = mat.m[1][0];
    m[1][1] = mat.m[1][1];
    m[1][2] = mat.m[1][2];
    m[1][3] = mat.m[1][3];

    m[2][0] = mat.m[2][0];
    m[2][1] = mat.m[2][1];
    m[2][2] = mat.m[2][2];
    m[2][3] = mat.m[2][3];

    m[3][0] = mat.m[3][0];
    m[3][1] = mat.m[3][1];
    m[3][2] = mat.m[3][2];
    m[3][3] = mat.m[3][3];

    return *this;
}

Mat44 Mat44::operator+(const double& v) const
{
    Mat44 res;
    res.m[0][0] = m[0][0] + v;
    res.m[0][1] = m[0][1] + v;
    res.m[0][2] = m[0][2] + v;
    res.m[0][3] = m[0][3] + v;

    res.m[1][0] = m[1][0] + v;
    res.m[1][1] = m[1][1] + v;
    res.m[1][2] = m[1][2] + v;
    res.m[1][3] = m[1][3] + v;

    res.m[2][0] = m[2][0] + v;
    res.m[2][1] = m[2][1] + v;
    res.m[2][2] = m[2][2] + v;
    res.m[2][3] = m[2][3] + v;

    res.m[3][0] = m[3][0] + v;
    res.m[3][1] = m[3][1] + v;
    res.m[3][2] = m[3][2] + v;
    res.m[3][3] = m[3][3] + v;

    return res;
}

Mat44 Mat44::operator+(const Mat44& mat) const
{
    Mat44 res;
    res.m[0][0] = m[0][0] + mat.m[0][0];
    res.m[0][1] = m[0][1] + mat.m[0][1];
    res.m[0][2] = m[0][2] + mat.m[0][2];
    res.m[0][3] = m[0][3] + mat.m[0][3];

    res.m[1][0] = m[1][0] + mat.m[1][0];
    res.m[1][1] = m[1][1] + mat.m[1][1];
    res.m[1][2] = m[1][2] + mat.m[1][2];
    res.m[1][3] = m[1][3] + mat.m[1][3];

    res.m[2][0] = m[2][0] + mat.m[2][0];
    res.m[2][1] = m[2][1] + mat.m[2][1];
    res.m[2][2] = m[2][2] + mat.m[2][2];
    res.m[2][3] = m[2][3] + mat.m[2][3];

    res.m[3][0] = m[3][0] + mat.m[3][0];
    res.m[3][1] = m[3][1] + mat.m[3][1];
    res.m[3][2] = m[3][2] + mat.m[3][2];
    res.m[3][3] = m[3][3] + mat.m[3][3];

    return res;
}

Mat44 Mat44::operator-(const double& v) const
{
    Mat44 res;
    res.m[0][0] = m[0][0] - v;
    res.m[0][1] = m[0][1] - v;
    res.m[0][2] = m[0][2] - v;
    res.m[0][3] = m[0][3] - v;

    res.m[1][0] = m[1][0] - v;
    res.m[1][1] = m[1][1] - v;
    res.m[1][2] = m[1][2] - v;
    res.m[1][3] = m[1][3] - v;

    res.m[2][0] = m[2][0] - v;
    res.m[2][1] = m[2][1] - v;
    res.m[2][2] = m[2][2] - v;
    res.m[2][3] = m[2][3] - v;

    res.m[3][0] = m[3][0] - v;
    res.m[3][1] = m[3][1] - v;
    res.m[3][2] = m[3][2] - v;
    res.m[3][3] = m[3][3] - v;
    return res;
}

Mat44 Mat44::operator-(const Mat44& mat) const
{
    Mat44 res;
    res.m[0][0] = m[0][0] - mat.m[0][0];
    res.m[0][1] = m[0][1] - mat.m[0][1];
    res.m[0][2] = m[0][2] - mat.m[0][2];
    res.m[0][3] = m[0][3] - mat.m[0][3];

    res.m[1][0] = m[1][0] - mat.m[1][0];
    res.m[1][1] = m[1][1] - mat.m[1][1];
    res.m[1][2] = m[1][2] - mat.m[1][2];
    res.m[1][3] = m[1][3] - mat.m[1][3];

    res.m[2][0] = m[2][0] - mat.m[2][0];
    res.m[2][1] = m[2][1] - mat.m[2][1];
    res.m[2][2] = m[2][2] - mat.m[2][2];
    res.m[2][3] = m[2][3] - mat.m[2][3];

    res.m[3][0] = m[3][0] - mat.m[3][0];
    res.m[3][1] = m[3][1] - mat.m[3][1];
    res.m[3][2] = m[3][2] - mat.m[3][2];
    res.m[3][3] = m[3][3] - mat.m[3][3];

    return res;
}

Mat44 Mat44::operator*(const double s) const
{
    Mat44 res;
    res.m[0][0] = m[0][0] * s;
    res.m[0][1] = m[0][1] * s;
    res.m[0][2] = m[0][2] * s;
    res.m[0][3] = m[0][3] * s;

    res.m[1][0] = m[1][0] * s;
    res.m[1][1] = m[1][1] * s;
    res.m[1][2] = m[1][2] * s;
    res.m[1][3] = m[1][3] * s;

    res.m[2][0] = m[2][0] * s;
    res.m[2][1] = m[2][1] * s;
    res.m[2][2] = m[2][2] * s;
    res.m[2][3] = m[2][3] * s;

    res.m[3][0] = m[3][0] * s;
    res.m[3][1] = m[3][1] * s;
    res.m[3][2] = m[3][2] * s;
    res.m[3][3] = m[3][3] * s;

    return res;
}

Mat44 Mat44::operator/(const double s) const
{
    Mat44 res;
    res.m[0][0] = m[0][0] / s;
    res.m[0][1] = m[0][1] / s;
    res.m[0][2] = m[0][2] / s;
    res.m[0][3] = m[0][3] / s;

    res.m[1][0] = m[1][0] / s;
    res.m[1][1] = m[1][1] / s;
    res.m[1][2] = m[1][2] / s;
    res.m[1][3] = m[1][3] / s;

    res.m[2][0] = m[2][0] / s;
    res.m[2][1] = m[2][1] / s;
    res.m[2][2] = m[2][2] / s;
    res.m[2][3] = m[2][3] / s;

    res.m[3][0] = m[3][0] / s;
    res.m[3][1] = m[3][1] / s;
    res.m[3][2] = m[3][2] / s;
    res.m[3][3] = m[3][3] / s;

    return res;
}

bool Mat44::operator==(const Mat44& mat) const
{
    return (m[0][0] == mat.m[0][0] && m[0][1] == mat.m[0][1] && m[0][2] == mat.m[0][2] && m[0][3] == mat.m[0][3]) &&
           (m[1][0] == mat.m[1][0] && m[1][1] == mat.m[1][1] && m[1][2] == mat.m[1][2] && m[1][3] == mat.m[1][3]) &&
           (m[2][0] == mat.m[2][0] && m[2][1] == mat.m[2][1] && m[2][2] == mat.m[2][2] && m[2][3] == mat.m[2][3]) &&
           (m[3][0] == mat.m[3][0] && m[3][1] == mat.m[3][1] && m[3][2] == mat.m[3][2] && m[3][3] == mat.m[3][3]);
}

bool Mat44::operator!=(const Mat44& mat) const
{
    return !(*this == mat);
}

Mat44 Mat44::operator-() const
{
    Mat44 res(*this);
    res = -1.0 * res;
    return res;
}

double Mat44::Determinant() const
{
    const Vec4& row0 = GetRow(0);
    const Vec4& row1 = GetRow(1);
    const Vec4& row2 = GetRow(2);
    const Vec4& row3 = GetRow(3);

    const Mat33 A0(Vec3(row1[1], row1[2], row1[3]), 
                   Vec3(row2[1], row2[2], row2[3]), 
                   Vec3(row3[1], row3[2], row3[3]));

    const Mat33 A1(Vec3(row0[1], row0[2], row0[3]), 
                   Vec3(row2[1], row2[2], row2[3]), 
                   Vec3(row3[1], row3[2], row3[3]));

    const Mat33 A2(Vec3(row0[1], row0[2], row0[3]), 
                   Vec3(row1[1], row1[2], row1[3]), 
                   Vec3(row3[1], row3[2], row3[3]));

    const Mat33 A3(Vec3(row0[1], row0[2], row0[3]), 
                   Vec3(row1[1], row1[2], row1[3]), 
                   Vec3(row2[1], row2[2], row2[3]));

    return m[0][0]*A0.Determinant() - m[1][0]* A1.Determinant() + m[2][0]* A2.Determinant() - m[3][0]* A3.Determinant();
}

Mat44 Mat44::Inverse()
{
    Mat44 res;

    double det = Determinant();
    if (det == 0.0)
    {
        cerr << "Waring: No Inverse Matrix" << endl;
        return *this;
    }

    const Vec4& row0 = GetRow(0);
    const Vec4& row1 = GetRow(1);
    const Vec4& row2 = GetRow(2);
    const Vec4& row3 = GetRow(3);

    Mat33 M[4][4];
    M[0][0] = Mat33(Vec3(row1[1], row1[2], row1[3]), 
                    Vec3(row2[1], row2[2], row2[3]), 
                    Vec3(row3[1], row3[2], row3[3]));

    M[0][1] = Mat33(Vec3(row1[0], row1[2], row1[3]), 
                    Vec3(row2[0], row2[2], row2[3]), 
                    Vec3(row3[0], row3[2], row3[3]));

    M[0][2] = Mat33(Vec3(row1[0], row1[1], row1[3]), 
                    Vec3(row2[0], row2[1], row2[3]), 
                    Vec3(row3[0], row3[1], row3[3]));

    M[0][3] = Mat33(Vec3(row1[0], row1[1], row1[2]), 
                    Vec3(row2[0], row2[1], row2[2]), 
                    Vec3(row3[0], row3[1], row3[2]));
    
    M[1][0] = Mat33(Vec3(row0[1], row0[2], row0[3]), 
                    Vec3(row2[1], row2[2], row2[3]), 
                    Vec3(row3[1], row3[2], row3[3]));


    M[1][1] = Mat33(Vec3(row0[0], row0[2], row0[3]), 
                    Vec3(row2[0], row2[2], row2[3]), 
                    Vec3(row3[0], row3[2], row3[3]));

    M[1][2] = Mat33(Vec3(row0[0], row0[1], row0[3]), 
                    Vec3(row2[0], row2[1], row2[3]), 
                    Vec3(row3[0], row3[1], row3[3]));
    
    M[1][3] = Mat33(Vec3(row0[0], row0[1], row0[2]), 
                    Vec3(row2[0], row2[1], row2[2]), 
                    Vec3(row3[0], row3[1], row3[2]));


    M[2][0] = Mat33(Vec3(row0[1], row0[2], row0[3]), 
                    Vec3(row1[1], row1[2], row1[3]), 
                    Vec3(row3[1], row3[2], row3[3]));

    M[2][1] = Mat33(Vec3(row0[0], row0[2], row0[3]), 
                    Vec3(row1[0], row1[2], row1[3]), 
                    Vec3(row3[0], row3[2], row3[3]));
    
    M[2][2] = Mat33(Vec3(row0[0], row0[1], row0[3]), 
                    Vec3(row1[0], row1[1], row1[3]), 
                    Vec3(row3[0], row3[1], row3[3]));
    
    M[2][3] = Mat33(Vec3(row0[0], row0[1], row0[2]), 
                    Vec3(row1[0], row1[1], row1[2]), 
                    Vec3(row3[0], row3[1], row3[2]));
    
    M[3][0] = Mat33(Vec3(row0[1], row0[2], row0[3]), 
                    Vec3(row1[1], row1[2], row1[3]), 
                    Vec3(row2[1], row2[2], row2[3]));

    M[3][1] = Mat33(Vec3(row0[0], row0[2], row0[3]), 
                    Vec3(row1[0], row1[2], row1[3]), 
                    Vec3(row2[0], row2[2], row2[3]));
    
    M[3][2] = Mat33(Vec3(row0[0], row0[1], row0[3]), 
                    Vec3(row1[0], row1[1], row1[3]), 
                    Vec3(row2[0], row2[1], row2[3]));
    
    M[3][3] = Mat33(Vec3(row0[0], row0[1], row0[2]), 
                    Vec3(row1[0], row1[1], row1[2]), 
                    Vec3(row2[0], row2[1], row2[2]));

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            res.m[i][j] = pow(-1, i + j) * M[j][i].Determinant() / det;
        }
    }

    return res;
}
    
Vec4 Mat44::GetRow(const int row) const
{
    return Vec4(m[row][0], m[row][1], m[row][2], m[row][3]);
}

Vec4 Mat44::GetColumn(const int column) const
{
    return Vec4(m[0][column], m[1][column], m[2][column], m[3][column]);
}

double Mat44::GetElement(const int row, const int column) const
{
    return m[row][column];
}

Mat44 Mat44::IDENTITY = Mat44(1.0, 0.0, 0.0, 0.0,
                              0.0, 1.0, 0.0, 0.0,
                              0.0, 0.0, 1.0, 0.0,
                              0.0, 0.0, 0.0, 1.0);

Mat44 Mat44::ZERO = Mat44(0.0, 0.0, 0.0, 0.0,
                          0.0, 0.0, 0.0, 0.0,
                          0.0, 0.0, 0.0, 0.0,
                          0.0, 0.0, 0.0, 0.0);