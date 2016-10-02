#include<bits/stdc++.h>
using namespace std;

void Factorize(int n, vector<int>& primes, vector<int>& primeList)
{
  int nSq = sqrt(n);
  int d = 2;
  while(d <= nSq)
  {
    if(n % d == 0)
    {
      n /= d;

      if(primes[d] == 0)
        primeList.push_back(d);
      primes[d]++;
      continue;
    }
    d++;
  }
  if(n != 1)
  {
    if(primes[d] == 0)
      primeList.push_back(d);
    primes[d]++;
  }
}


int main()
{
  int n, x;
  cin >> n;

  vector<int> lcm(1001, 0);
  vector<int> primeList;
  for(int i = 0; i < n; ++i)
  {
    cin >> x;

    vector<int> cm(1001, 0);
    Factorize(x, cm, primeList);

    for(int j = 0; j < primeList.size(); ++j)
    {
      int idx = primeList[j];
      lcm[idx] = max(lcm[idx], cm[idx]);
    }
  }

  int res = 1;
  for(int i = 0; i < primeList.size(); ++i)
  {
    int idx = primeList[i];
    cout<<idx<<endl;
    res *= pow(idx, lcm[idx]);
  }
  cout<<res<<endl;

  return 0;
}
