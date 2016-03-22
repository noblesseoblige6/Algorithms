#include <bits/stdc++.h>

using namespace std;

void check_board(vector<vector<bool> >& b, const int& r, const int& c)
{
  for(int i = 0; i < 8; ++i){
    b[r][i] = b[i][c] = true;
    int tmp_r = r+i, tmp_c = c+i;
    int tmp_r2 = r-i, tmp_c2 = c-i;

    if(tmp_r < 8 && tmp_c < 8)
      b[tmp_r][tmp_c] = true;
    if(tmp_r2 >= 0 && tmp_c2 >= 0)
      b[tmp_r2][tmp_c2] = true;

    if(tmp_r < 8 && tmp_c2 >= 0)
      b[tmp_r][tmp_c2] = true;
    if(tmp_r2 >= 0 && tmp_c < 8)
      b[tmp_r2][tmp_c] = true;
  }
}

bool find_q_pos(const vector<vector<bool> >& board, vector<int>& q_pos, const int& row)
{
  if(row == 8)
    return true;

  if(q_pos[row] != -1)
    if(find_q_pos(board, q_pos, row+1))
      return true;

  for(int i = 0; i < 8; ++i){
    if(!board[row][i]){
      vector<vector<bool> > tmp_board = board;
      check_board(tmp_board, row, i);

      if(find_q_pos(tmp_board, q_pos, row+1)){
        q_pos[row] = i;
        return true;
      }
    }
  }
  return false;
}

int main()
{
  int n;
  vector<vector<bool> > board(8, vector<bool>(8, false));
  vector<int> q_pos(8, -1);
  cin >> n;
  for(int i = 0; i < n; ++i){
    int r, c;
    cin >> r >> c;
    check_board(board, r, c);
    q_pos[r] = c;
  }

    find_q_pos(board, q_pos, 0);

  for(int i = 0; i < 8; ++i){
    // cout<<i<<" "<<q_pos[i]<<endl;
    for(int j = 0; j < 8; ++j){
      // cout<<board[i][j]<<" ";
      if(q_pos[i] == j)
        cout<<"Q";
      else
        cout<<".";
    }
    cout<<endl;
  }
  return 0;
}
