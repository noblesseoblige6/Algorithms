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
      if(spaces.count(*i) == 0)
        spaces[*i] = count;
      count++;
    }

    for(int i = pattern.size()-1; i < str.size(); ){
      int start = i;
      for(int j = 0; j < pattern.size(); ++j){
        int now = i-j;
        if(str[now] != pattern[pattern.size()-1-j]){
          int next =
            spaces.find(str[now]) == spaces.end() ? now+pattern.size() : now+spaces[str[now]];
          if(next < start){
            i++;
          }
          else{i = next;}
          break;
        }
        else if(j+1 == pattern.size()){
          cout<<now<<endl;
          i++;
        }
      }
    }
  }
  return 0;
}
