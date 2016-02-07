#include <bits/stdc++.h>

using namespace std;

enum Order{
  pre = 0,
  in = 1,
  post = 2
};

class node
{
  public:
    int id;
    node* l;
    node* r;
    node() : id(-1), l(NULL), r(NULL){}
    node(int c_id, int l_id, int r_id)
    {
      id = c_id;
      l = new node();
      l->id = l_id;
      r = new node();
      r->id = r_id;
    }
    void release()
    {
      if(l != NULL){l->release();}
      if(r != NULL){r->release();}
      delete this;
    }
};


bool search_build(int id, int l, int r, node* n)
{
  bool isfound = false;
  if(id == -1){return false;}
  if(n->id != id){
    if(n->l != NULL && !isfound){isfound = search_build(id, l, r, n->l);}
    if(n->r != NULL && !isfound){isfound = search_build(id, l, r, n->r);}
  }else if(n->id == id){
    n->l = new node();
    n->l->id = l;
    n->r = new node();
    n->r->id = r;
    return true;
  }
  return isfound;
}

node* buildBinTree(vector<node>& b, vector<node>& l)
{
  node* r = NULL;
  
  if(b.empty()){
    r = new node(l.front().id, l.front().l->id, l.front().r->id);
    return r;
  }
  
  r = new node(b.front().id, b.front().l->id, b.front().r->id);
  while(!b.empty()){
    for(vector<node>::iterator itr = b.begin(); itr < b.end();){
      cout<<itr->id<<endl;
      if(search_build(itr->id, itr->l->id, itr->r->id, r)){
        b.erase(itr);
      }
      else{++itr;}
    }
  }
  for(vector<node>::iterator itr = l.begin(); itr < l.end(); ++itr){
    search_build(itr->id, itr->l->id, itr->r->id, r);
  }
  return r;
}

void depth_fast_search(node* n, Order order)
{
  if(n->id == -1){return;}
  if(order == pre){cout<<" "<<n->id;}
  depth_fast_search(n->l, order);
  if(order == in){cout<<" "<<n->id;}
  depth_fast_search(n->r, order);
  if(order == post){cout<<" "<<n->id;}
}

int main()
{
  int id, l, r;
  int n;

  cin>>n;
  vector<node> branches;
  vector<node> leaves;
  for(int i = 0; i < n; ++i){
    cin>>id>>l>>r;
    if(l == -1 && r == -1){leaves.push_back(node(id, l, r));}
    else{branches.push_back(node(id, l, r));}
  }

  node* root = buildBinTree(branches, leaves);

  cout<<"Preorder"<<endl;
  depth_fast_search(root, pre);
  cout<<endl;

  cout<<"Inorder"<<endl;
  depth_fast_search(root, in);

  cout<<endl;
  cout<<"Postorder"<<endl;
  depth_fast_search(root, post);
  cout<<endl;
  root->release();
  return 0;
}
