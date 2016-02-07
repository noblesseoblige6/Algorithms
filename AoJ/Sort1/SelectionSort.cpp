#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void printData(vector<int>& values)
{
  unsigned int size = values.size();
  for(int i = 0; i < size; i++){
    if(i == size-1){cout<<values[i]<<endl;}
    else{cout<<values[i]<<" ";}
  }
}
int selectionSort(vector<int>& values)
{
  unsigned int size = values.size();
  int count = 0;
  int min;
  for(int i = 0; i < size-1; i++){
    min = i;
    for(int j = i+1; j < size; j++){
      if(values[j] <values[ min]){min = j;}
    }  
    if(min != i){
      swap(values[i], values[min]);
      count++;
    }
  }
  printData(values);
  return count;
}

int main()
{
  int count;
  int data;
  vector<int> values;
  cin>>count;

  for(int i = 0; i< count; i++){
    cin>>data;
    values.push_back(data);
  }

  cout<<selectionSort(values)<<endl;
}
