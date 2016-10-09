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

ull PhiFunc(ull n)
{
  vector<ull> primes;
  Factorize(n, primes);

  //@comment First prime is multiplied
  double count = (1.0-1.0/primes[0]);
  for(int i = 1; i < primes.size(); ++i)
  {
    if(primes[i-1] != primes[i])
      count *= (1.0-1.0/primes[i]);
  }
    count *= n;

  return (ull)count;
}

int main()
{
  ull n;
  cin >> n;
  printf("%llu\n", PhiFunc(n));

  return 0;
}
