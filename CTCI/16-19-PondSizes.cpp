#include<bits/stdc++.h>
using namespace std;
int main(){
	cout << "Input the land size (NxM)\n";
	int n,m; cin >> n >> m;
	vector<vector<int>> map(n,vector<int>(m,0));
	vector<vector<bool>> visited(n,vector<bool>(m,false));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> map[i][j];
			cout << map[i][j] << " ";
		}
		cout<< endl;
	}

	// Flood find
}
