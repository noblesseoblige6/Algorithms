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
bool descendxPair(const pair<vec2, vec2>& a) 
{
  if(a.first.x == a.second.x){return a.first.y < a.second.y;}
  return a.first.x < a.second.x;
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

vec2 projection(vec2 p0, vec2 p1, vec2 p2)
{
  vec2 v, n;
  v.x = p2.x - p0.x;
  v.y = p2.y - p0.y;
  n.x = p1.x - p0.x;
  n.y = p1.y - p0.y;

  n = normalize(n);
  vec2 res;
  res.x = dot(v, n)*n.x + p0.x;
  res.y = dot(v, n)*n.y + p0.y;
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

pair<vec2, vec2> findCrossPointCL(vec2 c, double r, vec2 p0, vec2 p1)
{
  //@comment The point projected to the seg 
  //from center of the circle
  vec2 h = projection(p0, p1, c);
  vec2 n = normalize(p1-p0);
  vec2 cr = h - c;
  //@comment The distance from the center to the projected point is bigger than r 
  if(norm(cr) > r){exit(1);} 
  double d = sqrt(r*r - norm(cr)*norm(cr));
  return formatPair(make_pair(c + (cr-n*d), c + (cr+n*d)));
}

int main(){
  vec2 p1;
  vec2 p2;
  vec2 c;
  double r;
  int count;

  cin>>c.x>>c.y>>r;
  cin>>count;
  for(int i = 0; i < count; i++){
    cin>>p1.x>>p1.y>>p2.x>>p2.y;
    pair<vec2, vec2> res = findCrossPointCL(c, r, p1, p2);
    cout<<setprecision(8);
    cout<<fixed<<res.first.x<<" "<<res.first.y<<" "<<res.second.x<<" "<<res.second.y<<endl;
  }
  return 0;
}

