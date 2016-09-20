#include <bits/stdc++.h>

using namespace std;
struct Point
{
  double x;
  double y;
  Point() : x(FLT_MAX), y(FLT_MAX){}
  Point(double _x, double _y) : x(_x), y(_y){}
  bool operator < (const Point& p) const
  {
    if(x == p.x)
      return y < p.y;
    return x < p.x;
  }
};

struct Circle
{
  double x;
  double y;
  double r;
  Circle(int _x, int _y, int _r) : x(_x), y(_y), r(_r){}
};

int CircleIntersection(int x1, int y1, int r1, int x2, int y2, int r2)
{

  int x = abs(x1 - x2);
  int y = abs(y1 - y2);
  double d = sqrt(x*x + y*y);

  // No intersection
  if(r1+r2 < d)
  {
    return 4;
  }
  else if(r1+r2 == d)
  {
    // Externally
    return 3;
  }
  else if(r1+r2 > d)
  {
    if(abs(r1-r2) < d)
    {
      // Intersection
      return 2;
    }
    else if(abs(r1-r2) == d)
    {
      // Incribed
      return 1;
    }
    else
    {
      // Comprehension
      return 0;
    }
  }
}
void CircleTangent(const Circle& cir, const Point& point, Point& p1, Point& p2)
{
  // Translate point
  Point p = Point(point.x - cir.x, point.y - cir.y);

  double c = p.x*p.x + p.y*p.y;
  double rSq = cir.r * cir.r;

  // Find first tangent point
  p1.x = p.x * cir.r + p.y * sqrt(c + - rSq);
  p1.x *= cir.r/c;

  p1.y = p.y * cir.r - p.x * sqrt(c + - rSq);
  p1.y *= cir.r/c;

  // Find second tangent point
  p2.x = p.x * cir.r - p.y * sqrt(c + - rSq);
  p2.x *= cir.r/c;

  p2.y = p.y * cir.r + p.x * sqrt(c + - rSq);
  p2.y *= cir.r/c;

  // Translate points
  p1.x += cir.x;
  p2.x += cir.x;

  p1.y += cir.y;
  p2.y += cir.y;
}

void FindTangetToCircle(int x, int y, int r, int px, int py)
{
  Point p(px, py);

  Circle c = Circle(x, y, r);
  vector<Point> res;
  res.resize(2);

  CircleTangent(c, p, res[0], res[1]);
  sort(res.begin(), res.end());

  for(int i = 0; i < res.size(); ++i)
    printf("%.10f %.10f\n", res[i].x, res[i].y);
}

int main()
{
  int r;
  int x, y;
  int px, py;

  cin >> px >> py;
  cin >> x >> y >> r;

  FindTangetToCircle(x, y, r, px, py);
  return 0;
}
