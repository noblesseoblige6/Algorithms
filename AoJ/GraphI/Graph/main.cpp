#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > make_adjacency(const vector<vector<int> >& mat)
{
	int nRaw = mat.size(), nCol;
	vector<vector<int> > adjacecy(nRaw, vector<int>(nRaw));

	for(int i = 0; i < nRaw; ++i){
		nCol = mat[i].size();
		for(int j = 0; j < nCol; ++j){
			adjacecy[i][mat[i][j]-1] = 1;
		}
	}
	return adjacecy;
}


int main()
{
	int n, nIdx, nAdj, val;

	cin >> n;
	vector<vector<int> > vertices_graph(n, vector<int>());
	vector<vector<int> > adjacecy;

	for(int i = 0 ; i < n; ++i){
		cin >> nIdx >> nAdj;
		vertices_graph[i].resize(nAdj);
		for(int j = 0 ; j < nAdj; ++j){
			cin>>val;
			vertices_graph[i][j] = val;
		}
	}
	
	adjacecy = make_adjacency(vertices_graph);
	
	for(int i = 0 ; i < n; ++i){
		for(int j = 0 ; j < n-1; ++j){
			cout<<adjacecy[i][j]<<" ";
		}

		cout<<adjacecy[i][n-1]<<endl;
	}
	return 0;
}
