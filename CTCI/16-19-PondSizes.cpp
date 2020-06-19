/* 	Input an NxM array. 0 for water.
	Find pond sizes. Diagonals considered adjacent. */

#include<bits/stdc++.h>
using namespace std;
int recurFind(vector<vector<int>> map, vector<vector<bool>> &visited, int i, int j){
	if (i>=map.size() || i<0 || j>=map[0].size() || j<0){
		return 0;
	}

	// Valid i,j
	if ( map[i][j]!=0 || visited[i][j]==true){
		visited[i][j]=true;
		return 0;
	}

	int sum=0;
	visited[i][j]=true;
	for(int p=-1; p<=1; p++){
		for(int q=-1; q<=1;q++){
			if(p==0&&q==0){continue;}
			sum+=recurFind(map,visited,i+p,j+q);
		}
	}
	return sum+1;
}
int main(){
	cout << "Input the land size (NxM)\n";
	int n,m; cin >> n >> m;
	vector<vector<int>> map(n,vector<int>(m,0));
	vector<vector<bool>> visited(n,vector<bool>(m,false));

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> map[i][j];
		}
	}

	// Flood find
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int pondsize = recurFind(map,visited,i,j);
			if (pondsize){cout << pondsize << " ";}
		}
	}
	cout << endl;
}
