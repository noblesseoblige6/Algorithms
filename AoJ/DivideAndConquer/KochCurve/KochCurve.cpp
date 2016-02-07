#include <bits/stdc++.h>
using namespace std;
class Point{
  public:
    double x;
    double y;
    Point():x(0.0), y(0.0){};
    Point(double x, double y):x(x), y(y){};
    ~Point(){};
    double norm();
    Point operator+(Point);
    Point operator-(Point);
    Point operator*(double);
    Point operator/(double);
};

Point Point::operator+(Point b)
{
  Point res;
  res.x = this->x + b.x;
  res.y = this->y + b.y;
  return res;
}

Point Point::operator-(Point b)
{
  Point res;
  res.x = this->x - b.x;
  res.y = this->y - b.y;
  return res;
}

Point Point::operator*(double m)
{
  return Point(m*this->x, m*this->y);
}

Point Point::operator/(double m)
{
  return Point(this->x/m, this->y/m);
}

double Point::norm()
{
  return sqrt(x*x + y*y);
}


vector<Point> kochCurve(Point s, Point e, int d, int pd)
{
  vector<Point> res;
  if(pd == 0){res.push_back(s);}
  if(d <= pd){
    res.push_back(e);
    return res;
  }

  double l = (e-s).norm();
  Point dir = (e-s)/l;
  Point normal(-(e-s).y/l, (e-s).x/l);
  Point lp, mp, rp;
  lp = dir*(l/3.0)+s;
  rp = dir*(2*l/3.0)+s;
  mp = dir*l*0.5 + normal*l*(sqrt(3)/6.0)+s;

  vector<Point> tmp;
  tmp = kochCurve(s, lp, d, pd+1);
  res.insert(res.end(), tmp.begin(), tmp.end());

  tmp = kochCurve(lp, mp, d, pd+1);
  res.insert(res.end(), tmp.begin(), tmp.end());

  tmp = kochCurve(mp, rp, d, pd+1);
  res.insert(res.end(), tmp.begin(), tmp.end());

  tmp = kochCurve(rp, e, d, pd+1);
  res.insert(res.end(), tmp.begin(), tmp.end());
  return res;
}

int main()
{
  int depth;
  Point s(0.0, 0.0), e(100.0, 0.0);
  vector<Point> points;  
  cin>>depth;
  points = kochCurve(s, e, depth, 0);
  for(int i = 0; i < points.size(); i++){
    cout<<fixed<<setprecision(8)<<points[i].x<<" "<<points[i].y<<endl;
  }
  return 0;
}
