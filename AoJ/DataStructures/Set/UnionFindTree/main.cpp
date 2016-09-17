#include<bits/stdc++.h>

using namespace std;
#define TEST cout<<"TEST"<<endl;
#define TEST2 cout<<"TEST2"<<endl;

const int UNITE = 0;
const int SAME = 1;

const int EMP = -100;
const int ROOT = -1;

struct Node
{
  int parent;
  Node() : parent(EMP){}
};

int findRoot(const vector<Node>& n, int idx)
{
  if(idx == EMP)
    return EMP;

  if(n[idx].parent == ROOT)
    return idx;

  return findRoot(n, n[idx].parent);
}

void uniteTree(vector<Node>& f, vector<int>& depth, int a, int b)
{
  if(f[a].parent == EMP){
    f[a].parent = ROOT;
    depth[a]++;
  }
  if(f[b].parent == EMP){
    f[b].parent = ROOT;
    depth[b]++;
  }

  int root1 = findRoot(f, a);
  int root2 = findRoot(f, b);

  //@comment already nodes are in the same tree
  if(root1 == root2)
    return;

  if(depth[root1] < depth[root2]){
    f[root1].parent = root2;
    depth[root1] = depth[root2];
    depth[a] = depth[root2];
  }
  else{
    f[root2].parent = root1;
    depth[root2] = depth[root1];
    depth[b] = depth[root1];
  }
}

bool isSameTree(const vector<Node>& f, int a, int b)
{
  //@comment root is the same, nodes are in the same tree
  int root1 = findRoot(f, a);
  int root2 = findRoot(f, b);
  if(root1 == EMP && root2 == EMP)
    return false;
  return root1 == root2;
}

int main()
{
  int n, q, op;
  int a, b;
  cin >> n >> q;

  vector<Node> forest(n);
  vector<int> depth(n);
  for(int i = 0; i < q; ++i){
    cin >> op >> a >> b;
    switch(op){
      case UNITE:
        // TEST;
        uniteTree(forest, depth, a, b);
        break;
      case SAME:
        // TEST2;
        isSameTree(forest, a, b) ? cout<<1<<endl : cout<<0<<endl;
        break;
      default:
        break;
    }
  }
  return 0;
}
