#include <bits/stdc++.h>

using namespace std;

void insert(vector<int>& q, int key)
{
  q.push_back(key);
  sort(q.begin(), q.end());
}

int extract(vector<int>& q)
{
  int pop_val = q.back();
  q.pop_back();
  return pop_val;
}

int main()
{
  priority_queue<int, vector<int> > pq;
  // vector<int> pq;
  string inst;

  while(1){
    cin>>inst;
    if(inst == "insert"){
      int val;
      cin>>val;
      // insert(pq, val);
      pq.push(val);
    }else if(inst == "extract"){
      // cout<<extract(pq)<<endl;
     cout<<pq.top()<<endl;
     pq.pop();
    }
    else
      break;
  }

  return 0;
}
