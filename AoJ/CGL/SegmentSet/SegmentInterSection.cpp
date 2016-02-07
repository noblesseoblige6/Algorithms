#include <bits/stdc++.h>
using namespace std;
class Segment
{
  public:
    pair<int, int> s;
    pair<int, int> e; 
    Segment(){};
    ~Segment(){};
    Segment(int x1, int y1, int x2, int y2)
    {
      s = make_pair(x1, y1);
      e = make_pair(x2, y2);
    }
};
bool descendY(Segment seg1, Segment seg2)
{
  //@commnet If y-coordinates of the start points are the same,
  //sort by the high y-coordinate of the end points
  if(seg1.s.second == seg2.s.second){return seg1.e > seg2.e;}
  return seg1.s.second < seg2.s.second;
}

bool isIntersected(Segment a, Segment b)
{
  int x = a.s.first;
  int y = b.s.second;
  if(x >= b.s.first && x <= b.e.first &&
      y >= a.s.second && y <= a.e.second){return true;}
  return false;
}


int segmentIntersection(vector<Segment>& segments)
{
  int interCount = 0;
  vector<Segment> segStack;
  sort(segments.begin(), segments.end(), descendY);
  for(int i = 0; i < segments.size(); i++){
    // cout<<"("<<segments[i].s.first<<", "<<segments[i].s.second<<"), ";
    // cout<<"("<<segments[i].e.first<<", "<<segments[i].e.second<<")"<<endl;
    //@comment The parallel segment to x-axis
    if(segments[i].s.second == segments[i].e.second){
      Segment horSeg = segments[i];
      for(int j = 0; j < segStack.size(); j++){
        int x = segStack[j].s.first;
        if(isIntersected(segStack[j], horSeg)){interCount++;}
      }
    }else{
      if(!segStack.empty()){
        pair<int, int> p = segStack.back().e;
        while(p.second <= segments[i].s.second && !segStack.empty()){segStack.pop_back();}
      }
      segStack.push_back(segments[i]);
    }
  }
return interCount;
}

int main(int argc, char* argv[])
{
  int count;
  int x1, y1;
  int x2, y2;
  vector<Segment> in;
  cin>>count;
  for(int i = 0; i < count; i++){
    cin>>x1>>y1>>x2>>y2;
    if(y1 <= y2){in.push_back(Segment(x1, y1, x2, y2));}
    else{in.push_back(Segment(x2, y2, x1, y1));}
  } 
  cout<<segmentIntersection(in)<<endl;
  return 0;
}
