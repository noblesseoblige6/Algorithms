#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const ull D = 1000000007;

int main()
{
  ull e, p;
  cin >> e >> p;
  ull res = 1;
  for(int i = 0; i < p; ++i)
    res *= e;
  cout<<res%D<<endl;
  return 0;
}
