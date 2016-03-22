#include <bits/stdc++.h>

using namespace std;

const int nMass = 8;

void check_board(vector<vector<bool> >& b, const int& r, const int& c)
{
  for(int i = 0; i < nMass; ++i){
    b[r][i] = b[i][c] = true;
    int tmp_r = r+i, tmp_c = c+i;
    int tmp_r2 = r-i, tmp_c2 = c-i;

    if(tmp_r < nMass && tmp_c < nMass)
      b[tmp_r][tmp_c] = true;
    if(tmp_r2 >= 0 && tmp_c2 >= 0)
      b[tmp_r2][tmp_c2] = true;

    if(tmp_r < nMass && tmp_c2 >= 0)
      b[tmp_r][tmp_c2] = true;
    if(tmp_r2 >= 0 && tmp_c < nMass)
      b[tmp_r2][tmp_c] = true;
  }
}

bool find_q_pos(const vector<vector<bool> >& board, vector<int>& q_pos, const int& row)
{
  if(row == nMass)
    return true;

  //@coomment there is already queen
  if(q_pos[row] != -1)
    if(find_q_pos(board, q_pos, row+1))
      return true;

  for(int i = 0; i < nMass; ++i){
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
  int r, c;
  vector<vector<bool> > board(nMass, vector<bool>(nMass, false));
  vector<int> q_pos(nMass, -1);

  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> r >> c;
    check_board(board, r, c);
    q_pos[r] = c;
  }

  find_q_pos(board, q_pos, 0);

  for(int i = 0; i < nMass; ++i){
    for(int j = 0; j < nMass; ++j){
      if(q_pos[i] == j)
        cout<<"Q";
      else
        cout<<".";
    }
    cout<<endl;
  }

  return 0;
}
