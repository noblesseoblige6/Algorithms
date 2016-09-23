#include<bits/stdc++.h>
using namespace std;

double Cross(int xa, int ya, int xb, int yb)
{
  return xa*yb - xb*ya;
}

void FindDisplacement(const vector<pair<int, int> >& s, vector<int>& d)
{
  int n = s.size();
  for(int i = 1; i < n; ++i)
  {
    pair<int, int> v(s[i].first - s[i-1].first, s[i].second - s[i-1].second);
    d.push_back(abs(v.first+v.second));
  }
}

void FindDirection(const vector<pair<int, int> >& s, vector<int>& d)
{
  int n = s.size();
  pair<int, int> v1;
  pair<int, int> v2;
  for(int i = 2; i < n; ++i)
  {
    v1 = pair<int, int>(s[i-1].first - s[i-2].first, s[i-1].second - s[i-2].second);
    v2 = pair<int, int>(s[i].first - s[i-1].first, s[i].second - s[i-1].second);

    d.push_back(Cross(v1.first, v1.second, v2.first, v2.second));
  }
}

bool IsSameDispAndDirec(const vector<int>& a, const vector<int>& b, const vector<pair<int, int> >& c)
{
  vector<int> disp;
  vector<int> direc;

  FindDisplacement(c, disp);
  FindDirection(c, direc);

  bool isSame = true;
  for(int i = 0; i < disp.size(); ++i)
  {
    if(a[i] != disp[i])
    {
      isSame = false;
      break;
    }
  }
  if(isSame)
  {
    for(int i = 0; i < direc.size(); ++i)
    {
      if(b[i] != direc[i])
      {
        isSame = false;
        break;
      }
    }
    return isSame;
  }

  return false;
}
bool IsSame(const vector<int>& direc, const vector<int>& disp, const vector<pair<int, int> >& c)
{
  if(IsSameDispAndDirec(direc, disp, c))
  {
    return true;
  }

  vector<pair<int, int> > rc;
  copy(c.rbegin(), c.rend(), back_inserter(rc));

  if(IsSameDispAndDirec(direc, disp, rc))
  {
    return true;
  }
  return false;
}

void FindSameSegment(const vector<vector<pair<int, int> > >& set, vector<int>& ids)
{
  int n = set.size();
  vector<int> disp;
  vector<int> dirc;

  FindDisplacement(set[0], disp);
  FindDirection(set[0], dirc);

  for(int i = 1; i < n; ++i)
  {
    if(set[0].size() != set[i].size())
      continue;

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
