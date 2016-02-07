#include<bits/stdc++.h>

using namespace std;
vector<int> parseAndMerge(vector<int>& in, int l, int r, int& count)
{
  if(l >= r){return vector<int>(1, in[r]);}
  int m = (l+r)/2;
  //@comment Parse vector
  vector<int> lVec = parseAndMerge(in, l, m, count);
  vector<int> rVec = parseAndMerge(in, m+1, r, count);

  //@comment Merge parsed vectors
  int size = lVec.size() + rVec.size();
  vector<int> res;
  for(int lCount = 0, rCount = 0; lCount+rCount < size;){
    if(rCount >= rVec.size()){
      res.push_back(lVec[lCount]);
      lCount++;
    }else if(lCount >= lVec.size()){
      res.push_back(rVec[rCount]);
      rCount++;
    }else if(lVec[lCount] <= rVec[rCount]){
      res.push_back(lVec[lCount]);
      lCount++;
    }else{
      res.push_back(rVec[rCount]);
      rCount++;
      //@comment When right vector element is bigger,
      //get how many elements there are between 
      //original and sorted positions
      // cout<<count<<" "<<lVec.size()-lCount<<endl;
      count += lVec.size()-lCount;
    }
  }
  return res;
}


int nInverse(vector<int>& in)
{
  int res = 0;
  parseAndMerge(in, 0, in.size()-1, res);
  return res;
}

int main()
{
  int count;
  int tmp;
  vector<int> inputs;
  cin>>count;
  for(int i = 0; i < count; i++){
    cin>>tmp;
    inputs.push_back(tmp);
  }
  cout<<nInverse(inputs)<<endl;
  return 0;
}
