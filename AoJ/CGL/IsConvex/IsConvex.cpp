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
    vec2 operator*(float);
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

vec2 vec2::operator*(float m)
{
  return vec2(m*this->x, m*this->y);
}


const float eps = 1e-8;
float norm(vec2 a)
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

bool isConvex(vector<vec2>& points )
{
  unsigned int size = points.size();
  vec2 a, b;
  int n, p;
  for(int i = 0; i < size; i++){
    p = i - 1;
    n = i + 1;
    if(p < 0){p = size-1;}
    if(n >= size){n = 0;}
    a = points[i] - points[p];
    b = points[n] - points[i];
    if(cross(a, b) < 0){return false;}
  }
  return true;
}

int main(){
  vector<vec2> points;
  vec2 point;
  int count;
  cin>>count;
  for(int i = 0; i < count; i++){
    cin>>point.x>>point.y;
    points.push_back(point);
  }
  if(isConvex(points)){
  cout<<1<<endl;
  }
  else{cout<<0<<endl;}
  return 0;
}
