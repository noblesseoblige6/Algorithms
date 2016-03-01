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
  //@comment at leaf node
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

node* getMin(node* target)
{
  while(target->l != NULL)
    target = target->l;
  return target;
}

node* find_delete_node(node* n)
{
  node* target = n;
  while(target->r != NULL)
    target = target->r;

  //@comment at leaf node. This node will be deleted
  if(target->l == NULL){
    target = getMin(target->p);
    target->p->r == target ? target->p->r = NULL : target->p->l = NULL;
    return target;
  }

  while(target->l != NULL && target->r == NULL)
    target = target->l;

  return find_delete_node(target);
}

void change_root(node* root, node* target)
{
  root->key = target->key;
  root->l = target->l;
  root->r = target->r;

  target->l->p = root;
  target->r->p = root;
}

void remove_node(node* n, const int& val)
{
  if(n->l == NULL && n->r == NULL){
    //@comment deleted node is NOT root
    if(n->p != NULL)
      n->p->r == n ? n->p->r = NULL : n->p->l = NULL;
    delete n;
    return;
  }
  if(n->l != NULL && n->r != NULL) {
    node* d_node = find_delete_node(n->r);
    n->key = d_node->key;
    delete d_node;
    return;
  }

  //@comment node has left child
  if(n->l != NULL) {
    //@comment node is root, then left child become root
    if(n->p == NULL)
      change_root(n, n->l);

    else if(n->p->l == n){
      n->l->p = n->p;
      n->p->l = n->l;
    }
    else{
      n->r->p = n->p;
      n->p->r = n->l;
    }
  }
  //@comment node has right chiled
  else if(n->r != NULL){
    if(n->p == NULL)
      change_root(n, n->r);

    else if(n->p->l == n){
      n->l->p = n->p;
      n->p->l = n->r;
    }
    else{
      n->r->p = n->p;
      n->p->r = n->r;
    }
  }
  delete n;
}

void erase(node* n, const int& val)
{
  if(n == NULL)
    return;
  //@comment search target node
  if(n->key > val)
    erase(n->l, val);
  else if(n->key < val)
    erase(n->r, val);

  //@comment target node
  else
    remove_node(n, val);
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
