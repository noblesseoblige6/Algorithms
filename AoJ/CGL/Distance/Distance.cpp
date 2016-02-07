#include <bits/stdc++.h>

using namespace std;

class vec2{
  public:
    double x;
    double y;
    vec2():x(0.0), y(0.0){};
    vec2(double val):x(val), y(val){};
    vec2(double x, double y):x(x), y(y){};
    ~vec2(){};
    vec2 operator=(vec2);
    vec2 operator+(vec2);
    vec2 operator-(vec2);
    vec2 operator*(double);
};

vec2 vec2::operator=(vec2 b)
{
  this->x = b.x;
  this->y = b.y;
  return *this;
}

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
vec2 normalize(vec2 a)
{
  vec2 res;
  double len = norm(a);
  if(len != 0.0){
    res.x = a.x/len;
    res.y = a.y/len;
  }
  else{
    res.x = 0.0f;
    res.y = 0.0f;
  }
  return res;
}

double dot(vec2 a, vec2 b)
{
  return a.x*b.x + a.y*b.y; 
}

double cross(vec2 a, vec2 b)
{
  return a.x*b.y - a.y*b.x;
}

vec2 projection(vec2 n, vec2 p0, vec2 p2)
{
  vec2 v;
  v = p2 - p0;

  n = normalize(n);
  vec2 res = n*dot(v, n) + p0;
  return res;
}

bool isIntersected(vec2 p1, vec2 p2, vec2 p3, vec2 p4)
{
  return cross(p3-p1, p4 - p1)*cross(p3 - p2, p4 - p2) < 0 
    && cross(p1 - p3, p2 - p3)*cross(p1 - p4, p2 - p4) < 0;
}

double findDisSP(vec2 terminal, vec2 origin, vec2 point)
{
  vec2 tmpSeg = point - origin;
  vec2 segment = terminal - origin;
  double dotProduct = dot(segment, tmpSeg);
  double dis;
  double d = norm(projection(segment, origin, point) - point);
  if(dotProduct <= 0.0f){dis = norm(tmpSeg);}
  else{
    vec2 tmp = projection(segment, origin, point);
    dis = sqrt(norm(tmpSeg)*norm(tmpSeg) - d*d);
    if(norm(segment) < dis){dis = norm(terminal - point);}
    else{dis = norm(tmp - point);}
  }
  return  dis; 
}

double findMinDis(vec2 p1, vec2 p2, vec2 p3, vec2 p4 )
{
  //@comment Two segments intersecting, the distance is 0
  if(isIntersected(p1, p2, p3, p4)){return 0.0f;}
  //@comment The start or end point to other segment is the min distance
  double tmpDis1 = min(findDisSP(p2, p1, p3), findDisSP(p2, p1, p4));
  double tmpDis2 = min(findDisSP(p4, p3, p1), findDisSP(p4, p3, p2));
  return min(tmpDis1, tmpDis2);
}

int main()
{
  vec2 p1, p2, p3, p4;
  int count;
  cin>>count;
  cout<<setprecision(10);
  for(int i = 0; i < count; i++){
    cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y>>p4.x>>p4.y;
    cout<<fixed<<findMinDis(p1, p2, p3, p4)<<endl;
  }
  return 0;
}

