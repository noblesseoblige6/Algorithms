#include <bits/stdc++.h>

using namespace std;

const int kINF = 0;
const int kMAX_COST = 1000001;
vector<int> shortestPathTree(const vector<vector<int> >& adj, vector<vector<int> >& res)
{
  int n = adj.size();
  vector<int> prev_costs(n, kMAX_COST);
  queue<int> vertices;

  vertices.push(0);
  prev_costs[0] = 0;

  while(!vertices.empty()){
    int ver_id = vertices.front();
    for(int i = 0; i < n; ++i){
      if(adj[ver_id][i] != kINF){
        int now_cost = adj[ver_id][i] + prev_costs[ver_id];
        // cout<<ver_id<<"->"<<i<<":"<<now_cost<<" "<<prev_costs[i]<<endl;
        if(now_cost < prev_costs[i]){
          // res[ver_id][i] = adj[ver_id][i];
          vertices.push(i);
          prev_costs[i] = now_cost;
        }
      }
    }
    vertices.pop();
  }
  return prev_costs;
}
void minSpanningTree(const vector<vector<int> >& adj, vector<vector<int> >& res)
{
  int n = adj.size();
  vector<int> vertices, edges;

  vertices.push_back(0);
  while(vertices.size() != n){
    int min = kMAX_COST;
    int tmp_ver, neighbor_ver;

    for(int i = 0; i < vertices.size(); ++i){
      for(int j = 0; j < n; ++j)
        if(find(vertices.begin(), vertices.end(), j) == vertices.end()){
          if(adj[vertices[i]][j] < min && adj[vertices[i]][j] != kINF){
            min = adj[vertices[i]][j];
            tmp_ver = vertices[i];
            neighbor_ver = j;
          }
        }
    }
    vertices.push_back(neighbor_ver);
    res[tmp_ver][neighbor_ver] = min;
  }
}

bool dfs(const vector<vector<int> >& cost_mat, const int& ver_id, const int& target, int& cost, vector<int>& visited)
{
  if(ver_id == target)
    return true;

  visited[ver_id] = 1;

  for(int i = 0; i < cost_mat.size(); ++i){
    if(cost_mat[ver_id][i] != kMAX_COST && visited[i] == 0){
      if(dfs(cost_mat, i, target, cost, visited)){
        cost += cost_mat[ver_id][i];
        return true;
      }
    }
  }
  return false;
}

int main()
{
  int n, in;
  cin >> n;

  vector<vector<int> > adj_mat(n, vector<int>(n));
  vector<vector<int> > min_spanning_mat(n, vector<int>(n, kMAX_COST));
  int ver_id, dim;
  int neighbor_id, weight;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cin >> ver_id >> dim;
      for(int k = 0; k < dim; ++k){
        cin >> neighbor_id >> weight;
        adj_mat[ver_id][neighbor_id] = weight;
      }
    }
  }

  vector<int> min_weights = shortestPathTree(adj_mat, min_spanning_mat);

  // for(int i = 0; i < n; ++i){
  //   for(int j = 0; j < n; ++j){
  //     cout<<min_spanning_mat[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  for(int i = 0; i < n; ++i){
    int cost = min_weights[i];
    // vector<int> visited_nodes(n, 0);
    // dfs(min_spanning_mat, 0, i, cost, visited_nodes);
    cout<<i<<" "<<cost<<endl;
  }

  return 0;
}
