#pragma once
#include <vector>
#include <algorithm>

#include "Vec.h"
#include "Segment.h"
#include "Constant.h"

namespace acLib
{
    namespace cgl
    {
        using namespace std;

        using namespace acLib::vec;
        using namespace acLib::segment;
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

            static double FindConvexArea(const vector<Vec2>& polygon)
            {
                double area = 0.0;

                for (int i = 1; i < (int)(polygon.size() - 1); ++i)
                {
                    Vec2 a = polygon[i] - polygon[0];
                    Vec2 b = polygon[i + 1] - polygon[0];

                    double tmpArea = abs(Vec2::cross(a, b)) * 0.5;
                    area += tmpArea < kEps ? 0.0 : tmpArea;
                }

                return area;
            }

            static void FindConvexHull(vector<Vec2>& points, vector<Vec2>& res)
            {
                const int size = points.size();

                //@comment sort the vertices by y-axis
                sort(points.begin(), points.end());

                //@comment add first two vertices to create vector
                vector<Vec2> rSide;
                rSide.push_back(points[0]);
                rSide.push_back(points[1]);

                //@comment Search right-hand side
                for (int i = 2; i < size; ++i)
                {
                    for (int n = rSide.size() - 1; n >= 1; --n)
                    {
                        const Vec2 &a = rSide[n] - rSide[n - 1];
                        const Vec2 &b = points[i] - rSide[n];

                        //@comment omit vertices which is not on the right side
                        if (Vec2::cross(a, b) > 0)
                        {
                            rSide.pop_back();
                        }
                        else
                        {
                            break;
                        }
                    }
                    rSide.push_back(points[i]);
                }

                //@comment add last two vertices to create vector
                vector<Vec2> lSide;
                lSide.push_back(points[size - 1]);
                lSide.push_back(points[size - 2]);

                //@comment Search left-hand side
                for (int i = size - 3; i >= 0; --i)
                {
                    for (int n = lSide.size() - 1; n >= 1; --n)
                    {
                        const Vec2 &a = lSide[n] - lSide[n - 1];
                        const Vec2 &b = points[i] - lSide[n];

                        //@comment omit the vertex which is not on the left side
                        if (Vec2::cross(a, b) > 0)
                        {
                            lSide.pop_back();
                        }
                        else
                        {
                            break;
                        }
                    }
                    lSide.push_back(points[i]);
                }

                //@comment merge right and left side convexes
                res.reserve(rSide.size() + lSide.size() - 2);
                for (int i = 0; i < (int)rSide.size(); ++i)
                {
                    res.push_back(rSide[i]);
                }
                //@comment omit first and last vertices
                for (int i = 1; i < (int)(lSide.size() - 1); ++i)
                {
                    res.push_back(lSide[i]);
                }

                //@comment convert CW to CCW
                for (int i = 1; i <= (int)(res.size() / 2); ++i)
                {
                    Vec2 tmp = res[i];
                    res[i] = res[res.size() - i];
                    res[res.size() - i] = tmp;
                }
            }

            static double FindConvexCut(vector<Vec2>& points, const Segment& segment)
            {
                vector<Vec2> convex;
                FindConvexHull(points, convex);

                //@comment find far points to create a segment
                Vec2 dir = Vec2::normalize(segment.m_end - segment.m_start);

                const int scale = 100000;
                Vec2 end = dir * scale + segment.m_start;
                Vec2 start = dir * -scale + segment.m_start;

                //@comment find two intersections
                Vec2 cutSegment = Vec2::normalize(end - start);
                vector<Vec2> cutConvex;
                cutConvex.reserve(convex.size());

                //@comment For detection second inter.occurs last segment, loop one more
                const int size = convex.size();
                for (int i = 0; i < size; ++i)
                {
                    Vec2 tmp = Vec2::normalize(convex[i] - start);

                    //@comment determine if i-th vertex is on left-hand side by edge and cutting segment
                    if (Vec2::cross(cutSegment, tmp) >= 0)
                    {
                        cutConvex.push_back(convex[i]);
                    }

                    //@comment check if an intersection occurs with cutting segment
                    const Segment seg1(convex[i], convex[(i + 1) % size]);
                    const Segment seg2(start, end);
                    if (Segment::Intersect(seg1, seg2))
                    {
                        Vec2 tmp = Segment::CrossPoint(seg1, seg2);

                        //@comment avoid miss judge that the same point is intersection
                        if (tmp == convex[i] || tmp == convex[(i + 1) % size])
                        {
                            continue;
                        }

                        cutConvex.push_back(tmp);
                    }
                }

                return FindConvexArea(cutConvex);
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
                    v[i] = a[i] - sum;
                    res = Vec3::normalize(v[i]);
                }
            }

            static bool IsOrthonormalBasis(const Vec3& v1, const Vec3& v2, const Vec3& v3)
            {
                Vec3 v[] = { v1, v2, v3 };

                for (int i = 0; i < 3; ++i)
                {
                    if (1.0 - v[i].norm() >= kEps)
                    {
                        return false;
                    }
                    if (abs(Vec3::dot(v[i], v[(i + 1) % 3])) >= kEps)
                    {
                        return false;
                    }
                }

                return true;
            }

            static double GeometoryTerm(const Vec3& point1, const Vec3& point2, const Vec3& normal1, const Vec3& normal2)
            {
                Vec dir = point2 - point1;

                const double rSq = dir.normSq();
                if(rSq == 0.0)
                {
                    return 0.0;
                }

                dir.normalized();
                return (std::max(Vec3::dot(normal1, dir), 0.0)*std::max(Vec3::dot(normal2, -dir), 0.0)) / rSq;
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
