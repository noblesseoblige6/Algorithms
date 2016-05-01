#include <bits/stdc++.h>
using namespace std;

int main()
{
  string str;
  int n;
  cin >> str >> n;
  vector<string> patterns(n);

  for(int i = 0; i < n; ++i)
    cin >> patterns[i];

  for(int i = 0; i < n; ++i){
    string pattern = patterns[i];
    if(str.size() < pattern.size()){
      cout<<0<<endl;
      continue;
    }

    map<char, int> spaces;
    int count = 1;
    for(string::reverse_iterator i = pattern.rbegin(); i != pattern.rend(); ++i){
      if(spaces.count(*i) == 0)
        spaces[*i] = count;
      count++;
    }
    bool isFound = false;
    for(int i = pattern.size()-1; i < str.size(); ){
      int start = i;
      for(int j = 0; j < pattern.size(); ++j){
        int now = i-j;
        if(str[now] != pattern[pattern.size()-1-j]){
          int next =
            spaces.find(str[start+1]) == spaces.end() ? start+pattern.size()+1 : start+spaces[str[start+1]];
          if(next < start){
            i++;
          }
          else{i = next;}
          break;
        }
        else if(j+1 == pattern.size()){
          cout<<1<<endl;
          isFound = true;
          break;
        }
      }
      if(isFound)
        break;
    }
    if(!isFound)
      cout<<0<<endl;
  }
  return 0;
}
