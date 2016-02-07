#include <bits/stdc++.h>
using namespace std;

bool comb(int depth, int target, vector<int>& list)
{
  if(depth == list.size() || target < 0){return false;}
  if(target-list[depth] == 0){return true;}
  return comb(depth+1, target-list[depth], list) || comb(depth+1, target, list);
}

void  exhaustiveSearch(vector<int>& list, vector<int>& input)
{
  for(int i = 0; i < input.size(); i++){
    if(comb(0, input[i], list)){cout<<"yes"<<endl;}
    else{cout<<"no"<<endl;}
  }
}

int main()
{
  int listCount;
  int count;
  int tmp;
  vector<int> list;
  vector<int> input;

  cin>>listCount;
  for(int i = 0; i < listCount; i++){
    cin>>tmp;
    list.push_back(tmp);
  }
  cin>>count;
  for(int i = 0; i < count; i++){
    cin>>tmp;
    input.push_back(tmp);
  }

  exhaustiveSearch(list, input);
  return 0;
}
