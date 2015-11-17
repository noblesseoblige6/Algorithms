#include<bits/stdc++.h>
using namespace std;

vector<int> countingSort(vector<int>& arr, int max)
{
  vector<int> res(arr.size());
  vector<int> counter(max+1, 0);
  for(int i = 0; i < arr.size(); i++){
    counter[arr[i]]++;
  }
  for(int i = 1; i < counter.size(); i++){
    counter[i] += counter[i-1];
  }
  for(int i = 0; i < arr.size(); i++){
    res[counter[arr[i]]-1] = arr[i];
    counter[arr[i]]--;
  }
  return res;
}

int main()
{
  int count;
  int tmp;
  int max = INT_MIN;
  vector<int> arr;
  cin>>count;
  for(int i = 0; i< count; i++){
    cin>>tmp;
    if(max < tmp){max = tmp;}
    arr.push_back(tmp);
  }
  arr = countingSort(arr, max);
  for(int i = 0; i < count; i++){
    if(i == count-1){cout<<arr[i]<<endl;}
    else{cout<<arr[i]<<" ";}
  }
  return 0;
}
