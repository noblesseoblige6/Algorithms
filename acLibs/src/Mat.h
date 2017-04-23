#pragma once
#include <iostream>
#include <cmath>

namespace acLib
{
  namespace mat
  {
    using namespace std;

    struct Mat33
    {
      public:
          static Mat33 IDENTITY;
          static Mat33 ZERO;

          Mat33()
          {
          *this = Mat33::IDENTITY;
          }
          Mat33(const double* row0, const double* row1, const double* row2)
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
        Mat33(double m00, double m01, double m02,
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
        Mat33(const Mat33& mat)
        {
            *this = mat;
        }
        ~Mat33()
        {}

        const Mat33& operator=(const Mat33& mat)
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

        Mat33 operator+(const double& v) const
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

        Mat33 operator+(const Mat33& mat) const
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

        Mat33 operator-(const double& v) const
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

        Mat33 operator-(const Mat33& mat) const
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

        Mat33 operator*(const double s) const
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

        Mat33 operator/(const double s) const
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

        bool operator==(const Mat33& mat) const
        {
          return (m[0][0] == mat.m[0][0] && m[0][1] == mat.m[0][1] && m[0][2] == mat.m[0][2]) && 
                 (m[1][0] == mat.m[1][0] && m[1][1] == mat.m[1][1] && m[1][2] == mat.m[1][2]) &&
                 (m[2][0] == mat.m[2][0] && m[2][1] == mat.m[2][1] && m[2][2] == mat.m[2][2]);
        }

        Mat33 operator-() const
        {
            Mat33 res(*this);
            res = -1.0 * res;
            return res;
        }

        friend ostream& operator<<(ostream& os, const Mat33& mat)
        {
            os << mat.m[0][0] << " " << mat.m[0][1] << " " << mat.m[0][2] << endl;
            os << mat.m[1][0] << " " << mat.m[1][1] << " " << mat.m[1][2] << endl;
            os << mat.m[2][0] << " " << mat.m[2][1] << " " << mat.m[2][2] << endl;

          return os;
        }

        double Determinant()
        {
        double det = m[0][0] * m[1][1] * m[2][2]
                   + m[1][0] * m[2][1] * m[0][2]
                   + m[2][0] * m[0][1] * m[1][2]
                   - m[0][0] * m[2][1] * m[1][2]
                   - m[2][0] * m[1][1] * m[0][2]
                   - m[1][0] * m[0][1] * m[2][2];

            return det;
        }

        Mat33 Inverse()
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

      public:
        double m[3][3];
    };

    Mat33 Mat33::IDENTITY = Mat33(1.0, 0.0, 0.0,
                                  0.0, 1.0, 0.0,
                                  0.0, 0.0, 1.0);

    Mat33 Mat33::ZERO = Mat33(0.0, 0.0, 0.0,
                              0.0, 0.0, 0.0,
                              0.0, 0.0, 0.0);
  }
}
