#pragma once
#include "AABB.h"
#include "Triangle.h"
#include <vector>
class BVH
{
  public:
    BVH();
    ~BVH();
    class BVH_node;
    void check();
    void construct(std::vector<Triangle>&);
    bool intersect(const Ray&, hitpoint&);
  private:
    BVH_node* root;
    BVH_node* internal_divide(std::vector<Triangle>&, int, double);
    AABB<double> create_AABB(std::vector<Triangle>&, int, int);
    int find_separator(const std::vector<Triangle>& v, double val, int axis);
    void tree_structure(BVH_node*);
};
