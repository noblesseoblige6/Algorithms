#include<bits/stdc++.h>
#define PrintTest cout<<"TEST"<<endl;
using namespace std;
const int BLACK = 0;
const int RED = 1;
const int VISITED = 3;

int FindMovableTiles(vector<vector<int> >& tiles, int sx, int sy, int w, int h)
{
  int count = 0;
  queue<pair<int, int> > q;
  q.push(pair<int, int>(sx, sy));

  const pair<int, int> offsets[4] =
  {
    pair<int, int>(-1, 0),
    pair<int, int>(0, -1),
    pair<int, int>(1, 0),
    pair<int, int>(0, 1)
  };

  while(!q.empty())
  {
    pair<int, int> coord = q.front();
    q.pop();
    count++;

    int x = coord.first;
    int y = coord.second;

    for(int i = 0; i < 4; ++i)
    {
      int xoffset = x + offsets[i].first;
      int yoffset = y + offsets[i].second;

      if( (0 <= xoffset && xoffset < w) &&
          (0 <= yoffset && yoffset < h) )
      {
        if(tiles[xoffset][yoffset] == BLACK)
        {
          tiles[xoffset][yoffset] = VISITED;
          q.push(pair<int, int>(xoffset, yoffset));
        }
      }
    }
  }

  return count;
}

int main()
{
  int w, h;
  int sx, sy;

  while(1)
  {
    cin >> w >> h;

    if(w == 0 && h == 0)
      break;

    vector<vector<int> > tiles(w, vector<int>(h, -1));
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
        else if(sign == '@')
        {
          tiles[i][j] = VISITED;
          sx = i;
          sy = j;
        }
      }
    }
    cout<<FindMovableTiles(tiles, sx, sy, w, h)<<endl;
  }
  return 0;
}
