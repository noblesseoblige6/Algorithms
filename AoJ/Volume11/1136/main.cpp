#include<bits/stdc++.h>
using namespace std;

const int Plus = 1;
const int Minus = -1;

double Cross(int xa, int ya, int xb, int yb)
{
  return xa*yb - xb*ya;
}

bool IsSameDisplacement(const vector<int>& a, const vector<pair<int, int> >& b)
{

}

bool IsSameDirection(const vector<int>& a, const vector<pair<int, int> >& b)
{

}

bool IsSame(const vector<int>& a, const vector<int>& b, const vector<pair<int, int> >& c)
{
 return IsSameDisplacement(a, c) && IsSameDirection(b, c);
}


void FindSameSegment(const vector<vector<pair<int, int> > >& set, vector<int>& ids)
{
  int n = set.size();
  vector<int> disp;
  vector<int> dirc;
  for(int i = 1; i < n; ++i)
  {
    pair<int, int> v(set[0][i].first - set[0][i-1].first, set[0][i].second - set[0][i-1].second);
    disp.push_back(sqrt(v.first*v.first + v.second*v.second));
  }

  pair<int, int> v1;
  pair<int, int> v2;
  for(int i = 2; i < n; ++i)
  {
    v1 = pair<int, int>(set[0][i-1].first - set[0][i-2].first, set[0][i-1].second - set[0][i-2].second);
    v2 = pair<int, int>(set[0][i].first - set[0][i-1].first, set[0][i].second - set[0][i-1].second);

    dirc.push_back(Cross(v1.first, v1.second, v2.first, v2.second));
  }

  for(int i = 1; i < n; ++i)
  {
    if(IsSame(disp, dirc, set[i]))
    {
      ids.push_back(i);
    }
  }
}
int main()
{
  int n, m;
  while(1)
  {
    cin >> n;
    if(n == 0)
      break;

    n+=1;
    vector<vector<pair<int, int> > > orders(n);
    for(int i = 0; i < n; ++i)
    {
      cin >> m;

      orders[i].resize(m);

      pair<int, int> c;
      for(int j = 0; j < m; ++j)
      {
        cin >> c.first >> c.second;
        orders[i][j] = c;
      }
    }
    vector<int> ids;
    FindSameSegment(orders, ids);
    for(int i = 0; i < ids.size(); ++i)
      cout<<ids[i]<<endl;
    cout<<"+++++"<<endl;
  }
  return 0;
}
