#include<bits/stdc++.h>
using namespace std;
const int BLACK = 0;
const int RED = 1;
const int VISITED = 3;

int FindMovableTiles(const vector<vector<int> >& tiles, int x, int y, int w, int h)
{
  int count = 0;
  queue<pair<int, int> > q;

  q.push(pair<int, int>(x, y));
  while(!q.empty())
  {
    pair<int, int> coord = q.front();
    int x = coord.first;
    int y = coord.second;
    int xl = coord.first-1;
    int xr = coord.first+1;
    int yu = coord.second-1;
    int yd = coord.second+1;

    if(xl >= 0)
    {
      if(tiles[xl][y] != RED && tiles[xl][y] != VISITED)
        q.push(pair<int, int>(xl, y));
    }
    if(yu < h)
    {
      if(tiles[x][yu] != RED && tiles[x][yu] != VISITED)
        q.push(pair<int, int>(x, yu));
    }
    if(xr < w)
    {
      if(tiles[xr][y] != RED && tiles[xr][y] != VISITED)
        q.push(pair<int, int>(xr, y));
    }
    if(yd >= 0)
    {
      if(tiles[x][yd] != RED && tiles[x][yd] != VISITED)
        q.push(pair<int, int>(x, yd));
    }
    count++;
  }

  return count;
}

int main()
{
  int w, h;
  int sx, sy;
  cin >> w >> h;

  vector<vector<int> > tiles(w, vector<int>(h));
  char sign;
  for(int j = 0; j < h; ++j)
  {
    for(int i = 0; i < w; ++i)
    {
      cin >> sign;
      if(sign == '.')
      {
        tiles[i][j] = BLACK;
      }
      else if(sign == '#')
      {
        tiles[i][j] = RED;
      }
      else
      {
        tiles[i][j] = VISITED;
      }
    }
  }
  cout<<FindMovableTiles(tiles, sx, sy, w, h)<<endl;
  return 0;
}
