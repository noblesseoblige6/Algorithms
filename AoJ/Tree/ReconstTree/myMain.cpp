#include <bits/stdc++.h>

using namespace std;
const int N_MAX = 41;
struct node
{
  int p, l, r;
  node() : p(-1), l(-1), r(-1){}
};

void dfs(const int& n, const vector<node>& nodes, vector<int>& post)
{
  if(n == -1)
    return;

  dfs(nodes[n].l, nodes, post);
  dfs(nodes[n].r, nodes, post);
  post.push_back(n+1);
}

int trackTree(int& pre_idx, int l, int r, const vector<int>& pre, const vector<int>& mid, vector<node>& tree)
{
  if(l > r)
    return -1;

  int mid_idx = -1;
  int id = pre[pre_idx++];
  for(int i = l; i <= r; ++i)
    if(id == mid[i])
      mid_idx = i;

  tree[id].l = trackTree(pre_idx, l, mid_idx-1, pre, mid, tree);
  tree[id].r = trackTree(pre_idx, mid_idx+1, r, pre, mid, tree);
  return id;
}

void reconstTree(const vector<int>& pre, const vector<int>& mid, vector<int>& post)
{
  int n = pre.size();
  vector<node> tree(N_MAX);

  int idx = 0;
  trackTree(idx, 0, n-1, pre, mid, tree);
  dfs(pre[0], tree, post);
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

  vector<int> post;
  reconstTree(pre_order, mid_order, post);

  for(int i = 0; i < n; ++i)
    i != n-1 ? cout<<post[i]<<" " : cout<<post[i]<<endl;

  return 0;
}
