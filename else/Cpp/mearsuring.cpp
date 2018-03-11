#include<bits/stdc++.h>

using namespace std;

int main(){
  int array[] = {4, 5, 1, 10, 3, 4, 100};
  int t = 3;
  int max = INT_MIN;
  int tmp = 0;

  for(int i = 0; i < t; i++){
    tmp += array[i];
  }

  for(int i = t; i < 7 ; i++){
    tmp -= array[i - t];
    tmp += array[i];
    if(max < tmp) max = tmp;
  }
  cout<<"Max: "<<max<<endl;
}
