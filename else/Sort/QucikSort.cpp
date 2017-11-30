#include <bits/stdc++.h>
using namespace std;
namespace acLib
{
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

template <typename T>
void swap(T &a, T &b)
{
  T tmp = a;
  a = b;
  b = tmp;
}
}
namespace acLib
{
namespace Sort
{
template <typename T>
void partition(vector<T> &arr, int& lAxis, int& rAxis)
{
  const int m = (lAxis+rAxis)/2;
  const T p = arr[m];

  while (1)
  {
    // 基準値以内・以上を検索
    while (arr[lAxis] < p){++lAxis;}
    while (arr[rAxis] > p){--rAxis;}

    // 軸が交差した場合終了
    if (lAxis >= rAxis)
    {
      break;
    }

    // 交換
    if (arr[lAxis] >= p && arr[rAxis] <= p)
    {
      acLib::swap(arr[lAxis], arr[rAxis]);
      ++lAxis;
      --rAxis;
    }
  }
}

template <typename T>
void quickSort(vector<T> &arr, const int l, const int r)
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
}
}

int main()
{
  int count;
  cin >> count;

  int a, b;
  vector<acLib::vec2> array;
  for (int i = 0; i < count; i++)
  {
    cin >> a >> b;
    array.push_back(acLib::vec2(a, b));
  }

  acLib::Sort::quickSort(array, 0, array.size() - 1);

  for (int i = 0; i < count; i++)
  {
    cout << array[i].x <<" " << array[i].y << endl;
  }

  return 0;
}