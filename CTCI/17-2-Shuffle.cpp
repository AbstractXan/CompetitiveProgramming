#include<bits/stdc++.h>
using namespace std;
int main(){
	cout << "Input array\n";
	int n; cin >> n;
	int a[n];
	for(int i=0;i<n;i++){ cin>>a[i]; cout << a[i] << " ";}
	cout << endl;
	// Shuffle array
	// 1. Traverse original array
	for(int i=0;i<n;i++){
		int k=rand()%n; //Choose random index
		int temp=a[k];	//Swap
		a[k]=a[i];
		a[i]=temp;
	}

	for(int i=0;i<n;i++){cout << a[i] << " ";}
	cout << endl;
}
