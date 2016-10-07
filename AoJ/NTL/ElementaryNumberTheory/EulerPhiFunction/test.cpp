#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long int ll;
ll N;
vector<ll>D;
ll ans;
ll M;
int main()
{
  scanf("%lld",&N);
  M=N;
  for(int i=2;i*i<=N;i++){
    if(N%i==0){
      for(int j=0;j<D.size();j++){
        if(i%D[j]==0)goto cc;
      }
      D.push_back(i);
    }
cc:;
  }
  for(int i=0;i<D.size();i++){
    while(true){
      if(M%D[i]!=0)break;
      M/=D[i];
    }
  }

  if(M!=1)D.push_back(M);
  ans=N;
  for(int i=0;i<D.size();i++){
    ans*=(D[i]-1);
    ans/=D[i];
    //printf("%d\n",D[i]);
  }
  printf("%d\n",ans);
  return 0;
}
