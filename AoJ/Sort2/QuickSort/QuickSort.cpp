#include<bits/stdc++.h>
using namespace std;

vector<pair<char, int> > parseAndMerge(vector<pair<char, int> >& in, int l, int r)
{
  if(l >= r){return vector<pair<char, int> >(1, in[r]);}
  int m = (l+r)/2;
  //@comment Parse vector
  vector<pair<char, int> > lVec = parseAndMerge(in, l, m);
  vector<pair<char, int> > rVec = parseAndMerge(in, m+1, r);

  //@comment Merge parsed vectors
  int size = lVec.size() + rVec.size();
  vector<pair<char, int> > res;
  for(int lCount = 0, rCount = 0; lCount+rCount < size;){
    if(rCount >= rVec.size()){
      res.push_back(lVec[lCount]);
      lCount++;
    }else if(lCount >= lVec.size()){
      res.push_back(rVec[rCount]);
      rCount++;
    }else if(lVec[lCount].second <= rVec[rCount].second){
      res.push_back(lVec[lCount]);
      lCount++;
    }else{
      res.push_back(rVec[rCount]);
      rCount++;
    }
  }
  return res;
}

vector<pair<char, int> > mergeSort(vector<pair<char, int> >& in)
{
  //@comment To avoid refering to out of the index, 
  //the size of vector should subtracte 1
  return parseAndMerge(in, 0, in.size()-1);
}

int partition(vector<pair<char, int> >& arr, int l, int r)
{
  int p = arr[r].second;
  int idx = l;
  for(int i = l; i < r; i++){
    if(arr[i].second <= p){
      pair<char, int> tmp = arr[i];
      arr[i] = arr[idx];
      arr[idx] = tmp;
      idx++;
    }
  }
  pair<char, int> tmp = arr[r];
  arr[r] = arr[idx];
  arr[idx] = tmp;
  return idx;
}

void quickSort(vector<pair<char, int> >& arr, int l, int r)
{
  if(l >= r){return;}
  int m = partition(arr, l, r); 
  quickSort(arr, l, m-1); 
  quickSort(arr, m+1, r); 
}


bool isQuickSortStable(vector<pair<char, int> >& cards)
{
  //@comment sort by merge sort to compare the result of quick sort
  vector<pair<char, int> > cpCards; 
  copy(cards.begin(), cards.end(), back_inserter(cpCards));
  cpCards = mergeSort(cpCards); 

  quickSort(cards, 0, cards.size()-1);

  //@comment Compare two results
  for(int i = 0; i < cards.size(); i++){
    if(cards[i].first != cpCards[i].first){return false;}
  }
  return true;

}


int main()
{
  int count;
  char sign;
  int num;
  vector<pair<char, int> > cards;
  cin>>count;
  for(int i = 0; i < count; i++){
    cin>>sign>>num;
    cards.push_back(pair<char, int>(sign, num));
  }
  bool isStable = isQuickSortStable(cards);
  if(isStable){cout<<"Stable"<<endl;}
  else{cout<<"Not stable"<<endl;}
  for(int i = 0; i < count; i++){
    cout<<cards[i].first<<" "<<cards[i].second<<endl;
  }
  return 0;
}
