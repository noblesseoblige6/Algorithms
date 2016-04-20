#include <bits/stdc++.h>

using namespace std;
const int N_MAX = 41;

void reconstTree(int l, int r, int& idx, const vector<int>& pre, const vector<int>& mid, vector<int>& ord)
{
  if(l > r)
    return;

  int id = pre[idx++];
  reconstTree(l, ord[id]-1, idx, pre, mid, ord);
  reconstTree(ord[id]+1, r, idx, pre, mid, ord);

  string tail = pre[0] == id ? "\n" : " ";
  cout << id+1 << tail;
}

int main()
{
  int p, n;

  cin>>n;
  vector<int> pre_order(n), mid_order(n);
  vector<int> order(N_MAX);

  for(int i = 0; i < n; ++i){
    cin>>p;
    pre_order[i] = p-1;
  }
  for(int i = 0; i < n; ++i){
    cin>>p;
    mid_order[i] = p-1;
    order[mid_order[i]] = i;
  }
  int idx = 0;
  reconstTree(0, n-1, idx, pre_order, mid_order, order);

  return 0;
}
