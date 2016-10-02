#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull Power(ull x, ull n)
{
  ull tmp = 1;
  if(n > 0)
  {
    tmp = Power(x, n/2);
    tmp = n % 2 == 0 ? (tmp*tmp) : (tmp*tmp)*x;
  }

  return tmp;
}

void Factorize(int n, vector<int>& primes)
{
  int nSq = sqrt(n);
  int d = 2;
  while(d <= nSq)
  {
    if(n % d == 0)
    {
      n /= d;

      primes[d]++;
      continue;
    }
    d++;
  }

  if(n != 1)
  {
    primes[n]++;
  }
}


int main()
{
  int n, x;
  cin >> n;

  vector<int> lcm(1001, 0);
  for(int i = 0; i < n; ++i)
  {
    cin >> x;

    vector<int> cm(1001, 0);
    Factorize(x, cm);

    for(int j = 0; j < 1001; ++j)
    {
      lcm[j] = max(lcm[j], cm[j]);
    }
  }

  ull res = 1;
  for(int i = 1; i < 1001; ++i)
  {
    if(lcm[i] != 0)
    {
      // cout<<i<<" "<<lcm[i]<<" "<<pow((double)i, (double)lcm[i])<<" "<<res<<endl;
      res *= Power(i, lcm[i]);
    }
  }
  cout<<res<<endl;

  return 0;
}
