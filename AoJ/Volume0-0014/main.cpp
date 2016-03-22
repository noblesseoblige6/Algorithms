#include <bits/stdc++.h>

using namespace std;

const int X = 600;

double f(const double& x)
{
  return x*x;
}

double integral(const int& nDiv)
{
  const int delta = X / nDiv;
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
