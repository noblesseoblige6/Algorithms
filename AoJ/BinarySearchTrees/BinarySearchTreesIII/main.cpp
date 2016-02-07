#include <bits/stdc++.h>

using namespace std;

struct node
{
  int key;
  node* p;
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
    n->p = NULL;
    n->l = NULL;
    n->r = NULL;
    return n;
  }
  if(n->key > key){
    n->l = insert(n->l, key);
    n->l->p = n;
  }else{
    n->r = insert(n->r, key);
    n->r->p = n;
  }
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

void erase(node* n, const int val)
{
  if(n == NULL)
    return;

  if(n->key > val)
    erase(n->l, val);

  else if(n->key < val)
    erase(n->r, val);
  //@comment target node
  else{
    //@comment leaf node
    if(n->l == NULL && n->r == NULL){
      if(n->p != NULL)
        n->p->key > n->key ? n->p->l = NULL : n->p->r = NULL;
    }
    else if(n->l == NULL) {
      if(n->p != NULL){
        n->p->key > n->key ? n->p->l = n->r : n->p->r = n->r;
        n->r->p = n->p;
      }
      else{
        n->key = n->r->key;
        erase(n->r, n->r->key);
        return;
      }
    }else if(n->r == NULL){
      if(n->p != NULL){
        n->p->key > n->key ? n->p->l = n->l : n->p->r = n->l;
        n->l->p = n->p;
      }
      else{
        int tmp = n->l->key;
        erase(n->l, n->l->key);
        n->key = tmp;
        return;
      }
    }
    //@comment deleted node has two children
    else{
      int tmp = n->r->key;
      //@comment delete right node
      erase(n->r, tmp);
      n->key = tmp;
      return;
    }
    delete n;
  }
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
    }else if(op == "delete"){
      cin>>val;
      erase(tree, val);
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
