#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > transpose(vector<vector<int> > matrix)
{
  int n = 5;
  vector<vector<int> > res;
  vector<int> tmp;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      tmp.push_back(matrix[j][i]);
    }
    res.push_back(tmp);
    tmp.clear();
  }
  return res;
}

vector<vector<int> > SparseXMat(vector<vector<int> > sparse, vector<vector<int> > mat)
{
  int n = 5;
  vector<vector<int> > res(n, vector<int>(n));
  vector<int> val;
  vector<int> rowPtr, rowIndx;
  int count;
  rowPtr.push_back(1);
  for(int i = 0; i < 12; i++){
    count = 0;
    for(int j = 0; j < 16; j++){
      if(sparse[i][j] != 0){
        val.push_back(sparse[i][j]);
        rowIndx.push_back(j);
        count++;
      }
    }
    rowPtr.push_back(rowPtr[i]+count);
  }
  cout<<"Row pointer"<<endl;
  for(int i = 0; i < rowPtr.size(); i++){
   cout<<rowPtr[i]<<endl;
  }

  cout<<"Row Index"<<endl;
  for(int i = 0; i < rowIndx.size(); i++){
   cout<<rowIndx[i]<<endl;
  }
/*
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      res[i][j] = 0;
      for(int k = rowPtr[i]-1; k < rowPtr[i+1]-1; k++){
        res[i][j] += val[k]*mat[rowIndx[k]][j];
      }
    }
  }
  */
  return res;
}

vector<vector<int> > MatXSparse(vector<vector<int> > sparse, vector<vector<int> > mat)
{
  int n = 5;
  vector<vector<int> > res(n, vector<int>(n));
  vector<int> val;
  vector<int> colPtr, colIndx;
  int count;
  colPtr.push_back(1);
  for(int i = 0; i < 12; i++){
    count = 0;
    for(int j = 0; j < 16; j++){
      if(sparse[j][i] != 0){
        val.push_back(sparse[j][i]);
        colIndx.push_back(j);
        count++;
      }
    }
    colPtr.push_back(colPtr[i]+count);
  }

cout<<"col pointer"<<endl;
  for(int i = 0; i < colPtr.size(); i++){
   cout<<colPtr[i]<<endl;
  }

  cout<<"Col Index"<<endl;
  for(int i = 0; i < colIndx.size(); i++){
   cout<<colIndx[i]<<endl;
  }

/*
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      res[i][j] = 0;
      for(int k = colPtr[j]-1; k < colPtr[j+1]-1; k++){
        res[i][j] += val[k]*mat[i][colIndx[k]];
      }
    }
  }
  */
  return res;
}

int main()
{
  int n = 5;
  vector< vector<int> > A(16, vector<int>(12));
  A[0][0] = 1; A[1][1] = 1; A[2][2] = 1; A[3][3] = 1; 
  A[4][8] = 1; A[5][9] = 1; A[6][7] = 1; A[7][8] = 1; 

  A[8][2] = 1;  A[9][3] = 1;  A[10][4] = 1; A[11][5] = 1; 
  A[12][10] = 1; A[13][11] = 1; A[14][8] = 1; A[15][9] = 1; 
  vector<vector<int> > X(n, vector<int>(n));
  X[0][0] = 6; X[0][1] = 1; X[0][2] = 4; X[0][3] = 1; X[0][4] = 2;
  X[1][0] = 1; X[1][1] = 1; X[1][2] = 1; X[1][3] = 1; X[1][4] = 3;
  X[2][0] = 1; X[2][1] = 1; X[2][2] = 3; X[2][3] = 3; X[2][4] = 3;
  X[3][0] = 1; X[3][1] = 3; X[3][2] = 6; X[3][3] = 8; X[3][4] = 8;
  X[4][0] = 7; X[4][1] = 8; X[4][2] = 2; X[4][3] = 1; X[4][4] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      X[i][j] = 1;
    }
  } 
  vector<vector<int> > At = transpose(A);
  vector<vector<int> > res;
  vector<vector<int> > tmp;

  tmp = SparseXMat(At, X);
  //tmp = MatXSparse(A, tmp);
  /*
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cout<<tmp[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  return 0;
}
