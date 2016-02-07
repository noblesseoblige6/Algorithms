#include <bits/stdc++.h>

using namespace std;
int partition(vector<int>& arr, int l, int r)
{
  int p = arr[r];
  int idx = l;
  for(int i = l; i < r; i++){
    if(arr[i] <= p){
      int tmp = arr[i];
      arr[i] = arr[idx];
      arr[idx] = tmp;
      idx++;
    }
  }
  int tmp = arr[r];
  arr[r] = arr[idx];
  arr[idx] = tmp;
  return idx;
}

void quickSort(vector<int>& arr, int l, int r)
{
  if(l >= r){return;}
  int m = partition(arr, l, r); 
  quickSort(arr, l, m-1); 
  quickSort(arr, m+1, r); 
}

int minCost(const vector<int>& org)
{
  int cost = 0, n = org.size();
  bool isSwapped = false;
  vector<int> sorted;
  vector<int> cycle;
  copy(org.begin(), org.end(), back_inserter(sorted));
  quickSort(sorted, 0, n-1); 
  for(int i = 0; i < n; i++){
    if(org[i] == sorted[i]){continue;}
    for(int j = i+1; j < n; j++){
      //@comment swap only once 
      if(org[i] == sorted[j] && sorted[i] == org[j]){
        cost += org[i] + org[j]; 
        cout<<org[i]<<" "<<org[j]<<" "<<cost<<endl;
        isSwapped = true;
        break;
      }
    }
    if(!isSwapped){cycle.push_back(org[i]);}
    isSwapped = false;
  }
  for(int i = 0; i < cycle.size(); i++){cout<<cycle[i]<<" ";}cout<<endl;
  if(cycle.size() != 0){
    int min = FLT_MAX;
    int sum = 0;
    for(int i = 0; i < cycle.size(); i++){
      if(min > cycle[i]){min = cycle[i];} 
      sum +=  cycle[i];
    }
    int tmpCost = sum + (cycle.size()-2)*min;
    int tmpCost2 = sum + min + (cycle.size()+1)*sorted.front();
    cost += sum + tmpCost < tmpCost2 ? tmpCost : tmpCost2; 
  }
  return cost;
}

int main()
{
  int n, tmp;
  vector<int> in;
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>tmp;
    in.push_back(tmp);
  }
  cout<<minCost(in)<<endl;
  return 0;
}
