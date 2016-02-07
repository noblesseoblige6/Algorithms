#include <bits/stdc++.h>
using namespace std;

int bubbleSort(vector<int>& values)
{
  unsigned int size = values.size();
  int count = 0;

  for(int i = 0; i < size; i++){
    for(int j = size-1; j > i; j-- ){
      if(values[j] < values[j-1]){
        int tmp = values[j];
        values[j] = values[j-1];
        values[j-1] = tmp;
        count++;
      }
    }
  }

  for(int i = 0; i < size; i++){
    if(i == size-1){
      cout<<values[i]<<endl;
    }
    else{
      cout<<values[i]<<" "; 
    }
  }
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

  cout<<bubbleSort(values)<<endl;
}
