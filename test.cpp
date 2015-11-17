#include <bits/stdc++.h>
using namespace std;
bool compareY(pair<int, int>  p1, pair<int, int> p2)
{
  if(p1.second == p2.second){return p1.first < p2.first;}
return p1.second < p2.second;
}

int main(int argc, char* argv[])
{
  vector<pair<int, int> > test(10);
  for(int i = 0; i < test.size(); i++){
    test[i] =make_pair(i*i%10, i);
  }
  sort(test.begin(), test.end(), compareY);
  for(int i = 0; i < test.size(); i++){
    cout<<test[i].first<<" "<<test[i].second<<endl;
  }
  return 0;
}
