#pragma once
#include <cmath>

namespace myMathUtil
{
  struct vec2{
    public:
      double x;
      double y;
      vec2():x(0), y(0){};
      vec2(double _x, double _y) : x(_x), y(_y){};
      ~vec2(){};
      vec2 operator+(vec2);
      vec2 operator-(vec2);
      bool operator==(vec2);
  };

  vec2 vec2::operator+(vec2 b)
  {
    vec2 res;
    res.x = this->x + b.x;
    res.y = this->y + b.y;
    return res;
  }

  vec2 vec2::operator-(vec2 b)
  {
    vec2 res;
    res.x = this->x - b.x;
    res.y = this->y - b.y;
    return res;
  }

  bool vec2::operator==(vec2 b)
  {
    if(this->x == b.x && this->y == b.y){return true;}
    return false;
  }
  const float eps = 1e-8;

  double norm(vec2 p)
  {
    return sqrt(p.x*p.x + p.y*p.y);
  }

  double dot(vec2 a, vec2 b)
  {
    return a.x*b.x + a.y*b.y;
  }
  double cross(vec2 a, vec2 b)
  {
    return a.x*b.y - a.y*b.x;
  }

  bool intersectLP(vec2 a, vec2 b, vec2 p)
  {
    if(a == p){return true;}
    if(b == p){return true;}
    return cross(b - a, p - a) == 0
      && norm(b-a) >= norm(p-a)
      && dot(b-a, p-a) > 0;
  }
  bool intersectLL(vec2 p1, vec2 p2, vec2 p3, vec2 p4)
  {
    vec2 line1 = p2 - p1;
    vec2 line2 = p4 - p3;
    if(intersectLP(p1, p2, p3)){ return true;}
    if(intersectLP(p1, p2, p4)){ return true;}
    if(intersectLP(p3, p4, p1)){ return true;}
    if(intersectLP(p3, p4, p2)){ return true;}

    return (cross(line1, p3 - p1)*cross(line1, p4 - p1) < 0)
      && (cross(line2, p1 - p3)*cross(line2, p2 - p3) < 0);
  }

}
