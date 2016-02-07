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
    bool operator==(vec2);
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

bool vec2::operator==(vec2 b)
{
  if(this->x == b.x && this->y == b.y){return true;}
  return false;
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

bool intersectLP(vec2 a, vec2 b, vec2 p)
{
  if(a == p || b == p){return true;}
  return cross(b - a, p - a) == 0 
    && norm(b-a) >= norm(p-a)
    && dot(b-a, p-a) > 0;
}
int intersectLL(vec2 p1, vec2 p2, vec2 p3, vec2 p4)
{
  vec2 line1 = p2 - p1, line2 = p4 - p3;
  if(intersectLP(p1, p2, p3) || intersectLP(p1, p2, p4)){return 1;}
  else if(intersectLP(p3, p4, p1) || intersectLP(p3, p4, p2)){return 2;}
  else if((cross(line1, p3 - p1)*cross(line1, p4 - p1) < 0) && 
      (cross(line2, p1 - p3)*cross(line2, p2 - p3) < 0)){return 3;}
  else{return 0;}
}
int inPolygon(vector<vec2>& points, vec2 p)
{
  unsigned int size = points.size();
  vec2 start, end, inf(INT_MAX, p.y);
  bool flag = false;
  int intersect;
  for(int i = 0; i < size; i++){
    if(i+1 >= size){end = points[0];}
    else{end = points[i+1];} 
    start = points[i];
    intersect = intersectLL(start, end, p, inf);
    if(intersect == 1){return 1;} //The point is on the segment
    else if(intersect != 0){
      //If P is between start and end points along y except for y of end point or start point
      if((start.y <= p.y && end.y > p.y) || (start.y > p.y && end.y <= p.y)){
        flag = !flag;
      } 
    }
  }
  return flag ? 2:0; 
}

int main(){
  vector<vec2> points;
  vector<vec2> targets;
  vec2 point;
  int count;
  cin>>count;
  for(int i = 0; i < count; i++){
    cin>>point.x>>point.y;
    points.push_back(point);
  }
  cin>>count;
  for(int i = 0; i < count; i++){
    cin>>point.x>>point.y;
    targets.push_back(point);
  }
  for(int i = 0; i < targets.size(); i++){ 
    cout<<inPolygon(points, targets[i])<<endl;
  }
  return 0;
}
