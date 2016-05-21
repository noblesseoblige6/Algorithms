#include<bits/stdc++.h>

typedef unsigned int uint;
typedef unsigned long long ull;
using namespace std;

vector<uint> parseAndMerge(vector<uint>& in, int l, int r, ull& count)
{
  if(l >= r)
    return vector<uint>(1, in[r]);

  //@comment parse
  int m = (l+r)/2;
  vector<uint> lVec = parseAndMerge(in, l, m, count);
  vector<uint> rVec = parseAndMerge(in, m+1, r, count);

  //@comment Merge
  const int sLVec = lVec.size();
  const int sRVec = rVec.size();
  const int size = sLVec + sRVec;
  vector<uint> res;
  int lCount = 0, rCount = 0;
  while(lCount+rCount < size){
    if(rCount >= rVec.size()){
      res.push_back(lVec[lCount++]);
      continue;
    }
    if(lCount >= lVec.size()){
      res.push_back(rVec[rCount++]);
      continue;
    }
    if(lVec[lCount] <= rVec[rCount]){
      res.push_back(lVec[lCount++]);
    }else{
      res.push_back(rVec[rCount++]);
      //@comment When right vector element is smaller,
      //get how many elements there are between
      //original and sorted positions
      count += sLVec-lCount;
    }
  }
  return res;
}


ull nInverse(vector<uint>& in)
{
  ull res = 0;
  parseAndMerge(in, 0, in.size()-1, res);
  return res;
}

int main()
{
  int count;
  uint tmp;
  vector<uint> inputs;
  cin>>count;
  for(int i = 0; i < count; i++){
    cin>>tmp;
    inputs.push_back(tmp);
  }
  cout<<nInverse(inputs)<<endl;
  return 0;
}
