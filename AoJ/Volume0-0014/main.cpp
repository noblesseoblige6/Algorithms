#include <bits/stdc++.h>

using namespace std;

double f(const double& x)
{
  return x*x;
}

double integral(const int& nDiv)
{
  const int delta = 600 / nDiv;
  double sum = 0.0;
  for(int i = 1; i < nDiv; ++i)
    sum += f(delta*i) * delta;
  return sum;
}

int main()
{
  int n;
  while(cin>>n)
    printf("%f\n", integral(n));
  return 0;
}
