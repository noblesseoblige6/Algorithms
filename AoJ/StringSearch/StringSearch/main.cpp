#include <bits/stdc++.h>
using namespace std;

int main()
{
  string pattern, str;

  cin >> str >> pattern;
  if(str.size() >= pattern.size()){
    map<char, int> spaces;
    int count = 1;
    for(string::reverse_iterator i = pattern.rbegin()+1; i != pattern.rend(); ++i){
      if(spaces.find(pattern[*i]) == spaces.end())
        spaces[*i] = count++;
    }

    for(int i = pattern.size()-1; i < str.size(); ){
      // cout<<i<<endl;
      for(int j = 0; j < pattern.size(); ++j){
        if(str[i-j] != pattern[pattern.size()-1-j]){
          int prev = i-pattern.size()-1;
          spaces.find(str[i-j]) == spaces.end() ? i = i-j+pattern.size() : i = i-j+spaces[str[i-j]];
          if(i < prev)
            i = prev + pattern.size();

          break;
        }
        else if(j+1 == pattern.size()){
          cout<<i-j<<endl;
          i++;
        }
      }
    }
  }
  return 0;
}
