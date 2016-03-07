#include <bits/stdc++.h>

using namespace std;

const float kINF = 10000;
int BFS(const vector<vector<int> >& ver, vector<int>& dis, const int& idx, const int& distance)
{
  queue<int> q;
  for(int i = 0; i < ver[idx].size(); ++i)
    q.push(ver[idx][i]);

  while(!q.empty()){
    int tmp_dis = BFS(ver, dis, q.front(), distance+1);
    if(tmp_dis < dis[q.front()])
      dis[q.front()] = tmp_dis;
    q.pop();
  }
  return distance;
}

vector<int> min_distance(const vector<vector<int> >& ver, const int& idx)
{
  vector<int> distances(ver.size(), kINF);
  distances[idx] = BFS(ver, distances, idx, 0);
  for(vector<int>::iterator itr = distances.begin(); itr != distances.end(); ++itr)
    if(*itr == kINF)
      *itr = -1;
  return distances;
}

int main()
{
  int n, nIdx, nAdj, val;

  cin >> n;
  vector<vector<int> > ver_edges(n, vector<int>());

  for(int i = 0 ; i < n; ++i){
    cin >> nIdx >> nAdj;
    ver_edges[i].resize(nAdj);
    for(int j = 0 ; j < nAdj; ++j){
      cin>>val;
      ver_edges[i][j] = val-1;
    }
  }

  vector<int> distances = min_distance(ver_edges, 0);

  for(int i = 0 ; i < n; ++i){
    cout<<i+1<<" "<<distances[i]<<endl;
  }

  return 0;
}
