#include <bits/stdc++.h>
#include "BVH.h"

using namespace std;

int bin_seach(const vector<Triangle>& v, double val, int axis)
{
  int next;
  int i = static_cast<int>(v.size()/2);
  next = i;
  while(true){
    if(val < v[i].min()[axis]){next = i/2;}
    else{next = (next - i)/2;}
    if(next == i)
      break;
    i = next;
  }
  return i+1;
}

int main()
{
  AABB<double> box(vec3<double>(0, 0, 0), vec3<double>(2, 2 ,2));
  vector<Triangle> polygons;
  vector<Triangle> l_poly;
  vector<Triangle> r_poly;

  polygons.push_back(Triangle(vec3<double>(1.5, 0, 1), vec3<double>(1.5, 0, -1), vec3<double>(1.5, 1, 0)));
  polygons.push_back(Triangle(vec3<double>(0, 0, 1), vec3<double>(0, 0, -1), vec3<double>(0, 1, 0)));
  for(int i = 0; i < 1; ++i){
    std::sort(polygons.begin(), polygons.end(), Triangle::compare_x);
    int offset = bin_seach(polygons, box.center()[i], i);
    cout<<offset<<endl;
    std::copy(polygons.begin(), polygons.begin()+offset, std::back_inserter(l_poly));
    std::copy(polygons.begin()+offset, polygons.end(), std::back_inserter(r_poly));
  }
  cout<<"TEST"<<endl;
  for(int i = 0; i < l_poly.size(); ++i){
    cout<<l_poly[i]<<endl; 
  }
  for(int i = 0; i < r_poly.size(); ++i){
    cout<<r_poly[i]<<endl; 
  }
  return 0;
}
