#include <bits/stdc++.h>

using namespace std;

class vec2{
  public:
    double x;
    double y;
    vec2():x(0.0), y(0.0){};
    vec2(double val):x(val), y(val){};
    vec2(double x, double y):x(x), y(y){};
    ~vec2(){};
    vec2 operator=(vec2);
    vec2 operator+(vec2);
    vec2 operator-(vec2);
    vec2 operator*(double);
    bool operator==(vec2);
    bool operator !=(vec2);
};

vec2 vec2::operator=(vec2 b)
{
  this->x = b.x;
  this->y = b.y;
  return *this;
}

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

bool ascendy(const vec2& a, const vec2& b)
{
  if(a.y == b.y){return a.x > b.x;}
  return a.y > b.y;
}

bool descendy(const vec2& a,const vec2& b)
{
  if(a.y == b.y){return a.x < b.x;}
  return a.y < b.y;
}

bool ascendx(const vec2& a, const vec2& b)
{
  if(a.x == b.x){return a.y > b.y;}
  return a.x > b.x;
}

bool descendx(const vec2& a,const vec2& b)
{
  if(a.x == b.x){return a.y < b.y;}
  return a.x < b.x;
}

void swap(vec2* a, vec2* b)
{
  vec2 tmp;
  tmp = *a;
  *b = *a;
  *b = tmp;
}
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

vec2 projection(vec2 n, vec2 p0, vec2 p2)
{
  vec2 v;
  v = p2 - p0;

  n = normalize(n);
  vec2 res = n*dot(v, n) + p0;
  return res;
}

vec2 next(vector<vec2>& vec, int idx)
{
  if(idx+1 >= vec.size()){return vec[0];}
  return vec[idx+1];
}
vec2 past(vector<vec2>& vec, int idx)
{
  if(idx-1 < 0){return vec[vec.size()-1];}
  return vec[idx-1];
}
bool intersectLP(vec2 a, vec2 b, vec2 p)
{
  if(a == p || b == p){return true;}
  return cross(b - a, p - a) == 0
    && norm(b-a) >= norm(p-a)
    && dot(b-a, p-a) > 0;
}
int intersectLL(vec2 p1, vec2 p2, vec2 p3, vec2 p4)
{
  vec2 line1 = p2 - p1, line2 = p4 - p3;
  if(intersectLP(p1, p2, p3) || intersectLP(p1, p2, p4)){return 1;}
  else if(intersectLP(p3, p4, p1) || intersectLP(p3, p4, p2)){return 2;}
  else if((cross(line1, p3 - p1)*cross(line1, p4 - p1) < 0) &&
      (cross(line2, p1 - p3)*cross(line2, p2 - p3) < 0)){return 3;}
  else{return 0;}
}

double smallDis(vector<vec2>& p, int l, int r)
{
  double dmin = FLT_MAX;
  for(int i = l; i < r; i++){
    for(int j = i+1; j < r; j++){
      dmin = min(dmin, norm(p[i] - p[j]));
    }
  }
  return dmin;
}

double findMinDis(vector<vec2>& px, int l, int r)
{
  if(r-l <= 3 ){return smallDis(px, l, r);}
  int m = (l+r)/2.0;
  //@comment To get points around the middle point, save it before sorting
  vec2 mp = px[m];
  double disL = findMinDis(px, l, m);
  double disR = findMinDis(px, m+1, r);
  double d = min(disL, disR);
  //@comment Sort points between l and r in y-direction ascendly
  sort(px.begin()+l, px.begin()+r, descendy);

  vector<vec2> strip;
  for(int i = l; i < r; i++){
    if(fabs(mp.x - px[i].x) >= d){continue;}
    for(int j = 0; j < strip.size(); j++){
      if(px[i].y - strip[strip.size()-1 - j].y >= d){break;}
      d = min(d, norm(strip[strip.size()-1 - j] - px[i]));
    }
    strip.push_back(px[i]);
  }
  return d;
}

double closestPair(vector<vec2>& points)
{
  sort(points.begin(), points.end(), descendx);
  return findMinDis(points, 0, points.size());
}

int main(){
  vector<vec2> points;
  vec2 point;
  int count;
  cin>>count;
  for(int i = 0; i < count; i++){
    cin>>point.x>>point.y;
    points.push_back(point);
  }
  closestPair(points);
  cout<<setprecision(11);
  cout<<fixed<<closestPair(points)<<endl;

  return 0;
}
