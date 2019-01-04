#pragma once

namespace acLib
{
    using namespace std;
    using namespace vec;

    namespace mat
    {
        template<typename T>
        struct mat33
        {
        public:
            static mat33 IDENTITY;
            static mat33 ZERO;

            mat33();
            mat33(const T* row0, const T* row1, const T* row2);
            mat33(const vec3<T>& row0, const vec3<T>& row1, const vec3<T>& row2);
            mat33(T m00, T m01, T m02,
                  T m10, T m11, T m12,
                  T m20, T m21, T m22);
            mat33(const mat33& mat);
            ~mat33();

            mat33 operator+(const T& v) const;
            mat33 operator+(const mat33& mat) const;
            mat33 operator-(const T& v) const;
            mat33 operator-(const mat33& mat) const;
            mat33 operator*( const T s ) const;
            mat33 operator*( const mat33& mat ) const;
            vec3<T> operator*(const vec3<T>& s) const;
            mat33 operator/(const T s) const;

            const mat33& operator=(const mat33& mat);

            bool operator==(const mat33& mat) const;
            bool operator!=(const mat33& mat) const;

            mat33 operator-() const;

            T Determinant() const;
            mat33 Inverse();

            void Transform( vec3<T>& vec );

            vec3<T> GetRow(const int row) const;
            vec3<T> GetColumn(const int column) const;
            T GetElement(const int row, const int column) const;

            friend mat33 operator+ (const T s, const mat33& mat)
            {
                mat33 res(mat);
                res = res + s;
                return res;
            }

            friend mat33 operator- (const T s, const mat33& mat)
            {
                mat33 res(mat);
                res = res - s;
                return res;
            }

            friend mat33 operator* (const T s, const mat33& mat)
            {
                mat33 res(mat);
                res = res * s;
                return res;
            }

            friend ostream& operator<<(ostream& os, const mat33& mat)
            {
                os << mat.m[0][0] << " " << mat.m[0][1] << " " << mat.m[0][2] << endl;
                os << mat.m[1][0] << " " << mat.m[1][1] << " " << mat.m[1][2] << endl;
                os << mat.m[2][0] << " " << mat.m[2][1] << " " << mat.m[2][2] << endl;

                return os;
            }

        public:
            T m[3][3];
        };

        template<typename T>
        struct mat44
        {
        public:
            static mat44 IDENTITY;
            static mat44 ZERO;

        public:
            static mat44  CreateLookAt( const vec3<T>& eye, const vec3<T>& lookAt, const vec3<T>& up );
            static mat44  CreatePerspectiveFieldOfViewRH( const T radian, const T aspect, const T near, const T far );
            static mat44  CreatePerspectiveFieldOfViewLH( const T radian, const T aspect, const T near, const T far );

        public:
            mat44();
            mat44(const T* row0, const T* row1, const T* row2, const T* row3);
            mat44(const vec4<T>& row0, const vec4<T>& row1, const vec4<T>& row2, const vec4<T>& row3);
            mat44(T m00, T m01, T m02, T m03,
                  T m10, T m11, T m12, T m13,
                  T m20, T m21, T m22, T m23,
                  T m30, T m31, T m32, T m33);
            mat44(const mat44& mat);
            mat44( const mat33<T>& mat, const vec3<T>& p );
            ~mat44();

            void Scale( const vec3<T>& scaler );
            void Translate( const vec3<T>& translate );

            void Move( const vec3<T>& vec );

            mat44 operator+(const T& v) const;
            mat44 operator+(const mat44& mat) const;
            mat44 operator-(const T& v) const;
            mat44 operator-(const mat44& mat) const;
            mat44 operator*(const T s) const;
            mat44 operator*( const mat44& mat ) const;
            vec4<T> operator*(const vec4<T>& v) const;
            mat44 operator/(const T s) const;

            const mat44& operator=(const mat44& mat);

            bool operator==(const mat44& mat) const;
            bool operator!=(const mat44& mat) const;

            mat44 operator-() const;

            T Determinant() const;
            mat44 Inverse();

            void Transform(vec4<T>& vec);

            vec4<T> GetRow(const int row) const;
            vec4<T> GetColumn(const int column) const;
            T GetElement(const int row, const int column) const;

            vec3<T>  GetPosition() const;
            mat33<T> GetScaleAndRoation() const;

            friend mat44 operator+ (const T s, const mat44& mat)
            {
                mat44 res(mat);
                res = res + s;
                return res;
            }

            friend mat44 operator- (const T s, const mat44& mat)
            {
                mat44 res(mat);
                res = res - s;
                return res;
            }

            friend mat44 operator* (const T s, const mat44& mat)
            {
                mat44 res(mat);
                res = res * s;
                return res;
            }

            friend ostream& operator<<(ostream& os, const mat44& mat)
            {
                os << mat.m[0][0] << " " << mat.m[0][1] << " " << mat.m[0][2] << " " << mat.m[0][3] << endl;
                os << mat.m[1][0] << " " << mat.m[1][1] << " " << mat.m[1][2] << " " << mat.m[1][3] << endl;
                os << mat.m[2][0] << " " << mat.m[2][1] << " " << mat.m[2][2] << " " << mat.m[2][3] << endl;
                os << mat.m[3][0] << " " << mat.m[3][1] << " " << mat.m[3][2] << " " << mat.m[3][3] << endl;

                return os;
            }

        public:
            T m[4][4];
        };
    }
}

typedef acLib::mat::mat33<int>  Mat33i;
typedef acLib::mat::mat33<float>  Mat33f;
typedef acLib::mat::mat33<double> Mat33d;
typedef acLib::mat::mat33<double> Mat33;

typedef acLib::mat::mat44<int>  Mat44i;
typedef acLib::mat::mat44<float>  Mat44f;
typedef acLib::mat::mat44<double> Mat44d;
typedef acLib::mat::mat44<double> Mat44;
