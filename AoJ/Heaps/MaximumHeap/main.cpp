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


int main()
{
  int n, tmp;
  vector<int> nodes;

  cin>>n;
  for(int i = 0; i < n; ++i){
    cin>>tmp;
    nodes.push_back(tmp);
  }
  buildMaxHeap(nodes);
  for(int i = 0; i < n; ++i)
    cout<<" "<<nodes[i];
  cout<<endl;

  return 0;
}
