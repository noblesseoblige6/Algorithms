#include <bits/stdc++.h>

using namespace std;

const int EXIT = 0;

int main()
{
  stack<int> cars;

  int car_id;
  while(cin>>car_id){
    if(car_id == EXIT){
      cout<<cars.top()<<endl;
      cars.pop();
    }
    else{
      cars.push(car_id);
    }
  }
  return 0;
}
