#include <bits/stdc++.h>

using namespace std;

struct Point{
  double x;
  double y;
};

const int eps = 1e-10;

double norm(Point a)
{
return sqrt(a.x*a.x + a.y*a.y);
}

Point normalize(Point a)
{
  Point res;
  double len = norm(a);
  if(len != 0.0){
    res.x = a.x/len;
    res.y = a.y/len;
  }
  else{
    res.x = 0.0;
    res.y = 0.0;
  }
  return res;
}

double dot(Point a, Point b)
{
  return a.x*b.x + a.y*b.y;
}

Point reflect(Point p0,Point p1,Point p2)
{
  Point v, n;
  v.x = p2.x - p0.x;
  v.y = p2.y - p0.y;
  n.x = p1.x - p0.x;
  n.y = p1.y - p0.y;

  n = normalize(n);
  Point res;
  res.x = (-v.x + 2*(dot(v, n))*n.x)+p0.x;
  res.y = (-v.y + 2*(dot(v, n))*n.y)+p0.y;
  return res;
}

int main(){
  Point p1;
  Point p2;
  vector<Point> p3;
  int count;
  Point tmp;

  cin>>p1.x>>p1.y>>p2.x>>p2.y;
  cin>>count;

  for(int i = 0; i < count; i++){
    cin>>tmp.x>>tmp.y;
    p3.push_back(tmp);
  }
  for(int i = 0; i < count; i++){
    Point res = reflect(p1, p2, p3[i]);
    cout<<endl<<fixed<<setprecision(8)<<res.x<<" "<<res.y<<endl;
  }
  return 0;
}

