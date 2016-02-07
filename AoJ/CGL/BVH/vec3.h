#pragma once


template <typename T>
class vec3
{
  public:
    T x_;
    T y_;
    T z_;
    vec3() : x_(0.0), y_(0.0), z_(0.0){}
    vec3(double x, double y, double z) : x_(x), y_(y), z_(z){}
    vec3 operator-(const vec3<T>& v) const {return vec3(x_-v.x_, y_-v.y_, z_-v.z_);}
    vec3 operator*(const T c) const {return vec3(x_*c, y_*c, z_*c);}
    T operator[](int idx) const{
      if(idx == 0)
        return x_;
      else if(idx == 1)
        return y_;
      else if(idx == 2)
        return z_;
    } 
};
typedef vec3<double> hitpoint;

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

