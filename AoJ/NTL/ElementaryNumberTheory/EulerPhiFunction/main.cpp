#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

void Factorize(ull n, vector<ull>& primes)
{
  ull nSq = sqrt(n);
  ull d = 2;
  while(d <= nSq)
  {
    if(n % d == 0)
    {
      n /= d;
      primes.push_back(d);
      continue;
    }
    d++;
  }
  if(n != 1)
    primes.push_back(n);
}

int  PhiFunc(int n)
{
  vector<ull> primes;
  Factorize(n, primes);

  double count = 1;
  for(int i = 0; i < primes.size(); ++i)
  {
    cout<< primes[i]<<endl;
    count *= (1.0-1.0/primes[i]);
  }
    count *= n;

  return (int)count;
}

int main()
{
  int n;
  cin >> n;

  cout <<PhiFunc(n) << endl;

  return 0;
}
