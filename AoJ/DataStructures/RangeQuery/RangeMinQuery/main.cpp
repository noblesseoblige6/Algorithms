#include <bits/stdc++.h>

#define INI_VAL 2147483647
#define PrintDebug cout<<"TEST"<<endl;

using namespace std;

struct Segment
{
  Segment* p;
  Segment* l;
  Segment* r;

  int start;
  int end;
  int min;

  Segment() : p(NULL), l(NULL), r(NULL), start(-1), end(-1), min(INI_VAL){};
};
Segment* ComposeTree(int s, int e, vector<Segment*>& arr)
{
  if(s == e-1)
  {
    Segment* seg = new Segment();
    seg->start = s;
    seg->end   = e;
    arr[s] = seg;
    return seg;
  }

  Segment* seg = new Segment();
  int m = (s + e) / 2.0;
  seg->l = ComposeTree(s, m, arr);
  seg->r = ComposeTree(m, e, arr);

  seg->l->p = seg;
  seg->r->p = seg;

  seg->start = s;
  seg->end = e;
  return seg;
}

void UpdateSegmentTree(Segment* s, int val)
{
  // Node is parent
  if(s == NULL)
    return;

  int minl, minr;
  minl = minr = INI_VAL;

  if(s->l != NULL)
    minl = s->l->min;
  if(s->r != NULL)
    minr = s->r->min;

  s->min = min(minl, minr);
  UpdateSegmentTree(s->p, val);
}

void Update(int id, int val, vector<Segment*>& arr)
{
  arr[id]->min = val;

  UpdateSegmentTree(arr[id]->p, val);
}

bool IsInRange(int s, int e, int v)
{
  return s <= v && v <= e;
}

int FindMin(const int& a, const int& b, const Segment* s)
{
  // segment is in range
  if(s->start == a && s->end == b)
    return s->min;

  Segment* cl = s->l;
  Segment* cr = s->r;

  if( cl != NULL &&
      IsInRange(cl->start, cl->end, a) &&
      IsInRange(cl->start, cl->end, b))
  {
    return FindMin(a, b, cl);
  }
  else if( cr != NULL &&
           IsInRange(cr->start, cr->end, a) &&
           IsInRange(cr->start, cr->end, b))
  {
    return FindMin(a, b, cr);
  }
  else if( cl != NULL &&
           cr != NULL &&
           IsInRange(cl->start, cl->end, a) &&
           IsInRange(cr->start, cr->end, b))
  {
    return min( FindMin(a, cl->end, cl),
                FindMin(cr->start, b, cr));
  }

  return s->min;
}

int main()
{
  int n, q;
  cin >> n >> q;

  Segment* seg = NULL;
  vector<Segment*> arr;
  arr.resize(n);

  seg = ComposeTree(0, n, arr);
  int o, x, y;
  for(int i = 0;  i < q; ++i){
    // cin >> o >> x >> y;
    scanf("%d %d %d", &o, &x, &y);

    if(o == 0){
      Update(x, y, arr);
      // for(int i = 0; i < arr.size(); ++i)
      //   cout<<arr[i]->min<<" ";
      // cout<<endl;
    }
    else if(o == 1){
      // cout << findMin(x, y, seg) << endl;
      printf("%d\n", FindMin(x, y+1, seg));
    }
  }

  return 0;
}
