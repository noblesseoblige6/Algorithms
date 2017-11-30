#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

class vec2
{
public:
  double x;
  double y;
  vec2() : x(0.0), y(0.0){};
  vec2(double val) : x(val), y(val){};
  vec2(double x, double y) : x(x), y(y){};
  vec2(const vec2 &v) : x(v.x), y(v.y){};
  ~vec2(){};
  vec2 &operator=(const vec2 &);
  vec2 operator+(const vec2 &) const;
  vec2 operator-(const vec2 &) const;
  vec2 operator*(const float);
  bool operator==(const vec2 &);
  bool operator!=(const vec2 &);
  bool operator<(const vec2 &);
  bool operator>(const vec2 &);
  bool operator<=(const vec2 &);
  bool operator>=(const vec2 &);
};
vec2 &vec2::operator=(const vec2 &b)
{
  x = b.x;
  y = b.y;
  return *this;
}

vec2 vec2::operator+(const vec2 &b) const
{
  vec2 res;
  res.x = this->x + b.x;
  res.y = this->y + b.y;
  return res;
}

vec2 vec2::operator-(const vec2 &b) const
{
  vec2 res;
  res.x = this->x - b.x;
  res.y = this->y - b.y;
  return res;
}

vec2 vec2::operator*(const float m)
{
  return vec2(m * this->x, m * this->y);
}

bool vec2::operator==(const vec2 &b)
{
  if (this->x == b.x && this->y == b.y)
  {
    return true;
  }
  return false;
}

bool vec2::operator!=(const vec2 &b)
{
  return !(*this == b);
}

bool vec2::operator<(const vec2 &b)
{
  return this->y == b.y ? this->x < b.x : this->y < b.y;
}

bool vec2::operator>(const vec2 &b)
{
  return this->y == b.y ? this->x > b.x : this->y > b.y;
}

bool vec2::operator<=(const vec2 &b)
{
  return this->y <= b.y;
}

bool vec2::operator>=(const vec2 &b)
{
  return this->y >= b.y;
}

bool ascendy(const vec2 &a, const vec2 &b)
{
  return a.y == b.y ? a.x < b.x : a.y < b.y;
}

bool descendy(const vec2 &a, const vec2 &b)
{
  return a.y == b.y ? a.x < b.x : a.y > b.y;
}

bool ascendx(const vec2 &a, const vec2 &b)
{
  if (a.x == b.x)
  {
    return a.y < b.y;
  }
  return a.x > b.x;
}

bool descendx(const vec2 &a, const vec2 &b)
{
  if (a.x == b.x)
  {
    return a.y < b.y;
  }
  return a.x < b.x;
}

int next(int idx, int size)
{
  if (idx >= size)
  {
    return idx - size;
  }
  return idx;
}

void swap(vec2 &a, vec2 &b)
{
  vec2 tmp = a;
  a = b;
  b = tmp;
}

float norm(vec2 a)
{
  return sqrt(a.x * a.x + a.y * a.y);
}
vec2 normalize(vec2 a)
{
  vec2 res;
  double len = norm(a);
  if (len != 0.0)
  {
    res.x = a.x / len;
    res.y = a.y / len;
  }
  else
  {
    res.x = 0.0f;
    res.y = 0.0f;
  }
  return res;
}

double dot(vec2 a, vec2 b)
{
  return a.x * b.x + a.y * b.y;
}

double cross(vec2 a, vec2 b)
{
  return a.x * b.y - a.y * b.x;
}

vec2 projection(vec2 n, vec2 p0, vec2 p2)
{
  vec2 v;
  v = p2 - p0;

  n = normalize(n);
  vec2 res = n * dot(v, n) + p0;
  return res;
}

vec2 next(vector<vec2> &vec, int idx)
{
  if (idx + 1 >= vec.size())
  {
    return vec[0];
  }
  return vec[idx + 1];
}

vec2 past(vector<vec2> &vec, int idx)
{
  if (idx - 1 < 0)
  {
    return vec[vec.size() - 1];
  }
  return vec[idx - 1];
}
bool intersectLP(vec2 a, vec2 b, vec2 p)
{
  if (a == p || b == p)
  {
    return true;
  }
  return cross(b - a, p - a) == 0 && norm(b - a) >= norm(p - a) && dot(b - a, p - a) > 0;
}
int intersectLL(const vec2 &p1, const vec2 &p2, const vec2 &p3, const vec2 &p4)
{
  vec2 line1 = p2 - p1, line2 = p4 - p3;
  if (intersectLP(p1, p2, p3) || intersectLP(p1, p2, p4))
  {
    return 1;
  }
  else if (intersectLP(p3, p4, p1) || intersectLP(p3, p4, p2))
  {
    return 2;
  }
  else if ((cross(line1, p3 - p1) * cross(line1, p4 - p1) < 0) &&
           (cross(line2, p1 - p3) * cross(line2, p2 - p3) < 0))
  {
    return 3;
  }
  else
  {
    return 0;
  }
}

