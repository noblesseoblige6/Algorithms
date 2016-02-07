#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void printVector(vector<int>& values)
{
  for(int i = 0; i < values.size(); i++){
  if(i == values.size() - 1){cout<<values[i];}
  else{cout<<values[i]<<" ";}
  }
  cout<<endl;
}

void insertionSort(vector<int>& values)
{
  int tmp, i, j;
  unsigned int size = values.size();
  for(i = 1; i < size; i++){
    tmp = values[i];
    for(j = i; j > 0 && values[j-1] > tmp; j--){
      values[j] = values[j-1];
    }
    values[j] = tmp;
    printVector(values);
  }
}

int main()
{
  int count;
  cin>>count;
  vector<int> values(count);
  for(int i = 0; i < count; i++){
    cin>>values[i];
  }
  printVector(values);
  insertionSort(values);
  return 0;
}
