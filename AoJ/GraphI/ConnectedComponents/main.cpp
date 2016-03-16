#include <bits/stdc++.h>

using namespace std;

const int kINF = 10000000;

void dfs(const vector<vector<int> >& ver, const int& ver_id, vector<int>& labels, const int& label)
{
  labels[ver_id] = label;
  for(int i = 0; i < ver[ver_id].size(); ++i)
    if(labels[ver[ver_id][i]] == kINF)
      dfs(ver, ver[ver_id][i], labels, label);
}

vector<int> findConnectedComponents(const vector<vector<int> >& ver, vector<int>& labels)
{
  int tmp_label = 1;

  for(int i = 0; i < ver.size(); ++i)
    if(labels[i] == kINF)
      dfs(ver, i, labels, tmp_label++);
  return labels;
}

int main()
{
  int nNodes, nPairs, a, b;

  cin >> nNodes >> nPairs;
  vector<vector<int> > ver_edges(nNodes, vector<int>());

  for(int i = 0 ; i < nPairs; ++i){
    cin>>a>>b;
    ver_edges[a].push_back(b);
    ver_edges[b].push_back(a);
  }

  int nChecks;
  cin>>nChecks;

  vector<int> labels(ver_edges.size(), kINF);
  findConnectedComponents(ver_edges, labels);

  for(int i = 0 ; i < nChecks; ++i){
    cin>>a>>b;
    if(labels[a] == labels[b])
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
  }

  return 0;
}
