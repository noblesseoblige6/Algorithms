#include <bits/stdc++.h>
using namespace std;

struct process
{
  string name;
  int time;
};

void roundRobin(vector<process>& processes, int n, int quantum)
{
  int totalTime = 0, head = 0;
  vector<process> res;

  while(res.size() != n){
    process tmp = processes[head];
    if(tmp.time - quantum <= 0){
      totalTime += tmp.time;
      tmp.time = totalTime;
      res.push_back(tmp); 
    } else{
      totalTime += quantum;
      tmp.time -= quantum;
      processes.push_back(tmp);
    }
    head++;
  }
  for(int i = 0; i < n; i++){  
    cout<<res[i].name<<" "<<res[i].time<<endl;
  }
}

int main()
{
  int c, q;
  string name;
  int time;
  vector<process> inputs, outputs; 
  cin>>c>>q;
  for(int i = 0; i < c; i++){  
    cin>>name>>time;
    process tmp; 
    tmp.name = name; tmp.time = time;
    inputs.push_back(tmp);
  }
  roundRobin(inputs, c, q);
  return 0;
}
