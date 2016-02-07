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
    bool operator==(vec2);
    bool operator !=(vec2);
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

bool vec2::operator==(vec2 b)
{
  if(this->x == b.x && this->y == b.y){return true;}
  return false;
}

bool vec2::operator!=(vec2 b)
{
  return !(*this == b);
}

bool ascendy(const vec2& a, const vec2& b)
{
  if(a.y == b.y){return a.x > b.x;}
  return a.y > b.y;
}

bool descendy(const vec2& a,const vec2& b) 
{
  if(a.y == b.y){return a.x < b.x;}
  return a.y < b.y;
}

bool ascendx(const vec2& a, const vec2& b)
{
  if(a.x == b.x){return a.y > b.y;}
  return a.x > b.x;
}

bool descendx(const vec2& a,const vec2& b) 
{
  if(a.x == b.x){return a.y < b.y;}
  return a.x < b.x;
}
bool ascend(const vec2& a, const vec2& b)
{
  return ascendx(a, b) && ascendy(a, b);
}
bool descend(const vec2& a,const vec2& b) 
{
  return descendx(a, b) && descendy(a, b);
}

double norm(vec2 a)
{
  return sqrt(a.x*a.x + a.y*a.y);
}

double dot(vec2 a, vec2 b)
{
  return a.x*b.x + a.y*b.y; 
}

double cross(vec2 a, vec2 b)
{
  return a.x*b.y - a.y*b.x;
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
    res.x = 0.0;
    res.y = 0.0;
  }
  return res;
}

pair<vec2, vec2> formatPair(pair<vec2, vec2> p)
{
  if(p.first.x == p.second.x){
    if(p.first.y < p.second.y){return p;}
    else{return make_pair(p.second, p.first);}
  }
  else if(p.first.x < p.second.x){return p;}
  else if(p.first.x > p.second.x){return make_pair(p.second, p.first);}
}

pair<vec2, vec2> findCrossPointCircles(vec2 c1, double r1, vec2 c2, double r2)
{
  double d = norm(c2-c1);
  if(d > r1+r2){exit(1);}
  double alpha = atan2((c2.y-c1.y),(c2.x-c1.x));
  double theta = acos((r1*r1+d*d-r2*r2)/(2*r1*d));
  //@comment Cross points
  vec2 p1, p2;
  p1 = vec2(r1*cos(alpha+theta), r1*sin(alpha+theta));
  p2 = vec2(r1*cos(theta-alpha), r1*sin(alpha-theta));
  //@comment output format
 return formatPair(make_pair(c1+p1, c1+p2)); 
}

int main(){
  vec2 c1, c2;
  double r1, r2;
  int count;

  cin>>c1.x>>c1.y>>r1;
  cin>>c2.x>>c2.y>>r2;
  pair<vec2, vec2> res = findCrossPointCircles(c1, r1, c2, r2);
  cout<<setprecision(8);
  cout<<fixed<<res.first.x<<" "<<res.first.y<<" ";
  cout<<res.second.x<<" "<<res.second.y<<endl;
  return 0;
}

