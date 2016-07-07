#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

#define TEST cout<<"TEST"<<endl

struct Node
{
  ull key;
  Node* next;
  Node* prev;
  Node() : key(0), next(NULL), prev(NULL){}
};

class List
{
  private:
    Node* front;
    Node* last;

  public:
    List():front(NULL), last(NULL){}
    ~List()
    {
      deleteAllList();
    }

    void deleteAllList()
    {
      if(front == NULL)
        return;

      Node* node = front->next;
      while(node != NULL){
        delete node->prev;
        node = node->next;
      }
      delete last;
    }

    void insert(const ull& key)
    {
      Node* res = new Node();
      res->key = key;
      res->prev = NULL;
      res->next = NULL;

      Node* node = front;
      if(node != NULL){
        res->next = node;
        node->prev = res;
      }
      front = res;
      if(front->next == NULL)
        last = front;
    }

    void print()
    {
      for(Node* tmp = front; tmp != NULL; tmp = tmp->next)
        tmp->next == NULL ? printf("%d\n", tmp->key) : printf("%d ", tmp->key);
    }

    void deleteFirst()
    {
      if(front == NULL)
        return;

      if(front == last){
        delete front;
        front = last = NULL;
        return;
      }

      Node* node = front->next;
      node->prev = NULL;

      //@comment delete front node
      delete front;
      front = node;
    }

    void deleteLast()
    {
      if(last == NULL)
        return;

      if(front == last){
        delete front;
        front = last = NULL;
        return;
      }

      Node* node = last->prev;
      node->next = NULL;

      delete last;
      last = node;
    }

    void deleteByKey(const ull& key)
    {
      if(front == NULL)
        return;

      Node* node = front;
      while(node->key != key){
        node = node->next;
        //@comment Not found
        if(node == NULL)
          return;
      }

      if(node == front){
        deleteFirst();
        return;
      }
      if(node == last){
        deleteLast();
        return;
      }

      node->next->prev = node->prev;
      node->prev->next = node->next;
      delete node;
    }
};


int main()
{
  char c_op[256];
  string operation;
  ull count, key;
  List l;
  cin>>count;
  for(int i = 0; i < count; i++){
    scanf("%s", c_op);
    operation = c_op;
    if(operation == "insert"){
      scanf("%d", &key);
      l.insert(key);
    }else if(operation == "delete"){
      scanf("%d", &key);
      l.deleteByKey(key);
    }else if(operation == "deleteFirst"){
      l.deleteFirst();
    }else if(operation == "deleteLast"){
      l.deleteLast();
    }
  }

  l.print();
  return 0;
}
