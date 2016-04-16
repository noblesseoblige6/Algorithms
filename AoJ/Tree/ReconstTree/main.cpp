#include <bits/stdc++.h>

using namespace std;

struct node
{
  int p, l, r;
  node() : p(-1), l(-1), r(-1){}
};

void dfs(const int& n, const vector<node>& nodes)
{
  if(n == -1)
    return;

  dfs(nodes[n].l, nodes);
  dfs(nodes[n].r, nodes);

  cout<<n+1<<" ";
}

int trackTree(int& pre_idx, const int& l, const int& r, const vector<int>& pre, const vector<int>& mid, vector<node>& tree)
{
  int mid_idx = -1;
  int id = pre[pre_idx];
  for(int i = l; i < r; ++i)
    if(id == mid[i])
      mid_idx = i;

  if(mid_idx == -1){
    pre_idx--;
    return -1;
  }

  tree[id].l = trackTree(++pre_idx, l, mid_idx, pre, mid, tree);
  tree[id].r = trackTree(++pre_idx, mid_idx, r, pre, mid, tree);

  return id;
}

void reconstTree(const vector<int>& pre, const vector<int>& mid)
{
  int n = pre.size();
  vector<node> tree(n);

  int idx = 0;
  int root = trackTree(idx, 0, n, pre, mid, tree);
  dfs(root, tree);
  cout<<endl;
}

int main()
{
  int p, n;

  cin>>n;
  vector<int> pre_order(n), mid_order(n);

  for(int i = 0; i < n; ++i){
    cin>>p;
    pre_order[i] = p-1;
  }
  for(int i = 0; i < n; ++i){
    cin>>p;
    mid_order[i] = p-1;
  }

  reconstTree(pre_order, mid_order);
  return 0;
}
