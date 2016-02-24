#include <bits/stdc++.h>

using namespace std;

void maxheapify(vector<int>& heap, int now_node)
{
  int size = heap.size();

  int l = 2*now_node;
  int r = 2*now_node+1;

  int key = heap[now_node-1];
  int l_key = l <= size && l > 0 ? heap[l-1] : -INT_MIN;
  int r_key = r <= size && r > 0 ? heap[r-1] : -INT_MIN;
  int max_key = max(key, max(l_key, r_key));

  int next = now_node;
  if(max_key == l_key){
    heap[now_node-1] = l_key;
    heap[l-1] = key;
    next = l;
  }else if(max_key == r_key) {
    heap[now_node-1] = r_key;
    heap[r-1] = key;
    next = r;
  }
  if(next == now_node) return;
  maxheapify(heap, next);
}

void buildMaxHeap(vector<int>& heap)
{
  int size = heap.size();
  for(int i = size/2; i > 0; --i)
    maxheapify(heap, i);
}

void insert(vector<int>& q, int key)
{
  q.push_back(key);
}

int extract(vector<int>& q)
{
  buildMaxHeap(q);
  int root = q.front();
  q.erase(q.begin());
  return root;
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
