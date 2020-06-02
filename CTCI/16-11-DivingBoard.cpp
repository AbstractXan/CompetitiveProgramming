// Planks of small and larger length make a k-planked board
// Generate all possible lengths of boards
// 5min
#include<bits/stdc++.h>
using namespace std; 
int main(){
	int smaller, larger, k;
	cout << "Enter length of smaller and larger planks\n"; cin>> smaller >> larger;
	cout << "Enter number of boards\n"; cin >> k;
	for(int i=0;i<=k;i++){
		cout << (smaller*(k-i) + larger*(i)) << endl;
	}
}
