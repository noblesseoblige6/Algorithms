#include<iostream>
#include<cstdlib>
#include<limits.h>
using namespace std;

int main(int argc, char* argv[]){
  int array[] = {4, 5, 1, 10, 3, 4, 1};
  int cumulativeSum[8] = {0};
  int sum = 0;
  int t = 3;

  for(int i = 1; i < 8; i++){
    cumulativeSum[i] = cumulativeSum[i-1] + array[i-1];
  }

  int max = INT_MIN;
  int tmp;
  for(int i = 0; i < 8 - t; i++){
    tmp = cumulativeSum[i+t] - cumulativeSum[i];
    if(max < tmp) max = tmp;
  }
  cout<<"MAX: "<<max<<endl;
  return 1;
}
