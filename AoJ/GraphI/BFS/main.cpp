#include <bits/stdc++.h>

using namespace std;

const float kINF = 10000;
void BFS(const vector<vector<int> >& ver, vector<int>& dis, const int& idx)
{
  queue<int> ver_q;
  queue<int> dis_q;

  //@commnet initialize queues with 1
  dis[idx] = 0;
  for(int i = 0; i < ver[idx].size(); ++i)
    if(dis[ver[idx][i]] == kINF){
      ver_q.push(ver[idx][i]);
      dis_q.push(dis[idx]+1);
    }

  while(!ver_q.empty()){
    int id = ver_q.front();

    if(dis_q.front() < dis[id])
      dis[id] = dis_q.front();

    ver_q.pop();
    dis_q.pop();

    for(int i = 0; i < ver[id].size(); ++i)
      if(dis[ver[id][i]] == kINF){
        ver_q.push(ver[id][i]);
        dis_q.push(dis[id]+1);
      }
  }
}

vector<int> min_distance(const vector<vector<int> >& ver, const int& idx)
{
  vector<int> distances(ver.size(), kINF);

  BFS(ver, distances, idx);

  //@comment change kINF to -1
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
