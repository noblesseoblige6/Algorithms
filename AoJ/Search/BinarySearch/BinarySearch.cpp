#include <bits/stdc++.h>
using namespace std;

struct process
{
  string name;
  int time;
};
int next(int idx, int n)
{
if(idx >= n){return idx - n;}
return idx;
}

bool search(const vector<int>& v, int l, int r, int in)
{
if(l >= r){
  if(v[l-1] == in){return true;}
  return false;
}
int m = (l+r)/2;
if(v[m] > in){return search(v, l, m, in);}
else{return search(v, m+1, r, in);}
}

int binarySearch(const vector<int>& s, const vector<int>& t)
{
  int count = 0;
  vector<int> lSeq;
  vector<int> sSeq;
  if(s.size() < t.size()){
    sSeq = s;
    lSeq = t;
  } else{
    sSeq = t;
    lSeq = s;
  }
  sort(sSeq.begin(), sSeq.end());
  sort(lSeq.begin(), lSeq.end());
  for(int i = 0; i < lSeq.size(); i++){
    if(lSeq[i] == lSeq[next(i+1, lSeq.size())]){continue;}
    if(search(sSeq, 0, sSeq.size(), lSeq[i])){count++;}
  }
  return count;
}

int main()
{
  int n, q;
  vector<int> s, t; 
  int in;
  cin>>n;
  for(int i = 0; i < n; i++){  
    cin>>in;
    s.push_back(in);
  }
  cin>>q;
  for(int i = 0; i < q; i++){  
    cin>>in;
    t.push_back(in);
  }
  cout<<binarySearch(s, t)<<endl;
  return 0;
}
