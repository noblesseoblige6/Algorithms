#include<bits/stdc++.h>
using namespace std;

class vec2{
public:
  double x;
  double y;
  vec2():x(0.0), y(0.0){};
  vec2(double val):x(val), y(val){};
  vec2(double x, double y):x(x), y(y){};
  vec2(const vec2& v) : x(v.x), y(v.y){};
  ~vec2(){};
  vec2& operator=(const vec2&);
  vec2 operator+(const vec2&) const;
  vec2 operator-(const vec2&) const;
  vec2 operator*(float);
  bool operator==(vec2);
  bool operator !=(vec2);
  bool operator <(vec2);
};

vec2& vec2::operator=(const vec2& b)
{
  x = b.x;
  y = b.y;
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

bool vec2::operator <(vec2 b)
{
  return this->y == b.y ? this->x < b.x : this->y < b.y;    
}


vector<vec2> parseAndMerge(vector<vec2>& in, int l, int r)
{
  if(l >= r)
    {
      return vector<vec2>(1, in[r]);
    }

  int m = (l+r)/2;

  //@comment Parse vector
  vector<vec2> lVec = parseAndMerge(in, l, m);
  vector<vec2> rVec = parseAndMerge(in, m+1, r);

  //@comment Merge parsed vectors
  int size = lVec.size() + rVec.size();
  vector<vec2> res;
  for(int lCount = 0, rCount = 0; lCount+rCount < size;)
  {
    if(rCount >= rVec.size())
    {
      res.push_back(lVec[lCount]);
      lCount++;
    }
    else if(lCount >= lVec.size())
    {
      res.push_back(rVec[rCount]);
      rCount++;
    }
    else if(lVec[lCount] < rVec[rCount])
    {
      res.push_back(lVec[lCount]);
      lCount++;
    }
    else
    {
      res.push_back(rVec[rCount]);
      rCount++;
    }
  }
  return res;
}

vector<vec2> mergeSort(vector<vec2>& in)
{
  //@comment To avoid refering to out of the index, 
  //the size of vector should be size-1
  return parseAndMerge(in, 0, in.size()-1);
}

int main()
{
  int count;
  cin>>count;

  int a, b;  
  vector<vec2> pair;
  for(int i = 0; i < count; i++)
  {
    cin>>a>>b;
    pair.push_back(vec2(a, b));
  }

  vector<vec2> res = mergeSort(pair);
  for(int i = 0; i < count; i++)
  {
    cout<<res[i].x<<" "<<res[i].y<<endl;
  }

  return 0;
}