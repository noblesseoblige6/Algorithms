#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

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
	vec2 operator*(float);
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

vec2 vec2::operator*(float m)
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
	if(a.y == b.y){return a.x < b.x;}
	return a.y > b.y;
}

bool descendy(const vec2& a, const vec2& b) 
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
	if(idx >= size){return idx - size;}
	return idx;
}
void swap(vec2& a, vec2& b)
{
	vec2 tmp;
	tmp = a;
	b = a;
	b = tmp;
}
float norm(vec2 a)
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
vector<vec2> convexHull(vector<vec2>& points)
{
	unsigned int size = points.size();
	vector<vec2> res;
	int index = 0;
	int count;
	 for(int i = 0; i < points.size(); ++i)
	cout<<points[i].x<<" "<<points[i].y<<endl;
	cout<<endl<<endl;
	
	//@comment sort the points by y-axis
	sort(points.begin(), points.end(), descendy);

  for(int i = 0; i < points.size(); ++i)
    cout<<points[i].x<<" "<<points[i].y<<endl;
  cout<<endl<<endl;
	vec2 a, b;

	//@comment Search right-hand side 
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

int main(){
	vector<vec2> points;
	vector<vec2> res;
	vec2 point;
	int count;
	cin>>count;
	for(int i = 0; i < count; i++){
		cin>>point.x>>point.y;
		points.push_back(point);
	}
	res = convexHull(points);
	cout<<res.size()<<endl;
	for(int i = 0; i < res.size(); i++){ 
		cout<<res[i].x<<" "<<res[i].y<<endl;
	}
	return 0;
}
