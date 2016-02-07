#pragma once
#include "vec3.h"
#include <algorithm>
#include <iostream>
class Triangle
{
  private:
    int id_;
    vec3<double> v1;
    vec3<double> v2;
    vec3<double> v3;
  public:
    Triangle(){}
    Triangle(int id, vec3<double> a, vec3<double> b, vec3<double> c) : 
      id_(id), v1(a), v2(b), v3(c){}
    int get_id() const {return id_;}
    vec3<double> min() const
    {
      return vec3<double>(
          std::min(v1[0], std::min(v2[0], v3[0])),
          std::min(v1[1], std::min(v2[1], v3[1])),
          std::min(v1[2], std::min(v2[2], v3[2]))
          );
    }
    vec3<double> max() const
    {
      return vec3<double>(
          std::max(v1[0], std::max(v2[0], v3[0])),
          std::max(v1[1], std::max(v2[1], v3[1])),
          std::max(v1[2], std::max(v2[2], v3[2]))
          );
    }

    //@comment predicade for stl::sort 
    static bool compare_x(const Triangle& a, const Triangle& b)
    {
      return a.min()[0] < b.min()[0];
    }
    static bool compare_y(const Triangle& a, const Triangle& b)
    {
      return a.min()[1] < b.min()[1]; 
    }
    static bool compare_z(const Triangle& a, const Triangle& b)
    {
      return a.min()[2] < b.min()[2]; 
    }

    friend std::ostream& operator<<(std::ostream& os, const Triangle& t)
    {
      os<<t.v1[0]<<" "<<t.v1[1]<<" "<<t.v1[2]<<std::endl;
      os<<t.v2[0]<<" "<<t.v2[1]<<" "<<t.v2[2]<<std::endl;
      os<<t.v3[0]<<" "<<t.v3[1]<<" "<<t.v3[2]<<std::endl;
      os<<std::endl; 
    }
};
