#include <bits/stdc++.h>

using namespace std;

const int kINF = 0;
const int kMAX_COST = 1000001;

struct node
{
  int v;
  int cost;
  bool operator<(const node& a) const
  {
    return cost < a.cost;
  }
};

vector<int> shortestPathTree(const vector<vector<int> >& adj)
{
  int n = adj.size();
  vector<int> prev_costs(n, kMAX_COST);
  priority_queue<node> vertices;

  //@comment search starts from 0th node
  node tmp; tmp.v  = tmp.cost = 0;
  vertices.push(tmp);
  prev_costs[0] = 0;

  while(!vertices.empty()){
    node ver_id = vertices.top();
    for(int i = 0; i < n; ++i){
      if(adj[ver_id.v][i] != kINF){
        int now_cost = adj[ver_id.v][i] + prev_costs[ver_id.v];
        if(now_cost < prev_costs[i]){
          tmp.v = i; tmp.cost = now_cost;
          vertices.push(tmp);
          prev_costs[i] = now_cost;
        }
      }
    }
    vertices.pop();
  }
  return prev_costs;
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

  vector<int> min_weights = shortestPathTree(adj_mat);

  for(int i = 0; i < n; ++i)
    cout<<i<<" "<<min_weights[i]<<endl;

  return 0;
}
