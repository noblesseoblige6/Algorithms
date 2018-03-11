#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n = 15;
  int a[] = {
  0,0,0,
  1,1,
  2,
  3,
  4,
  5,5,5,
  6,
  7,7,
  8
  };
int target = 0;
int head = 0;
int tail = n-1;
int mid;
int start, end;
while(1){
  mid = (tail + head)/2;
  if(a[mid] < target){head = mid;}
  else if(a[mid] > target){tail = mid;}
  else{
    for(int i = mid-1; i >= 0; i--){if(a[i] != a[mid]){start = i+1; break;}}
    for(int i = mid+1; i < n; i++){if(a[i] != a[mid]){end = i-1; break;}}
  break;
  }
}
cout<<target<<" is between "<<start<<" and "<<end<<endl;
return 0;
}