vector<vec2> parseAndMerge(vector<vec2> &in, int l, int r)
{
  if (l >= r)
  {
    return vector<vec2>(1, in[r]);
  }

  int m = (l + r) / 2;

  //@comment Parse vector
  vector<vec2> lVec = parseAndMerge(in, l, m);
  vector<vec2> rVec = parseAndMerge(in, m + 1, r);

  //@comment Merge parsed vectors
  int size = lVec.size() + rVec.size();
  vector<vec2> res;
  for (int lCount = 0, rCount = 0; lCount + rCount < size;)
  {
    if (rCount >= rVec.size())
    {
      res.push_back(lVec[lCount]);
      lCount++;
    }
    else if (lCount >= lVec.size())
    {
      res.push_back(rVec[rCount]);
      rCount++;
    }
    else if (lVec[lCount] < rVec[rCount])
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

vector<vec2> mergeSort(vector<vec2> &in)
{
  //@comment To avoid refering to out of the index,
  //the size of vector should be size-1
  return parseAndMerge(in, 0, in.size() - 1);
}

int partition(vector<vec2> &arr, int &lAxis, int &rAxis)
{
  const int m = (lAxis + rAxis) / 2;
  const vec2 p = arr[m];

  while (1)
  {
    // 基準値以内・以上を検索
    while (arr[lAxis] < p)
    {
      ++lAxis;
    }
    while (arr[rAxis] > p)
    {
      --rAxis;
    }

    // 軸が交差した場合終了
    if (lAxis >= rAxis)
    {
      break;
    }

    // 交換
    if (arr[lAxis] >= p && arr[rAxis] <= p)
    {
      swap(arr[lAxis], arr[rAxis]);
      ++lAxis;
      --rAxis;
    }
  }
}

void quickSort(vector<vec2> &arr, int l, int r)
{
  if (l >= r)
  {
    return;
  }

  int lIdx = l, rIdx = r;
  partition(arr, lIdx, rIdx);

  // 検索範囲がある場合ソートを続行
  if (l < lIdx - 1)
  {
    quickSort(arr, l, lIdx - 1);
  }
  if (rIdx + 1 < r)
  {
    quickSort(arr, rIdx + 1, r);
  }
}

vector<vec2> findConvexHull(vector<vec2> &points)
{
  const int size = points.size();

  //@comment sort the vertices by y-axis
  quickSort(points, 0, size - 1);

  //@comment add first two vertices to create vector
  vector<vec2> rSide;
  rSide.push_back(points[0]);
  rSide.push_back(points[1]);

  //@comment Search right-hand side
  for (int i = 2; i < size; ++i)
  {
    for (int n = rSide.size() - 1; n >= 1; --n)
    {
      const vec2 &a = rSide[n] - rSide[n - 1];
      const vec2 &b = points[i] - rSide[n];

      //@comment omit vertices which is not on the right side
      if (cross(a, b) > 0)
      {
        rSide.pop_back();
      }
      else
      {
        break;
      }
    }
    rSide.push_back(points[i]);
  }

  //@comment add last two vertices to create vector
  vector<vec2> lSide;
  lSide.push_back(points[size - 1]);
  lSide.push_back(points[size - 2]);

  //@comment Search left-hand side
  for (int i = size - 3; i >= 0; --i)
  {
    for (int n = lSide.size() - 1; n >= 1; --n)
    {
      const vec2 &a = lSide[n] - lSide[n - 1];
      const vec2 &b = points[i] - lSide[n];

      //@comment omit the vertex which is not on the left side
      if (cross(a, b) > 0)
      {
        lSide.pop_back();
      }
      else
      {
        break;
      }
    }
    lSide.push_back(points[i]);
  }

  //@comment merge right and left side convexes
  vector<vec2> res;
  res.reserve(rSide.size() + lSide.size() - 2);
  for (int i = 0; i < rSide.size(); ++i)
  {
    res.push_back(rSide[i]);
  }
  //@comment omit first and last vertices
  for (int i = 1; i < lSide.size() - 1; ++i)
  {
    res.push_back(lSide[i]);
  }

  //@comment convert CW to CCW
  for (int i = 1; i <= res.size() / 2; ++i)
  {
    vec2 tmp = res[i];
    res[i] = res[res.size() - i];
    res[res.size() - i] = tmp;
  }

  return res;
}

int main()
{
  vector<vec2> points;
  vec2 point;

  int count;
  cin >> count;

  for (int i = 0; i < count; ++i)
  {
    cin >> point.x >> point.y;
    points.push_back(point);
  }

  vector<vec2> res;
  res = findConvexHull(points);

  cout << res.size() << endl;
  for (int i = 0; i < res.size(); ++i)
  {
    cout << res[i].x << " " << res[i].y << endl;
  }

  return 0;
}