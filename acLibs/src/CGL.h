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
            static void OrthonormalBasis(const Vec3& src, Vec3& res1, Vec3&res2)
            {
                //@comment find arbitrarily vector
                Vec3 v;
                for (int i = 0; i < 3; ++i)
                {
                    if (i == 0)
                    {
                        v = Vec3(1.0, 0.0, 0.0);
                    }
                    else if (i == 1)
                    {
                        v = Vec3(0.0, 1.0, 0.0);
                    }
                    else if (i == 2)
                    {
                        v = Vec3(0.0, 0.0, 1.0);
                    }

                    //@comment source and arbitrarily vectors are different
                    if (1.0-abs(Vec3::dot(src, v)) > kEps)
                    {
                        break;
                    }
                }

                res1 = Vec3::normalize(Vec3::cross(src, v));
                res2 = Vec3::normalize(Vec3::cross(res1, src));
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
        };
    }
}
