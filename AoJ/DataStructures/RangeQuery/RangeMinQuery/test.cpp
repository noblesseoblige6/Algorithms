#include <iostream>
#include <algorithm>
#define INF 2147483647
using namespace std;
int tree[(1<<18)];
int n,q;

void update(int i,int x) {
  i+=(n-1);
  tree[i] = x;
  while(i!=0){
    i=(i-1)/2;
    tree[i] = min(tree[i*2+1],tree[i*2+2]);
  }
}

int find(int a ,int b,int ima,int L,int R){
  if(R<=a || b<=L) return INF;
  if(a<=L && R<=b) return tree[ima];
  int M = (R+L)/2;
  return min(find(a,b,ima*2+1,L,M),find(a,b,ima*2+2,M,R));
}

int main(){
  cin >> n >>q;
  int N=1;
  while(N<n)N*=2;
  n=N;

  for(int i=0;i<n;i++)update(i,INF);
  while(q--){
    int com,x,y;
    cin >>com >> x >> y;
    if(com == 0) update(x,y);
    if(com == 1) cout << find(x,y+1,0,0,n) <<endl;
  }
  return 0;
}
