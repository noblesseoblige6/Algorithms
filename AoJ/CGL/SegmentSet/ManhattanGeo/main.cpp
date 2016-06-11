#include <bits/stdc++.h>

using namespace std;

struct vec2{
  public:
    double x;
    double y;
    vec2():x(0), y(0){};
    vec2(double _x, double _y) : x(_x), y(_y){};
    ~vec2(){};
    vec2 operator+(vec2);
    vec2 operator-(vec2);
    bool operator<(const vec2& b) const
    {
      if(y == b.y)
        return x < b.x;
      return y < b.y;
    }
    bool operator<=(const vec2& b) const
    {
      return y <= b.y;
    }

    bool operator==(vec2) const;
    friend ostream& operator<<(ostream& os, const vec2& v)
    {
      os<<v.x<<" "<<v.y;
      return os;
    }
};

vec2 vec2::operator+(vec2 b)
{
  vec2 res;
  res.x = this->x + b.x;
  res.y = this->y + b.y;
  return res;
}

vec2 vec2::operator-(vec2 b)
{
  vec2 res;
  res.x = this->x - b.x;
  res.y = this->y - b.y;
  return res;
}

bool vec2::operator==(vec2 b) const
{
  return (x == b.x && y == b.y);
}
const float eps = 1e-8;

double norm(vec2 p)
{
  return sqrt(p.x*p.x + p.y*p.y);
}

double dot(vec2 a, vec2 b)
{
  return a.x*b.x + a.y*b.y;
}
double cross(vec2 a, vec2 b)
{
  return a.x*b.y - a.y*b.x;
}

bool intersectLP(vec2 a, vec2 b, vec2 p)
{
  if(a == p){return true;}
  if(b == p){return true;}
  return cross(b - a, p - a) == 0
    && norm(b-a) >= norm(p-a)
    && dot(b-a, p-a) > 0;
}
bool intersectLL(vec2 p1, vec2 p2, vec2 p3, vec2 p4)
{
  vec2 line1 = p2 - p1;
  vec2 line2 = p4 - p3;
  if(intersectLP(p1, p2, p3)){ return true;}
  if(intersectLP(p1, p2, p4)){ return true;}
  if(intersectLP(p3, p4, p1)){ return true;}
  if(intersectLP(p3, p4, p2)){ return true;}

  return (cross(line1, p3 - p1)*cross(line1, p4 - p1) < 0)
    && (cross(line2, p1 - p3)*cross(line2, p2 - p3) < 0);
}

struct Point
{
  vec2 p;
  int id;
  Point(const vec2& _p, int _id) : p(_p), id(_id){}

  bool operator<(const Point& b) const
  {
    return p < b.p;
  }
  bool operator!=(const Point& b) const
  {
    return !(*this == b);
  }
  bool operator==(const Point& b) const
  {
    return p == b.p && id == b.id;
  }
  friend ostream& operator<<(ostream& os, const Point& p)
  {
    os<<p.p<<", "<<p.id;
    return os;
  }
};

int segmentIntersection(const vector<Point>& p, const vector<vec2>& s, const vector<vec2>& e)
{
  int nIntersec = 0;

  //@comment Sort decsendly by y-axis
  sort(p.begin(), p.end());

  set<Point> tree;
  vector<Point> h_points;
  for(int i = 0; i < p.size(); ++i){
    int id = p[i].id;
    //@comment horizontal segment
    if(s[id].y == e[id].y){
      h_points.push_back(p[i]);
    }else if(s[id] == p[i].p){
      tree.insert(p[i]);
    }
  }

  for(int i = 0; i < h_points.size(); ++i){
    int id = h_points[i].id;
    vector<Point> passedPoints;
    set<Point>::iterator begin = tree.lower_bound(*tree.begin());
    set<Point>::iterator end = tree.upper_bound(h_points[i]);
    for(set<Point>::iterator it = begin; it != end; ++it){
      int tmpIdx = it->id;
      if(e[tmpIdx].y < e[id].y)
        passedPoints.push_back(Point(s[tmpIdx], tmpIdx));
      else if(intersectLL(s[tmpIdx], e[tmpIdx], s[id], e[id]))
        nIntersec++;
    }

    //@comment After searching, remove passed points
    tree.erase(passedPoints.begin(), passedPoints.end());
  }
  return nIntersec;
}

int main(int argc, char* argv[])
{
  int n;
  int x1, y1;
  int x2, y2;
  cin>>n;
  vector<Point> points;
  vector<vec2> s, e;
  for(int i = 0; i < n; i++){
    cin>>x1>>y1>>x2>>y2;
    if(y1 < y2){
      s.push_back(vec2(x1, y1));
      e.push_back(vec2(x2, y2));
      points.push_back(Point(vec2(x1, y1), i));
      points.push_back(Point(vec2(x2, y2), i));
    }
    else if(y1 > y2){
      s.push_back(vec2(x2, y2));
      e.push_back(vec2(x1, y1));
      points.push_back(Point(vec2(x1, y1), i));
      points.push_back(Point(vec2(x2, y2), i));
    }
    else{
      if(x1 < x2){
        s.push_back(vec2(x1, y1));
        e.push_back(vec2(x2, y2));
        points.push_back(Point(e.back(), i));
      }
      else{
        s.push_back(vec2(x2, y2));
        e.push_back(vec2(x1, y1));
        points.push_back(Point(e.back(), i));
      }
    }
  }
  cout<<segmentIntersection(points, s, e)<<endl;
  return 0;
}
