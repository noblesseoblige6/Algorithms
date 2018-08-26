namespace acLib
{
    namespace arithmetic
    {
        template<typename T>
        Triangle<T>::Triangle()
            :Triangle<T>( vec3<T>::ZERO, vec3<T>::ZERO, vec3<T>::ZERO )
        {
        }

        template<typename T>
        Triangle<T>::Triangle( const vec3<T>& v0, const vec3<T>& v1, const vec3<T>& v2, Triangle::ORDER order )
            : order( order )
        {
            m_vertices[0] = v0;
            m_vertices[1] = v1;
            m_vertices[2] = v2;
        }


        template<typename T>
        vec3<T> Triangle<T>::GetNormal() const
        {
            return vec3<T>::normalize( vec3<T>::cross( v1 - v0, v2 - v1 ) );
        }

        template<typename T>
        double Triangle<T>::GetArea() const
        {
            return Vec3::cross( v1 - v0, v2 - v0 ).norm()*0.5;
        }

        /*template<typename T>
        vec3<T> Triangle<T>::SampleUniform( Random& random ) const
        {
            double u = random.next01(), v = u * random.next01();
            Vec res = v0 * u + v1 * v + (1.0 - u - v)*v2;

            return v0 * u + v1 * v + (1.0 - u - v)*v2;
        }

        template<typename T>
        vec3<T> Triangle<T>::SampleUniform( Random& random, Vec& n ) const
        {
            Vec pos = SampleUniform( random );
            n = GetNormal();

            return pos;
        }*/

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
    }
}
