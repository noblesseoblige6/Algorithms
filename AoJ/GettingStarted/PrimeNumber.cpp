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

int countPrimeNumbers(vector<int>& numbers)
{
  unsigned int size = numbers.size();
  unsigned int oddNum = (int)ceil(numbers[0]/2);
  vector<bool> isPrimeNum(oddNum, true);
  int upperLimit = (int)ceil(sqrt(numbers[0])/2);
  int odd;
  //奇数分だけのフラグを用意 isPrimeNum[i]->2i+1を指す
  isPrimeNum[0] = false; //１は素数としない
  //エラトステネスのふるいの作成
  for(int i = 1; i <= upperLimit; i++){
    odd = 2*i+1;
    if(isPrimeNum[i]){
      for(int j = i + odd; j <= oddNum; j+=odd){
        isPrimeNum[j] = false;
      }
    }
  }

  int count = 0;
  for(int i = 0 ; i < size; i++){
    if(numbers[i] == 2){count++;} 
    else if(numbers[i]%2 == 0){continue;}
    else if(isPrimeNum[(numbers[i]-1)/2]){count++;}
  }
  return count;
}

int main()
{
  int inputNum;
  int count = 0;
  int data;
  cin>>inputNum;
  vector<int> numbers;

  for(int i = 0; i <inputNum; i++){
    cin>>data;
    numbers.push_back(data);
  }
  sort(numbers.begin(), numbers.end(), ascend);
  cout<<countPrimeNumbers(numbers)<<endl;
  
  return 0;
}
