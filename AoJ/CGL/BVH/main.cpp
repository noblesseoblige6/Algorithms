#include<bits/stdc++.h>
#include "BVH.h"

using namespace std;

int main()
{
  BVH bvh;
  int n;
  double x, y ,z;
  vector<Triangle> data;
  cin>>n;
  for(int i=0; i < n; ++i){
    vec3<double> v[3];
    for(int j=0; j < 3; ++j){
      cin>>x>>y>>z;
      v[j] = vec3<double>(x, y, z);
    }
    data.push_back(Triangle(i, v[0], v[1], v[2]));
  }
  bvh.construct(data);
  bvh.check();

  return 0;
}
