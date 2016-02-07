#include <bits/stdc++.h>
using namespace std;
bool weightLimits(int k, int limit, const vector<int>& w)
{
  int sum = 0, offset = -1;
  for(int i = 0; i < k; i++){
    for(int j = offset+1; j < w.size(); j++){
      if(sum + w[j] > limit){break;}
      offset = j;
      sum += w[j];
    }
    if(offset == w.size()-1){return false;}
    sum = 0;
  }
  return true;
}
int allocation(int n, int k, const vector<int>& weights)
{
  int r = 0;
  int l = FLT_MIN;
  int m;
  for(int i = 0; i < n; i++){
    l = max(weights[i], l);
    r += weights[i];
  }
  while(r > l){
    m = (r+l)/2.0;
    if(weightLimits(k, m, weights)){l = m+1;}
    else{r = m;}
  }
  return r;
}

int main(int argc, char* argv[])
{
  int n, k;
  int w;
  vector<int> weights;
  cin>>n>>k;
  for(int i = 0; i < n; i++){
    cin>>w;
    weights.push_back(w);
  }
  cout<<allocation(n, k, weights)<<endl;
  return 0;
}
