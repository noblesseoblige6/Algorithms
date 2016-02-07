#include <bits/stdc++.h>

using namespace std;

template <typename T>
class vec3
{
  public:
    T x_;
    T y_;
    T z_;
    vec3() : x_(0.0), y_(0.0), z_(0.0){}
    vec3(double x, double y, double z) : x_(x), y_(y), z_(z){}
};

class Ray
{
  private:
    vec3<double> dir_;
    vec3<double> org_;
  public:
    Ray() : dir_(vec3<double>(0.0, 0.0, 0.0)), org_(vec3<double>(0.0, 0.0, 0.0)){}
    Ray(vec3<double> dir, vec3<double> org) : dir_(dir), org_(org){}
    vec3<double> dir() const{return dir_;}
    vec3<double> org() const{return org_;}

};

class AABB
{
  private:
    vec3<double> min_;
    vec3<double> max_;
  public:
    AABB() : min_(vec3<double>(0.0, 0.0, 0.0)), max_(vec3<double>(0.0, 0.0, 0.0)){}
    AABB(vec3<double> min, vec3<double> max) : min_(min), max_(max){}
    vec3<double> min() const{return min_;}
    vec3<double> max() const{return max_;}
};

bool isIntersec_Ray_Box(const Ray& ray, const AABB& box)
{

  bool isInside = true;
  vec3<double> org = ray.org(); 
  vec3<double> dir = ray.dir(); 

  double tx;
  if(box.min().x_ > org.x_){
    tx = (box.min().x_ - org.x_)/ dir.x_;
    isInside = false;
  }else if(box.max().x_ < org.x_){
    tx = (box.max().x_ - org.x_)/ dir.x_;
    isInside = false;
  }else{
    tx = -1.0;
  }
  double ty;
  if(box.min().y_ > org.y_){
    ty = (box.min().y_ - org.y_)/ dir.y_;
    isInside = false;
  }else if(box.max().y_ < org.y_){
    ty = (box.max().y_ - org.y_)/ dir.y_;
    isInside = false;
  }else{
    ty = -1.0;
  }
  double tz;
  if(box.min().z_ > org.z_){
    tz = (box.min().z_ - org.z_)/ dir.z_;
    isInside = false;
  }else if(box.max().z_ < org.z_){
    tz = (box.max().z_ - org.z_)/ dir.z_;
    isInside = false;
  }else{
    tz = -1.0;
  }

  //@comment the ray is in the box
  if(isInside){return true;}

  double t = tx;
  int selPlane = 0;
  if(ty > t){
    selPlane = 1;
    t = ty;
  }
  if(tz > t){
    selPlane = 2;
    t = tz;
  }

  double x, y, z;
  switch(selPlane){
    //@comment check the ray intersects y-z plane
    case 0:
      y = dir.y_*t + org.y_;
      if(y < box.min().y_|| y > box.max().y_){return false;}
      z = dir.z_*t + org.z_;
      if(z < box.min().z_|| z > box.max().z_){return false;}
      break;
    case 1:
      x = dir.x_*t + org.x_;
      if(x < box.min().x_|| x > box.max().x_){return false;}
      z = dir.z_*t + org.z_;
      if(z < box.min().z_|| z > box.max().z_){return false;}
      break;
    case 2:
      y = dir.y_*t + org.y_;
      if(y < box.min().y_|| y > box.max().y_){return false;}
      x = dir.x_*t + org.x_;
      if(x < box.min().x_|| x > box.max().x_){return false;}
      break;
  }
  return true;
}

int main()
{
  double tmpx1, tmpy1, tmpz1;
  double tmpx2, tmpy2, tmpz2;
  double minx, miny, minz;
  double maxx, maxy, maxz;
  while(cin){
    cin>>tmpx1>>tmpy1>>tmpz1;
    cin>>tmpx2>>tmpy2>>tmpz2;
  }
  minx = min(tmpx1, tmpx2);
  maxx = max(tmpx1, tmpx2);

  miny = min(tmpy1, tmpy2);
  maxy = max(tmpy1, tmpy2);

  minz = min(tmpz1, tmpz2);
  maxz = max(tmpz1, tmpz2);

  isIntersec_Ray_Box(Ray(vec3<double>(1.0, 0.0, 0.0), vec3<double>(0.0, 0.0, 0.0)), AABB(vec3<double>(minx, miny, minz), vec3<double>(maxx, maxy, maxz))) 
    ? cout<<"Intersec" : cout<<"NOT intersec";
  cout<<endl;
  return 0;
}
