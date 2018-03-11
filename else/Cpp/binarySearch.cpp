#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n = 10000;
  int a[n];
  for(int i = 0; i < n; i++){
    a[i] = i;
  }
int target = 3;
int head = 0;
int tail = n-1;
int mid;
while(1){
  mid = (tail + head)/2;
  if(a[mid] < target){head = mid;}
  else if(a[mid] > target){tail = mid;}
  else{break;}
}
cout<<target<<" is "<<mid<<"th"<<endl;
return 0;
}
