#include <bits/stdc++.h>

using namespace std;

int main()
{
  list<int> l;

  int n, val;
  string op;
  cin>>n;
  for(int i = 0;  i < n; ++i){
    cin>>op;
    if(op == "insert"){
      cin>>val;
      l.push_front(val);
    }else if(op == "delete"){
      cin>>val;
      for(std::list<int>::iterator itr = l.begin(); itr != l.end(); itr++)
        if(*itr == val){
          l.erase(itr);
          break;
        }
    }else if(op == "deleteFirst"){
      l.pop_front();
    }else if(op == "deleteLast"){
      l.pop_back();
    }
  }
  for(std::list<int>::iterator itr = l.begin(); itr != l.end(); itr++)
    itr == --l.end() ?  cout<<*itr<<endl : cout<<*itr<<" ";
  return 0;
}
