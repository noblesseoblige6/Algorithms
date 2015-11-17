#include <bits/stdc++.h>

using namespace std;

class vec2{
  public:
  double x;
  double y;
  vec2():x(0), y(0){};
  ~vec2(){};
  vec2 operator+(vec2);
  vec2 operator-(vec2);
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

const float eps = 1e-8;

double dot(vec2 a, vec2 b)
{
  return a.x*b.x + a.y*b.y; 
}

double cross(vec2 a, vec2 b)
{
  return a.x*b.y - a.y*b.x; 
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
    vec2 s1 = p2 - p1;
    vec2 s2 = p4 - p3;
   
    if(fabs(dot(s1, s2)) == 0.0){cout<<1<<endl;}
    else if(fabs(cross(s1, s2)) == 0.0){cout<<2<<endl;}
    else{cout<<0<<endl;}
  }
  return 0;
}

