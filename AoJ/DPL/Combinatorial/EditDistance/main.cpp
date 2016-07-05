#include <bits/stdc++.h>

using namespace std;

int LD(const string& a, const string& b)
{
  vector<vector<int> > mat(a.size()+1, vector<int>(b.size()+1, 0));
  for(int i = 0; i < a.size()+1; ++i)
    mat[i][0] = i;
  for(int i = 0; i < b.size()+1; ++i)
    mat[0][i] = i;

  for(int i = 1; i < a.size()+1; ++i){
    for(int j = 1; j < b.size()+1; ++j){
      int c = a[i-1] == b[j-1] ? 0 : 1;
      mat[i][j] = min(min(mat[i-1][j]+1, mat[i][j-1]+1),
          mat[i-1][j-1] + c);
    }
  }
  return mat[a.size()][b.size()];
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  cout<<LD(s1, s2)<<endl;

  return 0;
}
