#include <bits/stdc++.h>

using namespace std;

int LCS(const string& a, const string& b)
{
  vector<vector<int> > mat(a.size()+1, vector<int>(b.size()+1, 0));
  for(int i = 1; i < a.size()+1; ++i){
    for(int j = 1; j < b.size()+1; ++j){
      if(a[i-1] == b[j-1]){
        mat[i][j] = mat[i-1][j-1]+1;
      }else{
        mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
      }
    }
  }
  return mat[a.size()][b.size()];
}

int main()
{
  int n;
  string a, b;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a >> b;
    cout<<LCS(a, b)<<endl;
  }
  return 0;
}
