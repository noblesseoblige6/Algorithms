#include <bits/stdc++.h>

using namespace std;
struct node
{
  int parent;
  vector<int> children;
  int depth;
  string kind;
  node():parent(-1), depth(-1),kind(""){children.clear();}
};

int main()
{
  int n, cn;
  int id, cid;

  cin>>n;
  vector<node> tree(n);
  for(int i = 0; i < n; ++i){
    cin>>id>>cn;
    for(int j = 0; j < cn; ++j){
      cin>>cid;
      tree[id].children.push_back(cid);  
      tree[cid].parent = id;
    }
  }

  int pid;
  for(int i = 0; i < n; ++i)
    if(tree[i].parent == -1)
      pid = i;

  tree[pid].depth = 0;
  tree[pid].kind = "root";

  stack<int> s;
  s.push(pid);
  while(!s.empty()){
    pid = s.top();
    s.pop();
    for(int i = 0; i < tree[pid].children.size(); ++i){
      cid = tree[pid].children[i];
      tree[cid].depth = tree[pid].depth+1;
      tree[cid].kind = tree[cid].children.size() == 0 ? "leaf" : "internal node"; 
      s.push(cid);
    }
  }

  for(int i = 0; i < n; ++i){
    printf("node %d: parent = %d, depth = %d, %s, [", i, tree[i].parent, tree[i].depth, tree[i].kind.c_str());  
    cn = tree[i].children.size();
    for(int j = 0; j < cn-1; ++j){
      printf("%d, ", tree[i].children[j]);
    }
    tree[i].children.size() != 0 ? printf("%d]\n", tree[i].children[cn-1]) : printf("]\n");
  }
  return 0;
}
