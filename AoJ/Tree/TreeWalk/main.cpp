#include <bits/stdc++.h>

using namespace std;

enum Order{
  pre = 0,
  in = 1,
  post = 2
};

struct node
{
    int p, l, r;
    node() : p(-1), l(-1), r(-1){}
};


void depth_fast_search(int n, const vector<node>& nodes, Order order)
{
  if(n == -1){return;}
  if(order == pre){cout<<" "<<n;}
  depth_fast_search(nodes[n].l, nodes, order);
  if(order == in){cout<<" "<<n;}
  depth_fast_search(nodes[n].r, nodes, order);
  if(order == post){cout<<" "<<n;}
}

int main()
{
  int p, l, r, root;
  int n;

  cin>>n;
  vector<node> nodes(n);

  for(int i = 0; i < n; ++i){
    cin>>p>>l>>r;
    nodes[p].l = l;
    nodes[p].r = r;
    if(l != -1) nodes[l].p = p;
    if(r != -1) nodes[r].p = p;
  }
  for(int i = 0; i < nodes.size(); ++i){
    if(nodes[i].p == -1) root = i;
  }

  cout<<"Preorder"<<endl;
  depth_fast_search(root, nodes, pre);
  cout<<endl;

  cout<<"Inorder"<<endl;
  depth_fast_search(root, nodes, in);

  cout<<endl;
  cout<<"Postorder"<<endl;
  depth_fast_search(root, nodes, post);
  cout<<endl;
  return 0;
}
