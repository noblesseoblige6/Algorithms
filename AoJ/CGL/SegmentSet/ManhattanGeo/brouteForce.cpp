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
    bool operator==(vec2);
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

bool vec2::operator==(vec2 b)
{
  if(this->x == b.x && this->y == b.y){return true;}
  return false;
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


struct Segment
{
  public:
    vec2 s;
    vec2 e;
    Segment(){};
    ~Segment(){};
    Segment(int x1, int y1, int x2, int y2)
    {
      s = vec2(x1, y1);
      e = vec2(x2, y2);
    }
    friend ostream& operator << (ostream& os, Segment a)
    {
      os << a.s.x << " " << a.s.y << " : "<< a.e.x << " " << a.e.y << endl;
      return os;
    }

    static bool descendY(Segment seg1, Segment seg2)
    {
      //@commnet If y-coordinates of the start points are the same,
      //sort by the high y-coordinate of the end points
      if(seg1.s.y == seg2.s.y){return seg1.e.x > seg2.e.x;}
      return seg1.s.y < seg2.s.y;
    }

    static bool ascendX(Segment seg1, Segment seg2)
    {
      //@commnet If y-coordinates of the start points are the same,
      //sort by the high y-coordinate of the end points
      if(seg1.s.x == seg2.s.x){return seg1.e.y > seg2.e.y;}
      return seg1.s.x > seg2.s.x;
    }

    static bool descendX(Segment seg1, Segment seg2)
    {
      //@commnet If y-coordinates of the start points are the same,
      //sort by the high y-coordinate of the end points
      if(seg1.s.x == seg2.s.x){return seg1.e.y > seg2.e.y;}
      return seg1.s.x < seg2.s.x;
    }
};

int segmentIntersection(vector<Segment>& v, vector<Segment>& h)
{
  //@comment if there are only vertical or horizontal, no intersections
  if(v.size() == 0 || h.size() == 0)
    return 0;

  int nIntersec = 0;
  sort(v.begin(), v.end(), Segment::descendX);
  sort(h.begin(), h.end(), Segment::descendX);

  for(int i = 0; i < v.size(); ++i){
    for(int j = 0; j < h.size(); ++j){
      if(intersectLL(h[j].s, h[j].e, v[i].s, v[i].e))
        nIntersec++;
    }
  }
  return nIntersec;
}

int main(int argc, char* argv[])
{
  int n;
  int x1, y1;
  int x2, y2;
  vector<Segment> in;
  vector<Segment> h_segments;
  vector<Segment> v_segments;
  vector<Segment> points;

  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>x1>>y1>>x2>>y2;
    if(x1 == x2 && y1 == y2){
      points.push_back(Segment(x1, y1, x2, y2));
    }
    else if(x1 == x2)
      v_segments.push_back(Segment(x1, y1, x2, y2));
    else if(y1 == y2){
      if(x1 > x2)
        h_segments.push_back(Segment(x2, y2, x1, y1));
      else
        h_segments.push_back(Segment(x1, y1, x2, y2));
    }
  }
  //@comment if there are points and no horizontal, points are handled as horizontal
  if(h_segments.size() == 0 && points.size() != 0)
    for(int i = 0; i < points.size(); ++i)
      h_segments.push_back(points[i]);

  cout<<segmentIntersection(v_segments, h_segments)<<endl;
  return 0;
}
