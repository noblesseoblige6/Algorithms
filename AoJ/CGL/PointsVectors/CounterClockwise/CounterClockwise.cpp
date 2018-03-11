#include <bits/stdc++.h>

using namespace std;

struct Point{
  double x;
  double y;
};

double norm(Point a)
{
return sqrt(a.x*a.x + a.y*a.y);
}

double dot(Point a, Point b)
{
  return a.x*b.x + a.y*b.y;
}

double cross_z(Point a, Point b)
{
  return a.x*b.y - a.y*b.x;
}

int judge_wise(Point p0,Point p1,Point p2)
{
  Point a, b;
  a.x = p1.x - p0.x;
  a.y = p1.y - p0.y;
  b.x = p2.x - p0.x;
  b.y = p2.y - p0.y;

  int wise = cross_z(a, b);
  if(wise > 0){return 1;}
  else if(wise < 0){return 2;}
  else{
    if(dot(a, b) < 0){return 3;}
    else{
    if(norm(a) < norm(b)){return 4;}
    else{return 5;}
    }
  }
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
    int res = judge_wise(p1, p2, p3[i]);
    switch(res){
      case 1:
        cout<<"COUNTER_CLOCKWISE"<<endl;
        break;
      case 2:
        cout<<"CLOCKWISE"<<endl;
        break;
      case 3:
        cout<<"ONLINE_BACK"<<endl;
        break;
      case 4:
        cout<<"ONLINE_FRONT"<<endl;
        break;
      default:
        cout<<"ON_SEGMENT"<<endl;
        break;
    }
  }
  return 0;
}

