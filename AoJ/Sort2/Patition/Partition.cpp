#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b)
{
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}

int partition(vector<int>& arr, int l, int r)
{
  int p = arr[r];
  int idx = l ;
  for(int i = l; i < r; i++){
    if(arr[i] <= p){
      swap(arr[idx], arr[i]);
      idx++;
    }
  }
  swap(arr[idx], arr[r]);
  return idx;
}

int main()
{
  int n, tmp, idx;
  vector<int> in;
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>tmp;
    in.push_back(tmp);
  }

  idx = partition(in, 0, n-1);

  for(int i = 0; i < n; i++){
    if(i == idx){cout<<"["<<in[i]<<"] ";}
    else if(i == n-1){cout<<in[i]<<endl;}
    else{cout<<in[i]<<" ";}
  }


  return 0;
}
