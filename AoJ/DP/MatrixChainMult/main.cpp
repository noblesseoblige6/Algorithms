#include <bits/stdc++.h>

using namespace std;

int matrixChainMulti(const vector<pair<int, int> >& m)
{
  int n = m.size();
  vector<vector<int> > cost(n, vector<int>(n));
  vector<vector<int> > p(n, vector<int>(2*n));

  for(int i = 1; i < n; ++i){
    for(int j = 1; j < n; j+=i){
      for(int k = 0; k < i; k+=j){
        int tmp = cost[i-j][k%(n-(i-1))] + cost[j][] + p[i-j][]*p[i-j][]*p[j][];
        if(cost[i][k] > tmp){
          cost[i][k] = tmp;

        }
      }
    }
  }
  return cost[n-1][0];
}

int main()
{
  int n;
  cin>>n;
  int row, col;
  vector<pair<int ,int> > m(n);
  while(cin>>row>>col){
    m.push_back(pair<int, int>(row, col));
  }
  cout<<matrixChainMulti(m)<<endl;
  return 0;
}
