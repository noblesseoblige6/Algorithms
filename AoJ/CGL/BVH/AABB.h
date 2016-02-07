#pragma once
#include "vec3.h"
#include <iostream>

template <typename T>
class AABB
{
  private:
    vec3<T> min_;
    vec3<T> max_;
    vec3<T> center_;
    vec3<T> find_center() const{
      return (max_ - min_)*0.5;
    }

  public:
    AABB():min_(vec3<T>()), max_(vec3<T>()), center_(vec3<T>()){}
    AABB(vec3<T> min, vec3<T> max) : min_(min), max_(max), center_(find_center()){}
    T x_edge() const {return (max_ - min_).x_;}
    T y_edge() const {return (max_ - min_).y_;}
    T z_edge() const {return (max_ - min_).z_;}
    T surface_area() const{
      return 2*(x_edge()*y_edge()+y_edge()*z_edge()+z_edge()*x_edge());
    }
    vec3<T>& center()
    {
      return center_;
    }
    friend std::ostream& operator<<(std::ostream& os, AABB<T> b)
    {
      os<<b.min_[0]<<" "<<b.min_[1]<<" "<<b.min_[2]<<std::endl;
      os<<b.max_[0]<<" "<<b.max_[1]<<" "<<b.max_[2]<<std::endl;
    }
};
