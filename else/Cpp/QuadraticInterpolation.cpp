#include <bits/stdc++.h>

using namespace std;

float f(float x)
{
static const int d = 1;
static const int ini = 0;
// return -(d-ini)*(x + 1)*(x + 1) + d;
return (d-ini)*(x*x+2*x-1)+d;
}

int main()
{
  for(int i = 0; i <= 10; i++){
    cout<<i/10.0f<<" "<<f(i/10.0f)<<endl; 
  }
  return 0;
}
