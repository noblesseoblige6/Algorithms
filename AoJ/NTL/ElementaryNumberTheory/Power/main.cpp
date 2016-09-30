#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const ull D = 1000000007;

ull Power(ull x, ull n)
{
  ull tmp = 1;
  if(n > 0)
  {
    tmp = Power(x, n/2);
    tmp = n % 2 == 0 ? (tmp*tmp)%D : (((tmp*tmp)%D)*x%D)%D;
  }

  return tmp;
}

int main()
{
  ull x, n ;
  cin >> x >> n;
  cout<<Power(x, n)<<endl;
  return 0;
}
