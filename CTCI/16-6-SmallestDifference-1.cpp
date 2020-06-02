// Approach 1: O(n^2)
#include<bits/stdc++.h>
using namespace std;
void inputarr(vector<int> &a){
	cout << "Input number of elements:" << endl;
	int n; cin >> n;
	for(int i=0; i<n;i++){
		int temp; cin >> temp;
		a.push_back(temp);
	}
}
int main(){
	vector<int> a , b;
	inputarr(a); inputarr(b);
	// cout << a[0] << b[0] << endl;
	int reta, retb;
	int diff = INT_MAX;
	for(int x : a){
		for(int y : b){
			if(x-y >= 0 && x-y<diff){
				diff = x-y;
				reta = x;
				retb = y;
			}
		}
	}
	cout << "(" << reta << "," << retb << ")" << endl;
	return 0;
}
