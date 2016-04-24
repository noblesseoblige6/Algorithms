#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const ull P = 1000000007ULL;

ull gen_hash(const string& str, const vector<ull>& ps, const int& n)
{
  ull v = 0;
  for(int i = 0; i < n; ++i){
    v += str[n-1-i]*ps[i];
  }
  return v;
}

int main()
{
  string pattern, str;
  cin >> str >> pattern;

  if(str.size() >= pattern.size()){
    int n = pattern.size();

    vector<ull> p_patterns(n+1);
    p_patterns[0] = 1;
    for(int i = 0; i < n; ++i){
      p_patterns[i+1] = p_patterns[i] * P;
    }

    ull pattern_hash = gen_hash(pattern, p_patterns, n);
    ull hash_val = gen_hash(str, p_patterns, n);

    for(int i = 0; i < str.size(); ++i){
      if(hash_val == pattern_hash)
        printf("%d\n", i);
      //@comment Update hash value
      hash_val = (hash_val*P + str[i+n] - str[i]*p_patterns[n]);
    }
  }
  return 0;
}
