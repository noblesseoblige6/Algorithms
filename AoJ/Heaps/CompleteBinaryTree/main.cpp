#include <bits/stdc++.h>

using namespace std;

void showHeapInfo(const vector<int>& heap)
{
  int size = heap.size();
  for(int i = 1; i <= size; ++i){
    int l = 2*i;
    int r = 2*i+1;
    int parent = i/2;

    if(i == 1){
      //@comment root node
      printf("node %d: key = %d, left key = %d, right key = %d, \n", i, heap[i-1], heap[l-1], heap[r-1]);
    }else if(l > size && r > size){
      //@comment leaf nodes
      printf("node %d: key = %d, parent key = %d, \n", i, heap[i-1], heap[parent-1]);
    }else if(r > size){
      //@comment one leaf node
      printf("node %d: key = %d, parent key = %d, left key = %d, \n", i, heap[i-1], heap[parent-1], heap[l-1]);
    }else{
      printf("node %d: key = %d, parent key = %d, left key = %d, right key = %d, \n", i, heap[i-1], heap[parent-1], heap[l-1], heap[r-1]);
    }
  }
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

  showHeapInfo(nodes);

  return 0;
}
