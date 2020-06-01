/**
Input a NxN matrix and flip the elements along the diagonal
**/
#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n; cout << "Enter the size of matrix" << endl; cin >> n;
	int m[n][n];
	for(int i=0;i<n;i++){
		for(int j=0; j<n;j++){
			cin >> m[i][j];
		}
	}

	//Swap against diagonals
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(i!=j){
				int temp = m[i][j];
				m[i][j]=m[j][i];
				m[j][i]=temp;
			}
		}
	}
	// Print matrix
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}
