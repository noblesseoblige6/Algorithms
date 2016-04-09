#include<bits/stdc++.h>

using namespace std;

const int kMax = 100000;

int state_cost(const int s[3][3])
{
  int sum_cost = 0;
  for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j)
      if(((i*3+j)+1)%9 != s[i][j] && s[i][j] != 0)
        sum_cost += abs(j-(s[i][j]-1) % 3) + abs(i-(int)(s[i][j]-1) / 3);
  return sum_cost;
}

int swap_piece(const int state[3][3], const int& space_x, const int& space_y, const int& x, const int& y)
{
  int tmp_state[3][3];
  for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j)
      tmp_state[i][j] = state[i][j];

  if(x < 0 && x >= 3 && y < 0 && y >= 3)
    return kMax;

  tmp_state[space_x][space_y] = tmp_state[x][y];
  tmp_state[x][y] = 0;

  return state_cost(tmp_state);
}

void find_min_state(const int state[3][3], int& x, int& y)
{
  int min_cost, tmp_cost;
  int prev_x = x, prev_y = y;

  min_cost = swap_piece(state, prev_x, prev_y, prev_x+1, prev_y);
  x = prev_x+1; y = prev_y;

  tmp_cost = swap_piece(state, prev_x, prev_y, prev_x-1, prev_y);
  if(tmp_cost < min_cost){
    min_cost = tmp_cost;
    x = prev_x-1; y = prev_y;
  }

  tmp_cost = swap_piece(state, prev_x, prev_y, prev_x, prev_y+1);
  if(tmp_cost < min_cost){
    min_cost = tmp_cost;
    x = prev_x; y = prev_y+1;
  }

  tmp_cost = swap_piece(state, prev_x, prev_y, prev_x, prev_y-1);
  if(tmp_cost < min_cost){
    min_cost = tmp_cost;
    x = prev_x; y = prev_y-1;
  }
}

int solve_puzzle(int state[3][3], int& space_x, int& space_y)
{
  int num_solve = 0;
  int prev_x = space_x, prev_y = space_y;

  while(state_cost(state) != 0){
    // cout<<state_cost(state)<<endl;
    find_min_state(state, space_x, space_y);

    state[prev_x][prev_y] = state[space_x][space_y];
    state[space_x][space_y] = 0;
    prev_x = space_x; prev_y = space_y;

    num_solve++;
  }
  return num_solve;
}

int main()
{
  int puzzle[3][3];
  int space_x, space_y;
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      cin >> puzzle[i][j];
      if(puzzle[i][j] == 0){
        space_x = i; space_y = j;
      }
    }
  }

  // cout << state_cost(puzzle) << endl;
  cout << solve_puzzle(puzzle, space_x, space_y) << endl;

  return 0;
}
