#include <bits/stdc++.h>

using namespace std;

const int kINF = -1;

int minSpanningTree(const vector<vector<int> >& adj)
{
  int n = adj.size();
  vector<int> vertices, edges;

  vertices.push_back(0);
  while(vertices.size() != n){
    int min = 10000;
    int tmp_ver;

    for(int i = 0; i < vertices.size(); ++i){
      for(int j = 0; j < n; ++j)
        if(find(vertices.begin(), vertices.end(), j) == vertices.end()){
          if(adj[vertices[i]][j] < min && adj[vertices[i]][j] != kINF){
            min = adj[vertices[i]][j];
            tmp_ver = j;
          }
        }
    }
    vertices.push_back(tmp_ver);
    edges.push_back(min);
  }
  return accumulate(edges.begin(), edges.end(), 0);
}

int main()
{
  int n, in;
  cin >> n;

  vector<vector<int> > adj_mat(n, vector<int>(n));

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cin >> in;
      adj_mat[i][j] = in;
    }
  }
  cout<<minSpanningTree(adj_mat)<<endl;
  return 0;
}
