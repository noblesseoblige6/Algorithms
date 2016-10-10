#include "NumberTheory.h"

typedef NTL::ull ull;

ull NTL::Power(ull x, ull n)
{
  ull res = 1;
  if(n > 0)
  {
    res = Power(x, n/2);
    res = n % 2 == 0 ? res*res : (res*res)*x;
  }

  return res;
}

void NTL::Factorize(ull n, std::vector<int>& primes)
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

ull NTL::LCM(ull x)
{
  // number of power
  std::vector<int> lcm(1001, 0);
  std::vector<int> cm(1001, 0);

  Factorize(x, cm);

  for(int j = 0; j < 1001; ++j)
  {
    lcm[j] = std::max(lcm[j], cm[j]);
  }

  ull res = 1;
  for(int i = 1; i < 1001; ++i)
  {
    if(lcm[i] != 0)
    {
      res *= Power(i, lcm[i]);
    }
  }
  return res;
}

ull NTL::FindNumberOfTotative(ull n)
{
  std::vector<int> primes;
  Factorize(n, primes);

  //@comment First prime is multiplied
  double count = n * (1.0-(1.0/primes[0]));
  for(int i = 1; i < primes.size(); ++i)
  {
    if(primes[i-1] != primes[i])
    {
      count *= (1.0-(1.0/primes[i]));
    }
  }

  return (ull)count;
}


