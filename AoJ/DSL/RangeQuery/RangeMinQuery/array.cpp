#include <bits/stdc++.h>

#define INI_VAL 2147483647
#define PrintDebug cout<<"TEST"<<endl;

using namespace std;

const int MAX_N = 131072;
int n;
int dat[MAX_N * 4];

void init()
{
  for(int i = 0; i < 2*n-1; ++i)
    dat[i] = INI_VAL;
}

void Update(int i, int x)
{
  i += n-1;
  dat[i] = x;

  // Trace back until parent
  while(i > 0)
  {
    i = (i-1)/2;
    dat[i] = min(dat[2*i+1], dat[2*i+2]);
  }
}

int Query(int a, int b, int k, int l, int r)
{
  if(r <= a || b <= l)
    return INI_VAL;

  // In range completely
  if(a <= l && r <= b)
  {
    // cout<<"TEST "<<k<<endl;
    return dat[k];
  }
  else
  {
    int vl = Query(a, b, k * 2 + 1, l, (l + r)/2);
    int vr = Query(a, b, k * 2 + 2, (l + r)/2, r);

    return min(vl, vr);
  }
}

int main()
{
  int q;
  cin >> n >> q;
  int num = n;

  n = n % 2 == 0 ? n : n + 1;
  init();

  int o, x, y;
  for(int i = 0;  i < q; ++i){
    // cin >> o >> x >> y;
    scanf("%d %d %d", &o, &x, &y);

    if(o == 0)
    {
      Update(x, y);
    }
    else if(o == 1)
    {
      printf("%d\n", Query(x, y+1, 0, 0, num));
    }
  }

  return 0;
}
