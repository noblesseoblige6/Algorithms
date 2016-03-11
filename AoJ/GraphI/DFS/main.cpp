#include <bits/stdc++.h>

using namespace std;

const int kINF = 0;

int DFS(const vector<vector<int> >& ver, vector<int>& find_times, vector<int>& complete_times, int ver_id, int current_time)
{
  stack<int> s;
  for(int i = ver[ver_id].size()-1; i >= 0; --i)
    s.push(ver[ver_id][i]);

  while(!s.empty()){
    int id = s.top();
    if(find_times[id] == kINF){
      find_times[id] = current_time;
      current_time = DFS(ver, find_times, complete_times, id, current_time+1);
      complete_times[id] = current_time++;
    }
    s.pop();
  }
  return current_time;
}

void time_stamp(const vector<vector<int> >& ver, vector<int>& find_times, vector<int>& complete_times)
{
  stack<int> s;
  int current_time = 1;
  int n = ver.size();
  for(int i = 0; i < n; ++i){
    if(find_times[i] == kINF){
      find_times[i] = current_time;
      current_time = DFS(ver, find_times, complete_times, i, current_time+1);
      complete_times[i] = current_time++;
    }
  }
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

  vector<int> find_times(n), complete_times(n);
  time_stamp(ver_edges, find_times, complete_times);

  for(int i = 0 ; i < n; ++i){
    cout<<i+1<<" "<<find_times[i]<<" "<<complete_times[i]<<endl;
  }

  return 0;
}
