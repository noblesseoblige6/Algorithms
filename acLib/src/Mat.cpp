namespace acLib
{
    using namespace vec;

    namespace mat
    {

        template<typename T>
        mat33<T>::mat33()
        {
            *this = mat33<T>::IDENTITY;
        }

        template<typename T>
        mat33<T>::mat33( const T* row0, const T* row1, const T* row2 )
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

        template<typename T>
        mat33<T>::mat33( const vec3<T>& row0, const vec3<T>& row1, const vec3<T>& row2 )
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

        template<typename T>
        mat33<T>::mat33( T m00, T m01, T m02,
            T m10, T m11, T m12,
            T m20, T m21, T m22 )
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

        template<typename T>
        mat33<T>::mat33( const mat33<T>& mat )
        {
            *this = mat;
        }

        template<typename T>
        mat33<T>::~mat33()
        {
        }

        template<typename T>
        const mat33<T>& mat33<T>::operator=( const mat33<T>& mat )
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

        template<typename T>
        mat33<T> mat33<T>::operator+( const T& v ) const
        {
            mat33 res;
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

        template<typename T>
        mat33<T> mat33<T>::operator+( const mat33<T>& mat ) const
        {
            mat33 res;
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

        template<typename T>
        mat33<T> mat33<T>::operator-( const T& v ) const
        {
            mat33 res;
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

        template<typename T>
        mat33<T> mat33<T>::operator-( const mat33<T>& mat ) const
        {
            mat33 res;
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

        template<typename T>
        mat33<T> mat33<T>::operator*( const T s ) const
        {
            mat33 res;
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

        template<typename T>
        mat33<T> mat33<T>::operator*( const mat33& mat ) const
        {
            mat33<T> res;
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    res.m[i][j] = vec3<T>::dot( GetRow( i ), mat.GetColumn( j ) );

            return res;
        }

        template<typename T>
        vec3<T> mat33<T>::operator*( const vec3<T>& v ) const
        {
            vec3<T> res;

            res.x = vec3<T>::dot( vec3<T>( m[0][0], m[0][1], m[0][2] ), v );
            res.y = vec3<T>::dot( vec3<T>( m[1][0], m[1][1], m[1][2] ), v );
            res.z = vec3<T>::dot( vec3<T>( m[2][0], m[2][1], m[2][2] ), v );

            return res;
        }

        template<typename T>
        mat33<T> mat33<T>::operator/( const T s ) const
        {
            mat33 res;
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

        template<typename T>
        bool mat33<T>::operator==( const mat33<T>& mat ) const
        {
            return (m[0][0] == mat.m[0][0] && m[0][1] == mat.m[0][1] && m[0][2] == mat.m[0][2]) &&
                   (m[1][0] == mat.m[1][0] && m[1][1] == mat.m[1][1] && m[1][2] == mat.m[1][2]) &&
                   (m[2][0] == mat.m[2][0] && m[2][1] == mat.m[2][1] && m[2][2] == mat.m[2][2]);
        }

        template<typename T>
        bool mat33<T>::operator!=( const mat33<T>& mat ) const
        {
            return !(*this == mat);
        }

        template<typename T>
        mat33<T> mat33<T>::operator-() const
        {
            mat33 res( *this );
            res = -1 * res;
            return res;
        }

        template<typename T>
        T mat33<T>::Determinant() const
        {
            T det = m[0][0] * m[1][1] * m[2][2]
                + m[0][1] * m[1][2] * m[2][0]
                + m[0][2] * m[1][0] * m[2][1]
                - m[0][2] * m[1][1] * m[2][0]
                - m[0][1] * m[1][0] * m[2][2]
                - m[0][0] * m[1][2] * m[2][1];

            return det;
        }

        template<typename T>
        mat33<T> mat33<T>::Inverse()
        {
            mat33 res;

            T det = Determinant();
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

        template<typename T>
        void mat33<T>::Transform( vec3<T>& vec )
        {
            vec = vec3<T>( vec3<T>::dot( GetRow( 0 ), vec ),
                           vec3<T>::dot( GetRow( 1 ), vec ),
                           vec3<T>::dot( GetRow( 2 ), vec ) );
        }

        template<typename T>
        vec3<T> mat33<T>::GetRow( const int row ) const
        {
            return vec3<T>( m[row][0], m[row][1], m[row][2] );
        }

        template<typename T>
        vec3<T> mat33<T>::GetColumn( const int column ) const
        {
            return vec3<T>( m[0][column], m[1][column], m[2][column] );
        }

        template<typename T>
        T mat33<T>::GetElement( const int row, const int column ) const
        {
            return m[row][column];
        }

        mat33<int> mat33<int>::IDENTITY = mat33( 1, 0, 0,
                                                 0, 1, 0,
                                                 0, 0, 1 );
        mat33<int> mat33<int>::ZERO = mat33( 0, 0, 0,
                                             0, 0, 0,
                                             0, 0, 0 );

        template<typename T>
        mat33<T> mat33<T>::IDENTITY = mat33( 1.0, 0.0, 0.0,
            0.0, 1.0, 0.0,
            0.0, 0.0, 1.0 );

        template<typename T>
        mat33<T> mat33<T>::ZERO = mat33( 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0,
            0.0, 0.0, 0.0 );

        template mat33<int>;
        template mat33<float>;
        template mat33<double>;

        template<typename T>
        mat44<T>::mat44()
        {
            *this = mat44<T>::IDENTITY;
        }

        template<typename T>
        mat44<T>::mat44( const T* row0, const T* row1, const T* row2, const T* row3 )
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

        template<typename T>
        mat44<T>::mat44( const vec4<T>& row0, const vec4<T>& row1, const vec4<T>& row2, const vec4<T>& row3 )
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

        template<typename T>
        mat44<T>::mat44( T m00, T m01, T m02, T m03,
            T m10, T m11, T m12, T m13,
            T m20, T m21, T m22, T m23,
            T m30, T m31, T m32, T m33 )
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

        template<typename T>
        mat44<T>::mat44( const mat44<T>& mat )
        {
            *this = mat;
        }

        template<typename T>
        mat44<T>::mat44( const mat33<T>& mat, const vec3<T>& p )
        {
            m[0][0] = mat.GetElement( 0, 0 );
            m[0][1] = mat.GetElement( 0, 1 );
            m[0][2] = mat.GetElement( 0, 2 );
            m[0][3] = static_cast<T>(0);

            m[1][0] = mat.GetElement( 1, 0 );
            m[1][1] = mat.GetElement( 1, 1 );
            m[1][2] = mat.GetElement( 1, 2 );
            m[1][3] = static_cast<T>(0);

            m[2][0] = mat.GetElement( 2, 0 );
            m[2][1] = mat.GetElement( 2, 1 );
            m[2][2] = mat.GetElement( 2, 2 );
            m[2][3] = static_cast<T>(0);

            m[3][0] = p.x;
            m[3][1] = p.y;
            m[3][2] = p.z;
            m[3][3] = static_cast<T>(1);
        }

        template<typename T>
        mat44<T>::~mat44()
        {
        }

        template<typename T>
        const mat44<T>& mat44<T>::operator=( const mat44<T>& mat )
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

        template<typename T>
        mat44<T> mat44<T>::operator+( const T& v ) const
        {
            mat44<T> res;
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

        template<typename T>
        mat44<T> mat44<T>::operator+( const mat44<T>& mat ) const
        {
            mat44<T> res;
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

        template<typename T>
        mat44<T> mat44<T>::operator-( const T& v ) const
        {
            mat44<T> res;
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

        template<typename T>
        mat44<T> mat44<T>::operator-( const mat44<T>& mat ) const
        {
            mat44<T> res;
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

        template<typename T>
        mat44<T> mat44<T>::operator*( const T s ) const
        {
            mat44<T> res;
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

        template<typename T>
        mat44<T> mat44<T>::operator*( const mat44& mat ) const
        {
            mat44<T> res;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    res.m[i][j] = vec4<T>::dot( GetRow( i ), mat.GetColumn( j ) );

            return res;
        }

        template<typename T>
        vec4<T> mat44<T>::operator*( const vec4<T>& v ) const
        {
            vec4<T> res;

            res.x = vec4<T>::dot( vec4<T>( m[0][0], m[0][1], m[0][2], m[0][3] ), v );
            res.y = vec4<T>::dot( vec4<T>( m[1][0], m[1][1], m[1][2], m[1][3] ), v );
            res.z = vec4<T>::dot( vec4<T>( m[2][0], m[2][1], m[2][2], m[2][3] ), v );
            res.w = vec4<T>::dot( vec4<T>( m[3][0], m[3][1], m[3][2], m[3][3] ), v );

            return res;
        }

        template<typename T>
        mat44<T> mat44<T>::operator/( const T s ) const
        {
            mat44<T> res;
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

        template<typename T>
        bool mat44<T>::operator==( const mat44<T>& mat ) const
        {
            return (m[0][0] == mat.m[0][0] && m[0][1] == mat.m[0][1] && m[0][2] == mat.m[0][2] && m[0][3] == mat.m[0][3]) &&
                   (m[1][0] == mat.m[1][0] && m[1][1] == mat.m[1][1] && m[1][2] == mat.m[1][2] && m[1][3] == mat.m[1][3]) &&
                   (m[2][0] == mat.m[2][0] && m[2][1] == mat.m[2][1] && m[2][2] == mat.m[2][2] && m[2][3] == mat.m[2][3]) &&
                   (m[3][0] == mat.m[3][0] && m[3][1] == mat.m[3][1] && m[3][2] == mat.m[3][2] && m[3][3] == mat.m[3][3]);
        }

        template<typename T>
        bool mat44<T>::operator!=( const mat44<T>& mat ) const
        {
            return !(*this == mat);
        }

        template<typename T>
        mat44<T> mat44<T>::operator-() const
        {
            mat44<T> res( *this );
            res = -1 * res;
            return res;
        }

        template<typename T>
        T mat44<T>::Determinant() const
        {
            const vec4<T>& row0 = GetRow( 0 );
            const vec4<T>& row1 = GetRow( 1 );
            const vec4<T>& row2 = GetRow( 2 );
            const vec4<T>& row3 = GetRow( 3 );

            const mat33<T> A0( vec3<T>( row1[1], row1[2], row1[3] ),
                               vec3<T>( row2[1], row2[2], row2[3] ),
                               vec3<T>( row3[1], row3[2], row3[3] ) );

            const mat33<T> A1( vec3<T>( row0[1], row0[2], row0[3] ),
                            vec3<T>( row2[1], row2[2], row2[3] ),
                            vec3<T>( row3[1], row3[2], row3[3] ) );

            const mat33<T> A2( vec3<T>( row0[1], row0[2], row0[3] ),
                            vec3<T>( row1[1], row1[2], row1[3] ),
                            vec3<T>( row3[1], row3[2], row3[3] ) );

            const mat33<T> A3( vec3<T>( row0[1], row0[2], row0[3] ),
                            vec3<T>( row1[1], row1[2], row1[3] ),
                            vec3<T>( row2[1], row2[2], row2[3] ) );

            return m[0][0] * A0.Determinant() - m[1][0] * A1.Determinant() + m[2][0] * A2.Determinant() - m[3][0] * A3.Determinant();
        }

        template<typename T>
        mat44<T> mat44<T>::Inverse()
        {
            mat44<T> res;

            T det = Determinant();
            if (det == 0.0)
            {
                cerr << "Waring: No Inverse Matrix" << endl;
                return res;
            }

            const vec4<T>& row0 = GetRow( 0 );
            const vec4<T>& row1 = GetRow( 1 );
            const vec4<T>& row2 = GetRow( 2 );
            const vec4<T>& row3 = GetRow( 3 );

            mat33<T> M[4][4];
            M[0][0] = mat33<T>( vec3<T>( row1[1], row1[2], row1[3] ),
                             vec3<T>( row2[1], row2[2], row2[3] ),
                             vec3<T>( row3[1], row3[2], row3[3] ) );

            M[0][1] = mat33<T>( vec3<T>( row1[0], row1[2], row1[3] ),
                             vec3<T>( row2[0], row2[2], row2[3] ),
                             vec3<T>( row3[0], row3[2], row3[3] ) );

            M[0][2] = mat33<T>( vec3<T>( row1[0], row1[1], row1[3] ),
                             vec3<T>( row2[0], row2[1], row2[3] ),
                             vec3<T>( row3[0], row3[1], row3[3] ) );

            M[0][3] = mat33<T>( vec3<T>( row1[0], row1[1], row1[2] ),
                             vec3<T>( row2[0], row2[1], row2[2] ),
                             vec3<T>( row3[0], row3[1], row3[2] ) );

            M[1][0] = mat33<T>( vec3<T>( row0[1], row0[2], row0[3] ),
                             vec3<T>( row2[1], row2[2], row2[3] ),
                             vec3<T>( row3[1], row3[2], row3[3] ) );


            M[1][1] = mat33<T>( vec3<T>( row0[0], row0[2], row0[3] ),
                             vec3<T>( row2[0], row2[2], row2[3] ),
                             vec3<T>( row3[0], row3[2], row3[3] ) );

            M[1][2] = mat33<T>( vec3<T>( row0[0], row0[1], row0[3] ),
                             vec3<T>( row2[0], row2[1], row2[3] ),
                             vec3<T>( row3[0], row3[1], row3[3] ) );

            M[1][3] = mat33<T>( vec3<T>( row0[0], row0[1], row0[2] ),
                             vec3<T>( row2[0], row2[1], row2[2] ),
                             vec3<T>( row3[0], row3[1], row3[2] ) );


            M[2][0] = mat33<T>( vec3<T>( row0[1], row0[2], row0[3] ),
                             vec3<T>( row1[1], row1[2], row1[3] ),
                             vec3<T>( row3[1], row3[2], row3[3] ) );

            M[2][1] = mat33<T>( vec3<T>( row0[0], row0[2], row0[3] ),
                             vec3<T>( row1[0], row1[2], row1[3] ),
                             vec3<T>( row3[0], row3[2], row3[3] ) );

            M[2][2] = mat33<T>( vec3<T>( row0[0], row0[1], row0[3] ),
                vec3<T>( row1[0], row1[1], row1[3] ),
                vec3<T>( row3[0], row3[1], row3[3] ) );

            M[2][3] = mat33<T>( vec3<T>( row0[0], row0[1], row0[2] ),
                vec3<T>( row1[0], row1[1], row1[2] ),
                vec3<T>( row3[0], row3[1], row3[2] ) );

            M[3][0] = mat33<T>( vec3<T>( row0[1], row0[2], row0[3] ),
                vec3<T>( row1[1], row1[2], row1[3] ),
                vec3<T>( row2[1], row2[2], row2[3] ) );

            M[3][1] = mat33<T>( vec3<T>( row0[0], row0[2], row0[3] ),
                vec3<T>( row1[0], row1[2], row1[3] ),
                vec3<T>( row2[0], row2[2], row2[3] ) );

            M[3][2] = mat33<T>( vec3<T>( row0[0], row0[1], row0[3] ),
                vec3<T>( row1[0], row1[1], row1[3] ),
                vec3<T>( row2[0], row2[1], row2[3] ) );

            M[3][3] = mat33<T>( vec3<T>( row0[0], row0[1], row0[2] ),
                vec3<T>( row1[0], row1[1], row1[2] ),
                vec3<T>( row2[0], row2[1], row2[2] ) );

            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    res.m[i][j] = static_cast<T>(pow( -1, i + j ) * M[j][i].Determinant() / det);
                }
            }

            return res;
        }

        template<typename T>
        void mat44<T>::Transform( vec4<T>& vec )
        {
            vec = vec4<T>( vec4<T>::dot( GetRow( 0 ), vec ),
                           vec4<T>::dot( GetRow( 1 ), vec ),
                           vec4<T>::dot( GetRow( 2 ), vec ),
                           vec4<T>::dot( GetRow( 3 ), vec ) );
        }

        template<typename T>
        vec4<T> mat44<T>::GetRow( const int row ) const
        {
            return vec4<T>( m[row][0], m[row][1], m[row][2], m[row][3] );
        }

        template<typename T>
        vec4<T> mat44<T>::GetColumn( const int column ) const
        {
            return vec4<T>( m[0][column], m[1][column], m[2][column], m[3][column] );
        }

        template<typename T>
        T mat44<T>::GetElement( const int row, const int column ) const
        {
            return m[row][column];
        }

        template<typename T>
        vec3<T> mat44<T>::GetPosition() const
        {
            vec3<T> pos( m[3][0], m[3][1], m[3][2] );
            return pos;
        }

        template<typename T>
        mat33<T> mat44<T>::GetScaleAndRoation() const
        {
            mat33<T> res = mat33<T>( GetElement( 0, 0 ), GetElement( 0, 1 ), GetElement( 0, 2 ),
                                     GetElement( 1, 0 ), GetElement( 1, 1 ), GetElement( 1, 2 ),
                                     GetElement( 2, 0 ), GetElement( 2, 1 ), GetElement( 2, 2 ) );
            return res;
        }

        template<typename T>
        mat44<T> mat44<T>::CreateLookAt( const vec3<T>& eye, const vec3<T>& lookAt, const vec3<T>& up )
        {
            vec3<T> x, y, z;

            z = lookAt - eye;
            x = vec3<T>::cross( up, z );
            y = vec3<T>::cross( z, x );

            x = x.normalized();
            y = y.normalized();
            z = z.normalized();

            T tx, ty, tz;
            tx = -vec3<T>::dot( eye, x );
            ty = -vec3<T>::dot( eye, y );
            tz = -vec3<T>::dot( eye, z );

            mat44<T> mat = mat44<T>::IDENTITY;

            mat.m[0][0] = x.x;  mat.m[0][1] = y.x;  mat.m[0][2] = z.x;
            mat.m[1][0] = x.y;  mat.m[1][1] = y.y;  mat.m[1][2] = z.y;
            mat.m[2][0] = x.z;  mat.m[2][1] = y.z;  mat.m[2][2] = z.z;
            mat.m[3][0] = tx;   mat.m[3][1] = ty;   mat.m[3][2] = tz;

            return mat;
        }

        template<typename T>
        mat44<T> mat44<T>::CreateOrthoRH( const T left, const T right, const T bottom, const T top, const T near, const T far )
        {
            mat44<T> mat = mat44<T>::IDENTITY;

            T w = right - left;
            T h = top - bottom;
            T d = near - far;

            mat.m[0][0] = static_cast<T>(2.0 / w);

            mat.m[1][1] = static_cast<T>(2.0 / h);

            mat.m[2][2] = static_cast<T>(-1.0 / d);

            mat.m[3][0] = static_cast<T>(-(right + left) / w);
            mat.m[3][1] = static_cast<T>(-(top + bottom) / h);
            mat.m[3][2] = static_cast<T>(near / d);

            return mat;
        }

        template<typename T>
        mat44<T> mat44<T>::CreateOrthoLH( const T left, const T right, const T bottom, const T top, const T near, const T far )
        {
            mat44<T> mat = mat44<T>::IDENTITY;

            T w = right - left;
            T h = top - bottom;
            T d = far - near;

            mat.m[0][0] = static_cast<T>(2.0 / w);

            mat.m[1][1] = static_cast<T>(2.0 / h);

            mat.m[2][2] = static_cast<T>(1.0 / d);

            mat.m[3][0] = static_cast<T>(-(right+left) / w);
            mat.m[3][1] = static_cast<T>(-(top+bottom) / h);
            mat.m[3][2] = static_cast<T>(-near / d);

            return mat;
        }

        template<typename T>
        mat44<T> mat44<T>::CreatePerspectiveRH( const T left, const T right, const T bottom, const T top, const T near, const T far )
        {
            mat44<T> mat = mat44<T>::IDENTITY;

            T w = right - left;
            T h = top - bottom;
            T d = far - near;

            mat.m[0][0] = static_cast<T>((2 * near) / w);

            mat.m[1][1] = static_cast<T>((2 * near) / h);

            mat.m[2][2] = -far / d;
            mat.m[2][3] = static_cast<T>(-1);

            mat.m[3][3] = static_cast<T>(0);
            mat.m[3][2] = -(near*far) / d;

            return mat;
        }

        template<typename T>
        mat44<T> mat44<T>::CreatePerspectiveLH( const T left, const T right, const T bottom, const T top, const T near, const T far )
        {
            mat44<T> mat = mat44<T>::IDENTITY;

            T w = right - left;
            T h = top - bottom;
            T d = far - near;

            mat.m[0][0] = static_cast<T>((2 * near) / w);

            mat.m[1][1] = static_cast<T>((2 * near) / h);

            mat.m[2][2] = far / d;
            mat.m[2][3] = static_cast<T>(1);

            mat.m[3][3] = static_cast<T>(0);
            mat.m[3][2] = -(near*far) / d;

            return mat;
        }

        template<typename T>
        mat44<T> mat44<T>::CreatePerspectiveFieldOfViewRH( const T radian, const T aspect, const T near, const T far )
        {
            mat44<T> mat = mat44<T>::IDENTITY;

            const T t   = static_cast<T>(1.0 / tan( radian*0.5 ));
            const T dis = static_cast<T>(far - near);

            mat.m[0][0] = aspect * t;

            mat.m[1][1] = t;

            mat.m[2][2] = -far / dis;
            mat.m[2][3] = static_cast<T>(-1);

            mat.m[3][3] = static_cast<T>(0);
            mat.m[3][2] = -(near*far) / dis;

            return mat;
        }

        template<typename T>
        mat44<T> mat44<T>::CreatePerspectiveFieldOfViewLH( const T radian, const T aspect, const T near, const T far )
        {
            mat44<T> mat = mat44<T>::IDENTITY;

            const T f   = static_cast<T>(1.0 / tan( radian*0.5 ));
            const T dis = static_cast<T>(far - near);

            T w = (2*far*aspect) / f;
            T h = (2 * far) / f;

            mat.m[0][0] = static_cast<T>(f / aspect);

            mat.m[1][1] = f;

            mat.m[2][2] = far / dis;
            mat.m[2][3] = static_cast<T>(1);

            mat.m[3][3] = static_cast<T>(0);
            mat.m[3][2] = -(near*far) / dis;

            return mat;
        }

        template<typename T>
        void mat44<T>::Scale( const vec3<T>& scaler )
        {
            m[0][0] = scaler[0];
            m[1][1] = scaler[1];
            m[2][2] = scaler[2];
        }

        template<typename T>
        void mat44<T>::Translate( const vec3<T>& translate )
        {
            m[3][0] = translate[0];
            m[3][1] = translate[1];
            m[3][2] = translate[2];
        }

        template<typename T>
        void mat44<T>::Move( const vec3<T>& vec )
        {
            m[3][0] += vec[0];
            m[3][1] += vec[1];
            m[3][2] += vec[2];
        }

        mat44<int> mat44<int>::IDENTITY = mat44( 1, 0, 0, 0,
                                                 0, 1, 0, 0,
                                                 0, 0, 1, 0,
                                                 0, 0, 0, 1 );

        mat44<int> mat44<int>::ZERO = mat44( 0, 0, 0, 0,
                                             0, 0, 0, 0,
                                             0, 0, 0, 0,
                                             0, 0, 0, 0 );

        template<typename T>
        mat44<T> mat44<T>::IDENTITY = mat44( 1.0, 0.0, 0.0, 0.0,
                                             0.0, 1.0, 0.0, 0.0,
                                             0.0, 0.0, 1.0, 0.0,
                                             0.0, 0.0, 0.0, 1.0 );

        template<typename T>
        mat44<T> mat44<T>::ZERO = mat44( 0.0, 0.0, 0.0, 0.0,
                                         0.0, 0.0, 0.0, 0.0,
                                         0.0, 0.0, 0.0, 0.0,
                                         0.0, 0.0, 0.0, 0.0 );

        template mat44<int>;
        template mat44<float>;
        template mat44<double>;
    }
}