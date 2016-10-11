#include <bits/stdc++.h>

#define TEST cout<<"TEST"<<endl
#define Print(i, a, b) std::cout<<i<<" "<<a<<" "<<b<<std::endl

using namespace std;

class vec2{
  public:
    double x;
    double y;
    vec2():x(0.0), y(0.0){};
    vec2(double val):x(val), y(val){};
    vec2(double x, double y):x(x), y(y){};
    vec2(const vec2& v) : x(v.x), y(v.y){};
    ~vec2(){};
    vec2& operator=(const vec2&);
    vec2 operator+(const vec2&) const;
    vec2 operator-(const vec2&) const;
    vec2 operator*(float);
    bool operator==(vec2);
    bool operator !=(vec2);
};

vec2& vec2::operator=(const vec2& b)
{
  x = b.x;
  y = b.y;
  return *this;
}

vec2 vec2::operator+(const vec2& b) const
{
  vec2 res;
  res.x = this->x + b.x;
  res.y = this->y + b.y;
  return res;
}

vec2 vec2::operator-(const vec2& b) const
{
  vec2 res;
  res.x = this->x - b.x;
  res.y = this->y - b.y;
  return res;
}

vec2 vec2::operator*(float m)
{
  return vec2(m*this->x, m*this->y);
}

bool vec2::operator==(vec2 b)
{
  if(this->x == b.x && this->y == b.y){return true;}
  return false;
}

bool vec2::operator!=(vec2 b)
{
  return !(*this == b);
}

bool descendy(const vec2& a, const vec2& b)
{
  return a.y == b.y ? a.x < b.x : a.y < b.y;
}

bool ascendx(const vec2& a, const vec2& b)
{
  if(a.x == b.x){return a.y < b.y;}
  return a.x > b.x;
}

bool descendx(const vec2& a,const vec2& b)
{
  if(a.x == b.x){return a.y < b.y;}
  return a.x < b.x;
}

struct Node
{
  int id;
  vec2 p;
  Node* l;
  Node* r;

  Node() : id(-1), p(vec2()), l(NULL), r(NULL){}
  Node(int id_, const vec2& p_) : id(id_), p(p_), l(NULL), r(NULL){}

  static bool descendId(const Node& a, const Node& b)
  {
    return a.id < b.id;
  }

  static bool descendy(const Node& a, const Node& b)
  {
    return a.p.y == b.p.y ? a.p.x < b.p.x : a.p.y < b.p.y;
  }

  static bool descendx(const Node& a, const Node& b)
  {
    return a.p.x == b.p.x ? a.p.y < b.p.y : a.p.x < b.p.x;
  }
};


class kdTree
{
  private:
    Node* root;

    Node* divideSpace(int l, int r, bool x_axis, vector<Node>& p)
    {
      if(l >= r)
        return NULL;
      x_axis ? sort(p.begin()+l, p.begin()+r, Node::descendx) : sort(p.begin()+l, p.begin()+r, Node::descendy);

      int m = (l+r)/2;

      Node* node = new Node();
      node->id = p[m].id;
      node->p = p[m].p;
      node->l = divideSpace(l, m, !x_axis, p);
      node->r = divideSpace(m+1, r, !x_axis, p);

      return node;
    }

    void deleteAllNode(Node* pNode)
    {
      if(pNode == NULL)
        return;

      deleteAllNode(pNode->l);
      deleteAllNode(pNode->r);
      delete pNode;
      pNode = NULL;
    }

  public:
    kdTree() : root(new Node()){};
    ~kdTree()
    {
      deleteAllNode(root);
    }
    void make_tree(vector<Node>& p)
    {
      root = divideSpace(0, p.size(), true, p);
    }
    void search_square(const vec2& s, const vec2& e, vector<Node>& res)
    {
      search(s, e, root, true, res);
    }

    void search(const vec2& s, const vec2& e, const Node* pNode, bool x_axis, vector<Node>& res)
    {
      if(pNode == NULL)
        return;

      int x = pNode->p.x;
      int y = pNode->p.y;

      if( (s.x <= x && x <= e.x) &&
          (s.y <= y && y <= e.y)){
        res.push_back(*pNode);

        search(s, e, pNode->l, !x_axis, res);
        search(s, e, pNode->r, !x_axis, res);
        return;
      }

      if(x_axis){
        if(s.x <= x)
          search(s, e, pNode->l, !x_axis, res);
        if(e.x >=  x)
          search(s, e, pNode->r, !x_axis, res);
      }
      else{
        if(s.y <= y)
          search(s, e, pNode->l, !x_axis, res);
        if(e.y >= y)
          search(s, e, pNode->r, !x_axis, res);
      }
    }
};

int main()
{
  int n;
  cin>>n;

  kdTree tree;
  int x, y;
  vector<Node> p(n);
  for(int i = 0; i < n; ++i){
    //cin>>x>>y;
    scanf("%d %d", &x, &y);
    p[i] = Node(i, vec2(x, y));
  }

  tree.make_tree(p);
  int sx, tx;
  int sy, ty;
  cin>>n;
  for(int i = 0; i < n; ++i){
    cin>>sx>>tx>>sy>>ty;
    vector<Node> res;
    tree.search_square(vec2(sx, sy), vec2(tx, ty), res);

    sort(res.begin(), res.end(), Node::descendId);

    for(int j = 0; j < res.size(); ++j)
      printf("%d\n", res[j].id);
    printf("\n");
      //cout<<res[j].id<<endl;
    //cout<<endl;
  }

  return 0;
}
