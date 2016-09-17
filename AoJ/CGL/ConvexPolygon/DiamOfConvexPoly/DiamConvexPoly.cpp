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
	vec2 operator=(const vec2&);
	vec2 operator+(const vec2&) const;
	vec2 operator-(const vec2&) const;
	vec2 operator*(const float) const;
	bool operator==(const vec2&) const;
	bool operator !=(const vec2&) const;
};

vec2 vec2::operator=(const vec2& b)
{
	this->x = b.x;
	this->y = b.y;
	return *this;
}

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

vec2 vec2::operator*(const float m) const
{
	return vec2(m*this->x, m*this->y);
}

bool vec2::operator==(const vec2& b) const
{
	if(this->x == b.x && this->y == b.y){return true;}
	return false;
}

bool vec2::operator!=(const vec2& b) const
{
	return !(*this == b);
}

bool ascendy(const vec2& a, const vec2& b)
{
	if(a.y == b.y){return a.x < b.x;}
	return a.y > b.y;
}

bool descendy(const vec2& a,const vec2& b) 
{
	if(a.y == b.y){return a.x < b.x;}
	return a.y < b.y;
}

bool ascendx(const vec2& a, const vec2& b)
{
	if(a.x == b.x){return a.y < b.y;}
	return a.x > b.x;
}

bool descendx(const vec2& a,const vec2& b) 
{
	if(a.x == b.x){return a.y < b.y;}
	return a.x < b.x;
}

int next(int idx, int size)
{
  return idx%size;
}
void swap(vec2& a, vec2& b)
{
	vec2 tmp;
	tmp = a;
	b = a;
	b = tmp;
}

double normSq(const vec2& a)
{
  return a.x*a.x + a.y*a.y;
}

double norm(vec2 a)
{
  return sqrt(normSq(a));
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
vector<vec2> convexHull(vector<vec2>& points)
{
	unsigned int size = points.size();
	vector<vec2> res;
	int index = 0;
	int count;
	
  //@comment sort the points by y-axis
	sort(points.begin(), points.end(), descendy);

	//@comment Search right-hand side 
	vec2 a, b;
	res.push_back(points[0]);
	res.push_back(points[1]);
	for(int i = 2; i < size; ++i){
		for(int n = res.size()-1; n >= 1; --n){
			a = res[n] - res[n-1];
			b = points[i] - res[n];
			if(cross(a, b) > 0){ //@comment Not rigt convex
				// cout<<"Popped "<<res.back().x<<" "<<res.back().y<<endl;
				res.pop_back();
			}
		}
		res.push_back(points[i]);
	}

	//@comment Search left-hand side 
	vector<vec2> l;
	l.push_back(points[size-1]);
	l.push_back(points[size-2]);
	for(int i = size-3; i >= 0; --i){
		for(int n = l.size()-1; n >= 1; --n){
			a = l[n] - l[n-1];
			b = points[i] - l[n];
			// cout<<i<<": "<<points[i].x<<" "<<points[i].y<<endl;
			if(cross(a, b) > 0){ //@comment Not left convex
				// cout<<"Popped "<<l.back().x<<" "<<l.back().y<<endl;
				l.pop_back();
			}
		}
		l.push_back(points[i]);
	}

	//@comment Merge right and left convex
	for(int i = 1; i < l.size()-1; i++){res.push_back(l[i]);}

	//@comment CW to CCW 
	for(int i = 1; i <= res.size()/2; i++){
		vec2 tmp = res[i];
		res[i] = res[res.size()-i];
		res[res.size()-i] = tmp;
	}
	return res;
}

double findDiamConvex(const vector<vec2>& points)
{
  double dis = 0.0;
  int n = points.size();
  int p, q;

  //@comment find points which is at top and bottom along y-axis
  double tmpMin = FLT_MAX, tmpMax = FLT_MIN;
  for(int i = 0; i < n; ++i){
    if(points[i].y < tmpMin){
      tmpMin = points[i].y;
      p = i;
    }
    if(points[i].y > tmpMax){
      tmpMax = points[i].y;
      q = i;
    }
  }

  //@comment find the dis of first point-pair 
  dis = normSq(points[p]-points[q]); 
  int fp = p, fq = q;

  //@comment find the point-pair by rotating the line 
  do{
    int np = next(p+1, n), nq = next(q+1, n);
    double sign = cross(points[np] - points[p], points[nq] - points[q]);
    if(sign < 0){
      dis = max(dis, normSq(points[np]-points[q]));
      p = np;
    }else if(sign > 0){
      dis = max(dis, normSq(points[p]-points[nq]));
      q = nq;
     }else{
      dis = max(dis, normSq(points[np]-points[nq]));
      p = np;
      q = nq;
    }
  }while(!(p == fq && q == fp));

  return sqrt(dis);
}

int main(){
	vector<vec2> points;
	double res;
	vec2 point;
	int count;
	cin>>count;
	for(int i = 0; i < count; i++){
		cin>>point.x>>point.y;
		points.push_back(point);
	}
	// res = findDiamConvex(convexHull(points));
	res = findDiamConvex((points));
  cout<<setprecision(13)<<res<<endl;
	return 0;
}
