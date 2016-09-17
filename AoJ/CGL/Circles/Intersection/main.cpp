#include<bits/stdc++.h>

using namespace std;

int CircleIntersection(int x1, int y1, int r1, int x2, int y2, int r2)
{

  int x = abs(x1 - x2);
  int y = abs(y1 - y2);
  double d = sqrt(x*x + y*y);

  // No intersection
  if(r1+r2 < d)
  {
    return 4;
  }
  else if(r1+r2 == d)
  {
    // Externally
    return 3;
  }
  else if(r1+r2 > d)
  {
    if(abs(r1-r2) < d)
    {
      // Intersection
      return 2;
    }
    else if(abs(r1-r2) == d)
    {
      // Incribed
      return 1;
    }
    else
    {
      // Comprehension
      return 0;
    }
  }
}

int main()
{
  int r1, r2;
  int x1, x2, y1, y2;

  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;

  cout<<CircleIntersection(x1, y1, r1, x2, y2, r2)<<endl;

  return 0;
}
