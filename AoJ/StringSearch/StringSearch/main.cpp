#include <bits/stdc++.h>
using namespace std;

int main()
{
  string org, str;

  cin >> org >> str;
  if(org.size() >= str.size()){
    int i, j;
    for(i = 0; i < org.size()-str.size()+1; ){
      for(j = 0; j < str.size(); ++j){
        if(org[i+j] != str[j]){
          i += j;
          break;
        }
      }
      if(j == str.size()){
        cout<<i<<endl;
        ++i;
      }
    }
  }
  return 0;
}
