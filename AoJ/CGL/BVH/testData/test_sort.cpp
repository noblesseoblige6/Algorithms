#include <bits/stdc++.h>

using namespace std;

int main()
{
vector<int> v;
v.push_back(6);
v.push_back(2);
v.push_back(4);
v.push_back(1);

sort(v.begin(),v.begin()+3);
for(int i = 0; i < v.size(); ++i)
  cout<<v[i]<<" "<<endl;
cout<<endl;
return 0;
}
