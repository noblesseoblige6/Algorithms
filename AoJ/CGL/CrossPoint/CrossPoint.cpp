#include <bits/stdc++.h>

using namespace std;

class vec2{
  public:
    double x;
    double y;
    vec2():x(0.0), y(0.0){};
    vec2(double x, double y):x(x), y(y){};
    ~vec2(){};
    vec2 operator+(vec2);
    vec2 operator-(vec2);
    vec2 operator*(double);
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

vec2 vec2::operator*(double m)
{
  return vec2(m*this->x, m*this->y);
}
const double eps = 1e-8;
double norm(vec2 a)
{
  return sqrt(a.x*a.x + a.y*a.y);
}

double cross(vec2 a, vec2 b)
{
return a.x*b.y - a.y*b.x;
}

vec2 findCrossPoint(vec2 p0, vec2 p1, vec2 p2, vec2 p3)
{
  vec2 base = p1 - p0;
  vec2 cSeg = p3 - p2;
  vec2 s1 = p0 - p2;
  vec2 s2 = p1 - p3;

  //@comment Find the height from base vector to p2 and p3
  //@comment To reduce error, dividing by norm is ommited
  // double d1 = abs(cross(cSeg, s1))/norm(base);
  // double d2 = abs(cross(cSeg, s2))/norm(base);
  double d1 = abs(cross(cSeg, s1));
  double d2 = abs(cross(cSeg, s2));


  //@comment Accroding to the ratio, t:(1-t) = d1:d2
  return  p0 + base * (d1/(d1+d2));
}
int main(){
  vec2 p1;
  vec2 p2;
  vec2 p3;
  vec2 p4;
  int count;

  cin>>count;
  for(int i = 0; i < count; i++){
    cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y>>p4.x>>p4.y;
    vec2 res = findCrossPoint(p1, p2, p3, p4);
    
    cout<<setprecision(8);
    cout<<fixed<<res.x<<" "<<res.y<<endl;
  }
  return 0;
}

