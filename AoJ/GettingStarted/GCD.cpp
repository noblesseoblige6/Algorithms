#include<bits/stdc++.h>
using namespace std;

int greatestCommonDivisor(int a, int b)
{
  int g, s;
  if(a < b){
    g = b - a;
  s = a;
  }
  else{g = a - b;
  s = b;
  }
  while(1){
    int r = g%s;
    if(g%s == 0 ){return s;}
  g = s; s = r;
  }
}

int main()
{
  int a, b;
  cin>>a>>b;
  cout<<greatestCommonDivisor(a, b)<<endl;
  return 0;
}
