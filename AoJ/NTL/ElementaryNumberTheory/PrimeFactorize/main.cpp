#include <bits/stdc++.h>
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

int main()
{
  ull n;
  cin >> n;
  vector<ull> primes;
  Factorize(n, primes);

  cout<<n<<": ";
  for(int i = 0; i < primes.size(); ++i)
  {
    (i == primes.size()-1) ?
      cout<<primes[i]<<endl : cout<<primes[i]<<" ";
  }
  return 0;
}
