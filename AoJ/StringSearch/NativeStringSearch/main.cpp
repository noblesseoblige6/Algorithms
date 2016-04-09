#include <bits/stdc++.h>
using namespace std;

int main()
{
  string org, str;

  cin >> org >> str;

  if(org.size() >= str.size()){
    for(int i = 0; i < org.size()-str.size()+1;++i){
      string tmp;
      copy(org.begin()+i, org.begin()+i+str.size(), back_inserter(tmp));
      // cout<<tmp<<endl;
      if(tmp == str)
        cout<<i<<endl;
    }
  }
  return 0;
}
