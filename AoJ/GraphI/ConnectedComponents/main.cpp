#include <bits/stdc++.h>

using namespace std;

const int kNULL = 0;

int DFS(const vector<vector<int> >& ver, const int& ver_id, vector<int>& labels, const int& label)
{
  stack<int> s;
  for(int i = ver[ver_id].size()-1; i >= 0; --i)
    if(labels[ver[ver_id][i]] == kNULL)
      s.push(ver[ver_id][i]);

  while(!s.empty()){
    labels[s.top()] = DFS(ver, s.top(), labels, label);
    s.pop();
  }
  return label;
}

vector<int> findConnectedComponents(const vector<vector<int> >& ver)
{
  vector<int> nodes_label(ver.size());
  int tmp_label = 1;
  nodes_label[0] = tmp_label;
  nodes_label[0] = DFS(ver, 0, nodes_label, tmp_label++);

  for(int i = 1; i < ver.size(); ++i){
    if(nodes_label[i] == kNULL)
      nodes_label[i] = DFS(ver, i, nodes_label, tmp_label++);
  }

  for(int i = 0; i < ver.size(); ++i)
    cout<<i<<" "<<nodes_label[i]<<endl;
  return nodes_label;
}

bool hasEdge(const vector<int>& labels, const int& start, const int & goal)
{
  return labels[start] == labels[goal];
}

int main()
{
  int nNodes, nPairs, a, b;

  cin >> nNodes >> nPairs;
  vector<vector<int> > ver_edges(nNodes, vector<int>());

  for(int i = 0 ; i < nPairs; ++i){
    cin>>a>>b;
    ver_edges[a].push_back(b);
  }

  // for(int i = 0; i < nNodes; ++i){
  //   cout<<i<<":";
  //   for(int j = 0; j < ver_edges[i].size(); ++j){
  //     cout<<ver_edges[i][j]<<" ";
  //   }
  // cout<<endl;
  // }

  int nChecks;
  cin>>nChecks;

  vector<int> labels = findConnectedComponents(ver_edges);
  for(int i = 0 ; i < nChecks; ++i){
    cin>>a>>b;
    if(hasEdge(labels, a, b))
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
  }

  return 0;
}
