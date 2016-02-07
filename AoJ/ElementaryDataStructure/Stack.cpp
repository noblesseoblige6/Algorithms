#include <bits/stdc++.h>
using namespace std;

int reversePolish(vector<string>& values)
{
  int res;
  string tmp = values.back();
  values.erase(values.end());
  
  if(tmp == "+"){
    int a = reversePolish(values), b = reversePolish(values);
    return b + a;
  } else if(tmp == "-"){
    int a = reversePolish(values), b = reversePolish(values);
    return b - a;
  } else if(tmp == "*"){
    int a = reversePolish(values), b = reversePolish(values);
    return b * a;
  } 
  res = atoi(tmp.c_str());
  return res;
}

int main()
{
  string data;
  vector<string> inputs; 
  while(1){
    cin>>data;
    if(cin.eof()){break;}
    inputs.push_back(data);
  }
 cout<<reversePolish(inputs)<<endl;
}
