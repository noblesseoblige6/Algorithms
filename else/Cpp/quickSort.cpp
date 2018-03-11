#include<bits/stdc++.h>

using namespace std;

void quickSort(vector<int>&, int, int);
void quick_sort(vector<int>& data, int left, int right);

int main(int argc, char* argv[])
{
  int n = 8;
  vector<int> array;
  srand((unsigned)time(NULL));
  for(int i = 0; i < n; i++){
    array.push_back(rand()%10);
    cout<< array[i]<<" ";
  }
  cout<<endl;
  quickSort(array, 0, n);
  for(int i = 0; i < n; i++){
    cout<< array[i]<<" ";
  }
  cout<<endl;
  return 1;
}

void quickSort(vector<int>& a, int l, int r)
{
  int c = (l + r)/2;
  int p = a[c];
  if(l < r){
    int i = l, j = r;
    while(1){
      while(a[i] < p){ i++;}
      while(a[j] > p){ j--;}
      if(i >= j ) break;
      swap(a[i], a[j]);
      i++;
      j--;
    }
    quickSort(a, l, i-1);
    quickSort(a, j+1, r);
  }
}
