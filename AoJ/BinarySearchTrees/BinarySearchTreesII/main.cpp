#include <bits/stdc++.h>

using namespace std;

struct node
{
  int key;
  node* l;
  node* r;
};

void release(node* n)
{
  if(n->l != NULL){release(n->l);}
  if(n->r != NULL){release(n->r);}

  delete n;
}

node* insert(node* n, int key)
{
  if(n == NULL){
    n = new node;
    n->key = key;
    n->l = NULL;
    n->r = NULL;
    return n;
  }
  n->key > key ? n->l = insert(n->l, key) : n->r = insert(n->r, key);
  return n;
}

bool search(node* n, const int val)
{
  if(n == NULL)
    return false;

  bool isfound = false;
  if(n->key > val)
    return search(n->l, val);
  else if(n->key < val)
    return search(n->r, val);
  else
    return true;
}

void mid_search(node* n)
{
  if(n == NULL)
    return;
  mid_search(n->l);
  cout<<" "<<n->key;
  mid_search(n->r);
}
void pre_search(node* n)
{
  if(n == NULL)
    return;
  cout<<" "<<n->key;
  pre_search(n->l);
  pre_search(n->r);
}


int main()
{
  node* tree = NULL;
  int n;
  string op;
  int val;

  cin>>n;
  for(int i = 0; i < n; ++i){
    cin>>op;
    if(op == "insert"){
      cin>>val;
      tree = insert(tree, val);
    }else if(op == "find"){
      cin>>val;
      search(tree, val) ? cout<< "yes" <<endl : cout<< "no" <<endl;
    }else if(op == "print"){
      mid_search(tree);
      cout<<endl;
      pre_search(tree);
      cout<<endl;
    }
  }

  release(tree);
  return 0;
}
