#include <bits/stdc++.h>

using namespace std;

struct node
{
  int parent;
  int l, r;
  int degree;
  int sibling;
  int depth;
  int height;
  string type;
};

int bin_tree(node* n, int id, int depth)
{
  if(id == -1)
    return 0;

  n[id].depth = depth;
  n[id].height = max(bin_tree(n, n[id].l, depth+1), bin_tree(n, n[id].r, depth+1));
  return n[id].height + 1;
}

int main()
{
  int n;
  int id, l, r;
  node nodes[25];
  cin>>n;

  for(int i = 0; i < 25; ++i){
    nodes[i].l = nodes[i].r = nodes[i].parent = nodes[i].sibling = -1;
    nodes[i].height = nodes[i].degree = nodes[i].depth = 0;
  }

  for(int i = 0; i < n; ++i){
    cin>>id>>l>>r;
    if(l != -1 && r != -1)
      nodes[id].degree = 2;
    else if(l != -1 || r != -1)
      nodes[id].degree = 1;


    nodes[id].l = l;
    nodes[id].r = r;

    nodes[l].parent = id;
    nodes[l].sibling = r;

    nodes[r].parent = id;
    nodes[r].sibling = l;
  }
  int pid;
  for(int i = 0; i < n; ++i){
    if(nodes[i].parent == -1){
      nodes[i].type = "root";
      pid = i;
    }
    else if(nodes[i].degree == 0){
      nodes[i].type = "leaf";
    }else{
      nodes[i].type = "internal node";
    }
  }

  bin_tree(nodes, pid, 0);

  for(int i = 0; i < n; ++i){
    cout<<"node "<<i<<": parent = "<<nodes[i].parent<<", sibling = "<<nodes[i].sibling<<", degree = "<<nodes[i].degree<<", depth = "<<nodes[i].depth<<", height = "<<nodes[i].height<<", "<<nodes[i].type<<endl;
  }

  return 0;
}
