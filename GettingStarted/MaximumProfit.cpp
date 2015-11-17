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

bool ascend(int a, int b)
{
  return a > b;
}

int getMaxProfit(vector<int>& numbers)
{
  unsigned int size = numbers.size();
  int max = INT_MIN;
  int min = numbers[0];

  for(int i = 1; i < size; i++){
    max = max > numbers[i]-min ? max : numbers[i]-min;
    min = min < numbers[i] ? min : numbers[i];
  }

  return max;
}

int main()
{
  int inputNum;
  int data;
  vector<int> numbers;

  cin>>inputNum;
  for(int i = 0; i <inputNum; i++){
    cin>>data;
    numbers.push_back(data);
  }
  cout<<getMaxProfit(numbers)<<endl;
  
  return 0;
}
