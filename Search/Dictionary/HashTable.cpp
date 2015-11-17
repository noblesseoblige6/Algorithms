#include <bits/stdc++.h>
using namespace std;

const int M = 1046527;
const int NIL = -1;

class Word
{
  public:
    string str;
    int key;
    Word():str(""), key(NIL){};
    ~Word(){};
    Word(string s, int k):str(s),key(k){};
};

int char2int(char* str)
{
  int sum = 0;
  for(int i = 0; i < strlen(str); i++){
    sum += (int)str[i];
  }
  return sum;
}

int h1(int key){return key % M;}

int h2(int key){return 1+(key % (M-1));}

int h(int key, int i){return (h1(key) + (i*h2(key)))% M;}

void insert(vector<Word>& table, char* str)
{
  int i = 0;
  int key = char2int(str);
  while(true){
  key = h(key, i);
    if(table[key].key == NIL){
      table[key] = Word(str, key);
      break;
    }
    i++;
  }
}

bool find(vector<Word>& table, char* str)
{
  int i = 0;
  int key = char2int(str);
  while(true){
  key = h(key, i);
    if(table[key].str == str){return true;}
    else if(table[key].key == NIL || i >= M){return false;}
    i++;
  }
}

int main(int argc, char* argv[])
{
  int count;
  char inOpe[10], inStr[12];
  vector<Word> table(M);
  cin>>count;
  for(int i = 0; i < count; i++){
    //@comment If use cin, it is too late
    scanf("%s %s", &inOpe, &inStr);
    if(inOpe[0] == 'i'){insert(table, inStr);}
    else{
      if(find(table, inStr)){cout<<"yes"<<endl;}
      else{cout<<"no"<<endl;}
    }
  }
}
