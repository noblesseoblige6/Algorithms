#include <bits/stdc++.h>

using namespace std;

int depth_fast_search(const vector<vector<int> >& ver, vector<int>& find_times, vector<int>& complete_times, int id, int current_time)
{
  int ver_id = id;
  stack<int> s;
  for(int i = 0; i < ver[ver_id].size(); ++i){
    if(find_times[ver[ver_id][i]] == 0){
      find_times[ver[ver_id][i]] = current_time++;
      s.push(ver[ver_id][i]);
    }
  }
  if(s.empty()){
    complete_times[ver_id] = current_time+1;
    s.pop();
    return complete_times[ver_id];
  }
  while(!s.empty()){
    ver_id = s.top();
    current_time = depth_fast_search(ver, find_times, complete_times, ver_id, current_time+1);
    // cout<<current_time<<endl;
    complete_times[ver_id] = current_time;
    s.pop();
  }
  return complete_times[ver_id];
}

void time_stamp_DFS(const vector<vector<int> >& ver, vector<int>& find_times, vector<int>& complete_times)
{
  stack<int> s;
  int current_time = 1;
  int n = ver.size();
  for(int i = 0; i < n; ++i){
    if(find_times[i] == 0){
      find_times[i] = current_time;
      current_time = depth_fast_search(ver, find_times, complete_times, i, current_time+1);
      complete_times[i] = current_time;
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
  time_stamp_DFS(ver_edges, find_times, complete_times);

  for(int i = 0 ; i < n; ++i){
    cout<<i+1<<" "<<find_times[i]<<" "<<complete_times[i]<<endl;
  }

  return 0;
}
