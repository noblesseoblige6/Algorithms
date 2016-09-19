#include <bits/stdc++.h>

using namespace std;
struct Point
{
  double x;
  double y;
  Point() : x(FLT_MAX), y(FLT_MAX){}
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
void InnerTangent(const Circle& c1, const Circle& cir2, Point& p1, Point& p2)
{
  // Translate second circle
  Circle c2 = Circle(cir2.x - c1.x, cir2.y - c1.y, cir2.r);

  double c = c2.x*c2.x + c2.y*c2.y;
  double r = (c1.r + c2.r);
  double rSq = r * r;

  // Find first tangent point
  p1.x = c2.x * r + c2.y * sqrt(c + - rSq);
  p1.x *= c1.r/c;

  p1.y = c2.y * r - c2.x * sqrt(c + - rSq);
  p1.y *= c1.r/c;

  // Find second tangent point
  p2.x = c2.x * r - c2.y * sqrt(c + - rSq);
  p2.x *= c1.r/c;

  p2.y = c2.y * r + c2.x * sqrt(c + - rSq);
  p2.y *= c1.r/c;

  // Translate points
  p1.x += c1.x;
  p2.x += c1.x;

  p1.y += c1.y;
  p2.y += c1.y;
}

void OuterTangent(const Circle& c1, const Circle& cir2, Point& p1, Point& p2)
{
  // Translate second circle
  Circle c2 = Circle(cir2.x - c1.x, cir2.y - c1.y, cir2.r);

  double c = c2.x*c2.x + c2.y*c2.y;
  double r = (c1.r - c2.r);
  double rSq = r * r;

  // Find first tangent point
  p1.x = c2.x * r + c2.y * sqrt(c + - rSq);
  p1.x *= (double)c1.r/c;

  p1.y = c2.y * r - c2.x * sqrt(c + - rSq);
  p1.y *= (double)c1.r/c;

  // Find second tangent point
  p2.x = c2.x * r - c2.y * sqrt(c + - rSq);
  p2.x *= (double)c1.r/c;

  p2.y = c2.y * r + c2.x * sqrt(c + - rSq);
  p2.y *= (double)c1.r/c;


  // Translate points
  p1.x += c1.x;
  p2.x += c1.x;

  p1.y += c1.y;
  p2.y += c1.y;

}

void FindCommonTanget(int x1, int y1, int r1, int x2, int y2, int r2)
{
  vector<Point> p(4);
  Point tmp;

  Circle c1 = Circle(x1, y1, r1);
  Circle c2 = Circle(x2, y2, r2);

  int n = CircleIntersection(x1, y1, r1, x2, y2, r2);
  switch(n)
  {
    case 1:
      OuterTangent(c1, c2, p[0], tmp);
      break;
    case 2:
      OuterTangent(c1, c2, p[0], p[1]);
      break;
    case 3:
      InnerTangent(c1, c2, p[0], tmp);
      OuterTangent(c1, c2, p[2], p[3]);
      break;
    case 4:
      InnerTangent(c1, c2, p[0], p[1]);
      OuterTangent(c1, c2, p[2], p[3]);
      break;
    default:
      break;
  };

  sort(p.begin(), p.end());

  for(int i = 0; i < n; ++i)
    printf("%.10f %.10f\n", p[i].x, p[i].y);
}

int main()
{
  int r1, r2;
  int x1, x2, y1, y2;

  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;

  FindCommonTanget(x1, y1, r1, x2, y2, r2);
  return 0;
}
