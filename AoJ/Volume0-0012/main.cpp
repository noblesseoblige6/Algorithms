#include <bits/stdc++.h>

using namespace std;

struct vec2
{
  double x_;
  double y_;
  vec2(double x, double y) : x_(x), y_(y){}
};

double cross(const vec2& a, const vec2& b)
{
  return a.x_*b.y_ - a.y_*b.x_;
}

int main()
{
  double x1, y1;
  double x2, y2;
  double x3, y3;
  double xp, yp;

  while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>xp>>yp){
    vec2 lines[] = {
      vec2(x2-x1, y2-y1),
      vec2(x3-x2, y3-y2),
      vec2(x1-x3, y1-y3)
    };
    vec2 pLines[] = {
      vec2(xp-x1, yp-y1),
      vec2(xp-x2, yp-y2),
      vec2(xp-x3, yp-y3)
    };
    bool isInnerPoint = false;
    if(cross(lines[0], pLines[0]) < 0 && cross(lines[1], pLines[1]) < 0 && cross(lines[2], pLines[2]) < 0)
      isInnerPoint = true;
    else if(cross(lines[0], pLines[0]) > 0 && cross(lines[1], pLines[1]) > 0 && cross(lines[2], pLines[2]) > 0)
      isInnerPoint = true;

    if(isInnerPoint)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}
