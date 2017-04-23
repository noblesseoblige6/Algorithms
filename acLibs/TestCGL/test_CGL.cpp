#include <iostream>
#include <iomanip>
#include <vector>
#include "../CGL.h"

using namespace std;
using namespace acLib::CGL;
using namespace acLib::vec;

int main()
{
  Vec2 p1, p2, tmp;
  vector<Vec2> p;
  int count;

  cin>>p1.x>>p1.y>>p2.x>>p2.y;
  cin>>count;

  for(int i = 0; i < count; i++){
    cin>>tmp.x>>tmp.y;
    p.push_back(tmp);
  }

  for(int i = 0; i < count; i++){
    Vec2 res = CGL::projection(p1, p2, p[i]);
    cout<<fixed<<setprecision(10)<<res.x<<" "<<res.y<<endl;
  }
  return 0;
}
