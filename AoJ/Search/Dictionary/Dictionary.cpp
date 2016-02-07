#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
  int count;
  char inOpe[10], inStr[12];
  set<string> dictionary;
  cin>>count;
  for(int i = 0; i < count; i++){
    //@comment If use cin, it is too late
    scanf("%s %s", &inOpe, &inStr);
    if(inOpe[0] == 'i'){dictionary.insert(inStr);}
    else{
      if(dictionary.find(inStr) != dictionary.end()){cout<<"yes"<<endl;}
      else{cout<<"no"<<endl;}
    }
  }
}
