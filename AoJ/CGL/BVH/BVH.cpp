#include "BVH.h"
#include <iostream>
#include <cfloat>
#include <algorithm>

using namespace std;
class BVH::BVH_node
{
  public:
    BVH_node():l(NULL), r(NULL), depth(0){}
    BVH_node(int d, AABB<double> b):l(NULL), r(NULL), depth(d), box(b){}
    int depth;
    std::vector<int> leaf_ids;
    AABB<double> box;
    BVH_node* l;
    BVH_node* r;
    void release(){
      if(l != NULL){l->release();}
      if(r != NULL){r->release();}
      delete this;
    }
};

BVH::BVH() : root(NULL){}

BVH::~BVH(){
  if(root != NULL)
    root->release();
}

AABB<double> BVH::create_AABB(std::vector<Triangle>& v, int s, int e)
{
 
  double minx, maxx;
  std::sort(v.begin()+s,  v.begin()+e, Triangle::compare_x);
  minx = v.front().min()[0];
  maxx = v.back().max()[0];

  double miny, maxy;
  std::sort(v.begin()+s,  v.begin()+e, Triangle::compare_y);
  miny = v.front().min()[1];
  maxy = v.back().max()[1];

  double minz, maxz;
  std::sort(v.begin()+s,  v.begin()+e, Triangle::compare_z);
  minz = v.front().min()[2];
  maxz = v.back().max()[2];

  return AABB<double>(vec3<double>(minx, miny, minz), vec3<double>(maxx, maxy, maxz));
}

int BVH::find_separator(const std::vector<Triangle>& v, double val, int axis)
{
  if(v.size() == 1)
    return 0;

  int next = v.size();
  int i = static_cast<int>(v.size()/2);
  while(true){
    if(val < v[i].min()[axis])
      next = i/2;
    else
      next = (next - i)/2;

    if(next == i)
      break;
    i = next;
  }
  return i+1;
}


BVH::BVH_node* BVH::internal_divide(std::vector<Triangle>& polygons, int depth, double prev_cost)
{
  if(polygons.size() == 0) return NULL;
  BVH_node* n = new BVH_node(depth, create_AABB(polygons, 0, polygons.size()));

  double cost = prev_cost;
  std::vector<Triangle> l_poly, r_poly;

  //@comment separate polygons in each axis based on the center of AABB
  for(int i = 0; i < 3; ++i){
    if(i == 0)
      std::sort(polygons.begin(), polygons.end(), Triangle::compare_x);
    else if(i == 1)
      std::sort(polygons.begin(), polygons.end(), Triangle::compare_y);
    else if(i == 2)
      std::sort(polygons.begin(), polygons.end(), Triangle::compare_z);

    int offset = find_separator(polygons, n->box.center()[i], i);
    AABB<double> l_box = create_AABB(polygons, 0, offset);
    AABB<double> r_box = create_AABB(polygons, offset+1, polygons.size());

    //@comment calc. cost
    double tmp = 2*depth+(l_box.surface_area()*l_poly.size()+r_box.surface_area()*r_poly.size())*(depth+1)/n->box.surface_area();

    //@comment update min cost
    if(cost > tmp){
      cost = tmp;
      l_poly.clear();
      std::copy(polygons.begin(), polygons.begin()+offset+1, std::back_inserter(l_poly));
      r_poly.clear();
      std::copy(polygons.begin()+offset+1, polygons.end(), std::back_inserter(r_poly));
    }
  }
  //@comment when a node is a leaf, it should have the info of polygons
  if(prev_cost == cost){
    for(int i = 0; i < polygons.size(); ++i)
      n->leaf_ids.push_back(polygons[i].get_id());
    return n;
  }

  //@comment construct binary tree 
  n->l = internal_divide(l_poly, n->depth+1, cost);
  n->r = internal_divide(r_poly, n->depth+1, cost);

  return n;
}

void BVH::construct(std::vector<Triangle>& polygons)
{
  root = internal_divide(polygons, 0, FLT_MAX);
}

bool BVH::intersect(const Ray& ray, hitpoint& hp)
{

}

void BVH::tree_structure(BVH_node* n)
{
  if(n == NULL) return;
  std::cout<<std::endl<<"Depth : "<<n->depth<<std::endl<<n->box;
  std::cout<<"ids : ";
  for(int i = 0; i < n->leaf_ids.size(); ++i)
    std::cout<<n->leaf_ids[i]<<" ";
  std::cout<<std::endl;

  tree_structure(n->l); 
  tree_structure(n->r); 
}

void BVH::check()
{
  tree_structure(root);
}
