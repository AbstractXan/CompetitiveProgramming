#include<bits/stdc++.h>
using namespace std;
int main(){
	cout << "Input array size\n";
	int n; cin >> n;
	cout << "Input subset size\n";
	int m; cin >> m;
	cout << "Input array\n";
	int a[n],subset[m];
	for(int i=0;i<n;i++){cin>>a[i]; cout << a[i] << " ";}
	// 1. Initialize array with first m values
	for(int i=0;i<m;i++){subset[i]=a[i];}
	
	cout << endl;
	srand (time(NULL));
	
	// Shuffle subset
	// 2. Traverse through left over values of a.
	for(int i=m;i<n;i++){
		
		int k=rand()%n; //Choose random index
		if(k<m){
			int temp=subset[i];	//Swap
			subset[i]=a[k];
			a[k]=temp;
			cout << k << endl;
		}
	}

	for(int i=0;i<m;i++){cout << subset[i] << " ";}
	cout << endl;
}
