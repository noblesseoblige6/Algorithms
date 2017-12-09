#include <bits/stdc++.h>

using namespace std;

class vec2{
  public:
    double x;
    double y;
    vec2():x(0.0), y(0.0){};
    vec2(double x, double y):x(x), y(y){};
    ~vec2(){};
    vec2 operator+(const vec2&) const;
    vec2 operator-(const vec2&) const;
    vec2 operator*(double);
    bool operator==(vec2);
    bool operator !=(vec2);
    friend ostream& operator<<(ostream& os, const vec2& v){
    os<<"("<<v.x<<", "<<v.y<<")";
    return os;
    }
};

vec2 vec2::operator+(const vec2& b) const
{
  vec2 res;
  res.x = this->x + b.x;
  res.y = this->y + b.y;
  return res;
}

vec2 vec2::operator-(const vec2& b) const
{
  vec2 res;
  res.x = this->x - b.x;
  res.y = this->y - b.y;
  return res;
}

vec2 vec2::operator*(double m)
{
  return vec2(m*this->x, m*this->y);
}

bool vec2::operator==(vec2 b)
{
  if(this->x == b.x && this->y == b.y){return true;}
  return false;
}

bool vec2::operator!=(vec2 b)
{
  return !(*this == b);
}


const double eps = 1e-8;
double norm(vec2 a)
{
  return sqrt(a.x*a.x + a.y*a.y);
}

vec2 normalize(vec2 a)
{
  vec2 res;
  double len = norm(a);
  if(len != 0.0){
    res.x = a.x/len;
    res.y = a.y/len;
  }
  else{
    res.x = 0.0f;
    res.y = 0.0f;
  }
  return res;
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

  return (cross(line1, p3 - p1)*cross(line1, p4 - p1) < 0) && (cross(line2, p1 - p3)*cross(line2, p2 - p3) < 0);
}

vec2 findCrossPoint(vec2 p0, vec2 p1, vec2 p2, vec2 p3)
{
  vec2 base = p1 - p0;
  vec2 cSeg = p3 - p2;
  vec2 s1 = p0 - p2;
  vec2 s2 = p1 - p3;

  //@comment Find the height from base vector to p2 and p3
  //@comment To reduce error, dividing by norm is ommited
  // double d1 = abs(cross(cSeg, s1))/norm(base);
  // double d2 = abs(cross(cSeg, s2))/norm(base);
  double d1 = abs(cross(cSeg, s1));
  double d2 = abs(cross(cSeg, s2));

  //@comment Accroding to the ratio, t:(1-t) = d1:d2
  return  d1+d2 == 0 ? p0 : p0 + base * (d1/(d1+d2));
}

double findConvexArea(const vector<vec2>& polygon)
{
    double area = 0.0;
    for(int i = 1; i < polygon.size()-1; ++i){
      vec2 a = polygon[i] - polygon[0];
      vec2 b = polygon[i+1] - polygon[0];
      area += abs(cross(a, b))*0.5 < eps ? 0.0 : abs(cross(a, b))*0.5;
    }
    return area;
}

vector<double> findConvexCut(const vector<vec2>& convex, const vector<pair<vec2, vec2> >& lines)
{
  vector<double> res;
  res.reserve(lines.size());

  for(int k = 0; k < lines.size(); ++k)
  {
    //@comment find far points to create a segment
    vec2 dir = normalize(lines[k].second - lines[k].first);

    const int scale = 100000;
    vec2 end = dir * scale  + lines[k].first;
    vec2 start = dir * -scale + lines[k].first;

    //@comment find two intersections
    vec2 segment = normalize(end - start);
    vector<vec2> cutConvex;
    cutConvex.reserve(convex.size());

    //@comment For detection second inter.occurs last segment, loop one more
    const int size = convex.size();
    for(int i = 0; i < size; ++i)
    {
      vec2 tmp = normalize(convex[i] - start);

      //@comment determine if i-th vertex is on left-hand side by edge and cutting segment
      if(cross(segment, tmp) >= 0)
      {
        cutConvex.push_back(convex[i]);
      }

      //@comment check if an intersection occurs with cutting segment
      if(intersectLL(convex[i], convex[(i+1)%size], start, end))
      {
        vec2 tmp = findCrossPoint(convex[i], convex[(i+1)%size], start, end);
        
        //@comment avoid miss judge that the same point is intersection
        if(tmp == convex[i] || tmp == convex[(i+1)%size]) 
        {
          continue;
        }

        cutConvex.push_back(tmp);
      }
    }

    res.push_back(findConvexArea(cutConvex));
  }

  return res;
}

int main(){
  int count;
  vec2 p;
  vector<vec2> convex;
  pair<vec2, vec2> points;
  vector<pair<vec2, vec2> >lines;

  cin>>count;
  for(int i = 0; i < count; i++){
    cin>>p.x>>p.y;
    convex.push_back(p);
  }
  cin>>count;
  for(int i = 0; i < count; i++){
    cin>>points.first.x>>points.first.y;
    cin>>points.second.x>>points.second.y;
    lines.push_back(points);
  }
  cout << fixed;
  vector<double> res = findConvexCut(convex, lines);
  for(int i = 0; i < res.size(); ++i){cout<<setprecision(8)<<res[i]<<endl;}
  return 0;
}

