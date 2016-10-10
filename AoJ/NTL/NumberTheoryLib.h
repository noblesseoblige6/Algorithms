#pragma once
#include <vector>
#include <cmath>
#include <algorithm>

namespace NTL
{

  typedef unsigned long long ull;

  ull Power(ull x, ull n);
  void Factorize(ull n, std::vector<int>& primes);
  ull LCM(ull x);
  ull FindNumberOfTotative(ull n);
}
