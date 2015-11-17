#include <bits/stdc++.h>
using namespace std;
struct Node 
{
  int key;
  Node* next;
  Node* prev;
};

void deleteAllList(Node* front)
{ 
  while(front != NULL){
    delete front->prev;
    front = front->next;
  }
}

Node* insert(Node* front, int key)
{
  //res‚ªæ“ª‚ÌNode‚É‚È‚é
  Node* res = new Node;
  res->key = key;
  res->next = front;
  res->prev = NULL;
  if(front != NULL){
    front->prev = res;
  }
  return res;
}

Node* deleteFirst(Node* front)
{
  if(front == NULL){return NULL;}
  else if(front->next == NULL){
    delete front;
    return NULL;
  }
  front = front->next;
  //@comment delete front node
  delete front->prev;
  front->prev = NULL;
  return front;
}

void deleteLast(Node* front)
{
  if(front == NULL){return;}
  //@comment loop until the end of the list
  while(front->next != NULL){front = front->next;}
  front->prev->next = NULL;
  front->prev = NULL;
  delete front;
}

void deleteByKey(Node* front, int key)
{
  if(front == NULL){return;}
  while(front->key != key){front = front->next;}
  if(front->prev == NULL){ //@comment the target is at the front 
    front = deleteFirst(front);
  } else if(front->next == NULL){ //the target is at the end
    deleteLast(front); 
  }else{
    front->next->prev = front->prev;
    front->prev->next = front->next;
    delete front;
  }
}
int main()
{
  string operation;
  int count, key;
  Node* front = new Node;
  front->key = 0; front->next = NULL; front->prev = NULL;
  cin>>count;
  for(int i = 0; i < count; i++){
    cin>>operation;
  cout<<operation<<endl;
    if(operation == "insert"){
      cin>>key;
      front->next = insert(front->next, key);
    }else if(operation == "delete"){
      cin>>key;
      deleteByKey(front->next, key);
    }else if(operation == "deleteFirst"){
      front->next =  deleteFirst(front->next);
    }else if(operation == "deleteLast"){
      deleteLast(front->next);
    }else{cout<<"There is no such operation"<<endl;}
    //Output part
    for(Node* tmp = front->next; tmp != NULL; tmp = tmp->next){
      if(tmp->next == NULL){cout<<tmp->key<<endl;}
      else{cout<<tmp->key<<" ";}
    }
  }
  
  deleteAllList(front->next); 
  return 0;
}
