#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
  int tmp = *a;
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

int insertionSort(vector<int>& values, int h)
{
  int tmp, count = 0, i, j;
  unsigned int size = values.size();

  // if(size/9.0 < h){return 0;}
  for(i = h; i < size; i++){
    tmp = values[i];
    for(j = i - h; j >= 0 && values[j] > tmp; j-=h){
      values[j+h] = values[j];
      count++;
    }
    values[j+h] = tmp;
  }
  return count;
}

void shellSort(vector<int>& values)
{
  int h, count = 0;
  vector<int> g;
  int tmp = values.size();
  g.push_back(1);
  for(int i = 1; ; i++){
    int tmp = 3*g[i-1] + 1;
    if(tmp > values.size()){break;}
    g.push_back(tmp);
  }
  h = g.size();
  for(int i = 0; i < h; i++){
  // cout<<"TEST "<<g[h-1-i]<<endl;
    count += insertionSort(values, g[h-1-i]);
  }
  //Output part
  cout<<h<<endl;
  for(int i = 0; i < h; i++){
    if(i != h-1){cout<<g[h-1-i]<<" ";}
    else{cout<<g[h-1-i]<<endl;}
  }
  cout<<count<<endl;

  for(int i = 0; i < values.size(); i++){
    cout<<values[i]<<endl;
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
  shellSort(values);
  return 0;
}
