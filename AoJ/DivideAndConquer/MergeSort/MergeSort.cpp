#include <bits/stdc++.h>
using namespace std;
int Count = 0;
vector<int> parseAndMerge(vector<int>& in, int l, int r)
{
  if(l >= r){return vector<int>(1, in[r]);}
  int m = (l+r)/2;
  //@comment Parse vector
  vector<int> lVec = parseAndMerge(in, l, m);
  vector<int> rVec = parseAndMerge(in, m+1, r);

  //@comment Merge parsed vectors
  int size = lVec.size() + rVec.size();
  vector<int> res;
  for(int lCount = 0, rCount = 0; lCount+rCount < size;){
    Count++;
    if(rCount >= rVec.size()){
      res.push_back(lVec[lCount]);
      lCount++;
    }else if(lCount >= lVec.size()){
      res.push_back(rVec[rCount]);
      rCount++;
    }else if(lVec[lCount] < rVec[rCount]){
      res.push_back(lVec[lCount]);
      lCount++;
    }else{
      res.push_back(rVec[rCount]);
      rCount++;
    }
  }
  return res;
}

vector<int> mergeSort(vector<int>& in)
{
  //@comment To avoid refering to out of the index,
  //the size of vector should subtracte 1
  return parseAndMerge(in, 0, in.size()-1);
}

int main()
{
  int count;
  int tmp;
  vector<int> input;
  cin>>count;
  for(int i = 0; i < count; i++){
    cin>>tmp;
    input.push_back(tmp);
  }
  vector<int> res = mergeSort(input);
  for(int i = 0; i < res.size(); i++){
    if(i == res.size()-1){cout<<res[i]<<endl;}
    else{cout<<res[i]<<" ";}
  }
  cout<<Count<<endl;
  return 0;
}
