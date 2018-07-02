#pragma once
#include <iostream>
#include <cmath>

namespace acLib
{
    namespace vec
    {
        struct Vec2;
        struct Vec3;
        struct Vec4;
    }

    namespace mat
    {
        using namespace std;
        using namespace acLib::vec;

        struct Mat33
        {
        public:
            static Mat33 IDENTITY;
            static Mat33 ZERO;

            Mat33();
            Mat33(const double* row0, const double* row1, const double* row2);
            Mat33(const Vec3& row0, const Vec3& row1, const Vec3& row2);
            Mat33(double m00, double m01, double m02,
                double m10, double m11, double m12,
                double m20, double m21, double m22);
            Mat33(const Mat33& mat);
            ~Mat33();

            Mat33 operator+(const double& v) const;
            Mat33 operator+(const Mat33& mat) const;
            Mat33 operator-(const double& v) const;
            Mat33 operator-(const Mat33& mat) const;
            Mat33 operator*(const double s) const;
            Mat33 operator/(const double s) const;

            const Mat33& operator=(const Mat33& mat);

            bool operator==(const Mat33& mat) const;
            bool operator!=(const Mat33& mat) const;

            Mat33 operator-() const;

            double Determinant() const;
            Mat33 Inverse();

            Vec3 GetRow(const int row) const;
            Vec3 GetColumn(const int column) const;
            double GetElement(const int row, const int column) const;

            friend Mat33 operator+ (const double s, const Mat33& mat)
            {
                Mat33 res(mat);
                res = res + s;
                return res;
            }

            friend Mat33 operator- (const double s, const Mat33& mat)
            {
                Mat33 res(mat);
                res = res - s;
                return res;
            }

            friend Mat33 operator* (const double s, const Mat33& mat)
            {
                Mat33 res(mat);
                res = res * s;
                return res;
            }

            friend ostream& operator<<(ostream& os, const Mat33& mat)
            {
                os << mat.m[0][0] << " " << mat.m[0][1] << " " << mat.m[0][2] << endl;
                os << mat.m[1][0] << " " << mat.m[1][1] << " " << mat.m[1][2] << endl;
                os << mat.m[2][0] << " " << mat.m[2][1] << " " << mat.m[2][2] << endl;

                return os;
            }
        public:
            double m[3][3];
        };

        struct Mat44
        {
        public:
            static Mat44 IDENTITY;
            static Mat44 ZERO;
        public:
            static Mat44 CreateLookAt( const Vec3& eye, const Vec3& lookAt, const Vec3& up );
            static Mat44 CreatePerspectiveFieldOfView( const double radian, const double aspect, const double near, const double far );

        public:
            Mat44();
            Mat44(const double* row0, const double* row1, const double* row2, const double* row3);
            Mat44(const Vec4& row0, const Vec4& row1, const Vec4& row2, const Vec4& row3);
            Mat44(double m00, double m01, double m02, double m03,
                  double m10, double m11, double m12, double m13,
                  double m20, double m21, double m22, double m23,
                  double m30, double m31, double m32, double m33);
            Mat44(const Mat44& mat);
            ~Mat44();

            Mat44 operator+(const double& v) const;
            Mat44 operator+(const Mat44& mat) const;
            Mat44 operator-(const double& v) const;
            Mat44 operator-(const Mat44& mat) const;
            Mat44 operator*(const double s) const;
            Mat44 operator/(const double s) const;

            const Mat44& operator=(const Mat44& mat);

            bool operator==(const Mat44& mat) const;
            bool operator!=(const Mat44& mat) const;

            Mat44 operator-() const;

            double Determinant() const;
            Mat44 Inverse();

            Vec4 GetRow(const int row) const;
            Vec4 GetColumn(const int column) const;
            double GetElement(const int row, const int column) const;

            friend Mat44 operator+ (const double s, const Mat44& mat)
            {
                Mat44 res(mat);
                res = res + s;
                return res;
            }

            friend Mat44 operator- (const double s, const Mat44& mat)
            {
                Mat44 res(mat);
                res = res - s;
                return res;
            }

            friend Mat44 operator* (const double s, const Mat44& mat)
            {
                Mat44 res(mat);
                res = res * s;
                return res;
            }

            friend ostream& operator<<(ostream& os, const Mat44& mat)
            {
                os << mat.m[0][0] << " " << mat.m[0][1] << " " << mat.m[0][2] << " " << mat.m[0][3] << endl;
                os << mat.m[1][0] << " " << mat.m[1][1] << " " << mat.m[1][2] << " " << mat.m[1][3] << endl;
                os << mat.m[2][0] << " " << mat.m[2][1] << " " << mat.m[2][2] << " " << mat.m[2][3] << endl;
                os << mat.m[3][0] << " " << mat.m[3][1] << " " << mat.m[3][2] << " " << mat.m[3][3] << endl;

                return os;
            }
        public:
            double m[4][4];
        };
    }
}
