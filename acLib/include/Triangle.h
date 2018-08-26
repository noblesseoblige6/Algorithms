#pragma once

namespace acLib
{
    namespace arithmetic
    {
        template<typename T>
        class Triangle
        {
        public:
            enum ORDER {
                CW = 0,
                CCW = 1
            };

            Triangle();

            Triangle( const vec3<T>& v0, const vec3<T>& v1, const vec3<T>& v2, Triangle::ORDER _order = CCW );

            vec3<T> GetNormal() const;

            double GetArea() const;

            //vec3<T> SampleUniform( Random& random ) const;

            //vec3<T> SampleUniform( Random& random, Vec& n ) const;

            //bool Intersect( const Ray& ray, HitPoint* hp ) const
            //{
            //    //@comment ray cast implemented by Moller-Trumbore
            //    //TODO: Check it works on the line of triangle
            //    //TODO: Check triangle order, for now only CCW works
            //    Vec d = ray.m_direction;
            //    Vec e1 = v1 - v0, e2 = v2 - v0, t = ray.m_position - v0;
            //    Vec p = Vec3::cross( d, e2 ), q = Vec3::cross( t, e1 );

            //    double det = Vec3::dot( p, e1 );
            //    if (det == 0.0)
            //    {
            //        return false;
            //    }

            //    double div = 1.0 / det;

            //    double s = div * Vec3::dot( q, e2 );

            //    //@comment direction is opposite
            //    if (s < 0.0)
            //    {
            //        return false;
            //    }

            //    double u = div * Vec3::dot( p, t );//Vec3::dot(Vec3::cross(d, t), e2);    //
            //    double v = div * Vec3::dot( q, d );//Vec3::dot(Vec3::cross(t, v2-v1), d); //

            //    double minErr = 0.0, maxErr = 1.0;

            //    if (u < minErr || u > maxErr)
            //    {
            //        return false;
            //    }

            //    if (v < minErr || v > maxErr)
            //    {
            //        return false;
            //    }

            //    if (u + v < minErr || u + v > maxErr)
            //    {
            //        return false;
            //    }

            //    //@comment intersection if the ray is on the edge or vertex
            //    hp->m_position = ray.m_position + s * d;
            //    hp->m_normal = Vec3::normalize( Vec3::cross( e1, e2 ) );
            //    hp->m_distance = s;

            //    //if (Vec3::dot(hp->normal, ray.m_position - hp->position) < 0) hp->normal = -hp->normal;

            //    return true;
            //}

            /*friend std::ostream& operator<<( std::ostream& os, const Triangle& t )
            {
                os << t.v0[0] << " " << t.v0[1] << " " << t.v0[2] << std::endl;
                os << t.v1[0] << " " << t.v1[1] << " " << t.v1[2] << std::endl;
                os << t.v2[0] << " " << t.v2[1] << " " << t.v2[2] << std::endl;

                return os;
            }*/

        public:
            vec3<T>& operator[](int index ) const { return m_vertices[index]; }
            //const vec3<T>& operator[]( int index ) const { return m_vertices[index]; }

        private:
            vec3<T> m_vertices[3];
            //box<T> m_boundingBox;

            ORDER order;
        };
    }
}

typedef acLib::arithmetic::Triangle<float> TriangleF; 
typedef acLib::arithmetic::Triangle<double> TriangleD;