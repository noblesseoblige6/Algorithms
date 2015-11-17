#include <bits/stdc++.h>
using namespace std;

struct numberedData
{
  int id;
  char initial;
  int number;
};

void swap(int* a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void printResult(vector<numberedData>& values)
{
  //Print result
  unsigned int size = values.size();
  bool isStable = true;
  cout<<values[0].initial<<values[0].number<<" ";
  for(int i = 1; i < size; i++){
    if(isStable){
      if(values[i-1].number == values[i].number && 
          values[i-1].id > values[i].id){isStable = false;}
    }
    if(i != size-1){cout<<values[i].initial<<values[i].number<<" ";}
    else{cout<<values[i].initial<<values[i].number<<endl;}
  }

  if(isStable){cout<<"Stable"<<endl;}
  else{cout<<"Not stable"<<endl;}
}

void bubbleSort(vector<numberedData> values)
{
  unsigned int size = values.size();
  int count = 0;
  for(int i = 0; i < size; i++){
    for(int j = size-1; j > i; j-- ){
      if(values[j].number < values[j-1].number){
        numberedData tmp = values[j];
        values[j] = values[j-1];
        values[j-1] = tmp;
        count++;
      }
    }
  }
  printResult(values);
} 

void selectionSort(vector<numberedData> values)
{
  unsigned int size = values.size();
  int count = 0;
  int min;
  for(int i = 0; i < size-1; i++){
    min = i;
    for(int j = i+1; j < size; j++){
      if(values[j].number <values[min].number){min = j;}
    }  
    if(min != i){
      swap(values[i], values[min]);
      count++;
    }
  }
  printResult(values);
}

int main()
{
  int count;
  string data;
  numberedData tmp;
  vector<numberedData> values;
  cin>>count;

  for(int i = 0; i< count; i++){
    cin>>data;
    tmp.id = i; 
    tmp.initial = data[0]; 
    tmp.number = atoi(&data[1]);
    // cout<<tmp.initial<<" "<<tmp.number<<endl;
    values.push_back(tmp);
  }
  bubbleSort(values);
  selectionSort(values);

  return 0;
}
