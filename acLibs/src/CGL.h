#pragma once
#include "Vec.h"
#include "Constant.h"

namespace acLib
{
    namespace cgl
    {
        using namespace acLib::vec;
        using namespace acLib::constant;

        class CGL
        {
        public:
            static Vec2 Projection(const Vec2& p0, const Vec2& p1, const Vec2& p2)
            {
                Vec2 v = p2 - p0;
                Vec2 n = Vec2::normalize(p1 - p0);

                return n * Vec2::dot(v, n) + p0;
            }

            static Vec2 Reflection(const Vec2& p0, const Vec2& p1, const Vec2& p2)
            {
                Vec2 v = p2 - p0;
                Vec2 n = Vec2::normalize(p1 - p0);

                return (-v + n * 2 * Vec2::dot(v, n)) + p0;
            }

            static Vec2 Reflect(const Vec2& in, const Vec2& normal)
            {
                return Vec2::normalize(in - normal*(2.0*Vec2::dot(in, normal)));
            }

            static Vec3 Reflection(const Vec3& p0, const Vec3& p1, const Vec3& p2)
            {
                Vec3 v = p2 - p0;
                Vec3 n = Vec3::normalize(p1 - p0);

                return (-v + n * 2 * Vec3::dot(v, n)) + p0;
            }

            static Vec3 Reflect(const Vec3& in, const Vec3& normal)
            {
                return Vec3::normalize(in - normal*(2.0*Vec3::dot(in, normal)));
            }

            //@comment intersect segment and point
            static bool IntersectLP(Vec2 ss, Vec2 se, Vec2 p)
            {
                //@comment point is on segment start point or end point
                if (ss == p || se == p)
                {
                    return true;
                }

                return Vec2::cross(se - ss, p - ss) == 0
                    && (se - ss).norm() >= (p - ss).norm()
                    && Vec2::dot(se - ss, p - ss) > 0;
            }

            //@comment intersect segments
            static int IntersectLL(const Vec2& p1, const Vec2& p2, const Vec2 &p3, const Vec2& p4)
            {
                Vec2 line1 = p2 - p1, line2 = p4 - p3;

                if (IntersectLP(p1, p2, p3) || IntersectLP(p1, p2, p4))
                {
                    return 1;
                }
                else if (IntersectLP(p3, p4, p1) || IntersectLP(p3, p4, p2))
                {
                    return 2;
                }
                else if ((Vec2::cross(line1, p3 - p1)*Vec2::cross(line1, p4 - p1) < 0) &&
                    (Vec2::cross(line2, p1 - p3)*Vec2::cross(line2, p2 - p3) < 0))
                {
                    return 3;
                }
                else
                {
                    //@comment no intersection
                    return 0;
                }
            }

            //@comment Find orthonormal basis whose one basis is composed of source vector.
            static void OrthonormalBasis(const Vec3& normal, Vec3& tangent, Vec3& binormal)
            {
                //@comment find arbitrarily vector
                if (fabs(normal.x) > fabs(normal.y))
                {
                    tangent = Vec3::normalize(Vec3::cross(Vec3(0, 1, 0), normal));
                }
                else
                {
                    tangent = Vec3::normalize(Vec3::cross(Vec3(1, 0, 0), normal));
                }

                binormal = Vec3::normalize(Vec3::cross(normal, tangent));
            }

            //@comment Find orthonormal basis from arbitrarily three vectors by gram–schmidt orthogonalization
            static void OrthonormalBasis(const Vec3& src1, const Vec3& src2, const Vec3& src3, Vec3& res1, Vec3& res2, Vec3& res3)
            {
                Vec3 a[] = { src1, src2, src3 };
                Vec3* u[] = { &res1, &res2, &res3 };
                Vec3 v[3];
                for (int i = 0; i < 3; ++i)
                {
                    Vec3& res = *u[i];
                    Vec3 sum = Vec3(0.0);
                    for (int j = 0; j < i; ++j)
                    {
                        Vec3& tmp = *u[j];
                         sum = sum + Vec3::dot(a[i], tmp)*tmp;
                    }
                    v[i] = a[i] -sum;
                    res = Vec3::normalize(v[i]);
                }
            }

            static bool IsOrthonormalBasis(const Vec3& v1, const Vec3& v2, const Vec3& v3)
            {
                Vec3 v[] = { v1, v2, v3 };

                for (int i = 0; i < 3; ++i)
                {
                    if (1.0- v[i].norm() >= kEps)
                    {
                        return false;
                    }
                    if (abs(Vec3::dot(v[i], v[(i+1)%3])) >= kEps)
                    {
                        return false;
                    }
                }

                return true;
            }

            static Vec3 RotateX(const Vec3& vec, const double deg)
            {
                double c = cos(DEG2RAD(deg));
                double s = sin(DEG2RAD(deg));

                Vec3 res = Vec3(vec.x,
                    vec.y * c + vec.z * -s,
                    vec.y * s + vec.z * c);

                return res;
            }

            static Vec3 RotateY(const Vec3& vec, const double deg)
            {
                double c = cos(DEG2RAD(deg));
                double s = sin(DEG2RAD(deg));

                Vec3 res = Vec3(vec.x * c + vec.z * s,
                    vec.y,
                    vec.x*-s + vec.z * c);

                return res;
            }

            static Vec3 RotateZ(const Vec3& vec, const double deg)
            {
                double c = cos(DEG2RAD(deg));
                double s = sin(DEG2RAD(deg));

                Vec3 res = Vec3(vec.x * c + vec.y * -s,
                    vec.x * s + vec.y * c,
                    vec.z);

                return res;
            }

            static Vec3 RotateXYZ(const Vec3& vec, const Vec3& degs)
            {
                Vec3 res = RotateX(RotateY(RotateZ(vec, degs.z), degs.y), degs.x);

                return res;
            }
        };
    }
}
