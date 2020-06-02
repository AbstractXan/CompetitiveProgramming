// Find indices m,n such that array gets sorted when a[m] to a[n] are sorted
// 20 min
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout << "Enter array size and  array\n";
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){cin >> a[i];}

	int left=1, right=n-1, mid;
	// go from LtR
	while(left<=n-1){
		if(a[left-1]<a[left]){left++;}
		else{break;}
	}
	// if parses throughout
	if(left==n){cout << 0 << endl;}

	while(right>0){
		if(a[right]>a[right-1]){right--;}
		else{break;}
	}

	left--; // Reset left position
	right++;
	for(mid=left+1;mid<right;mid++){
		while(a[mid]<a[left] && left>0){
			left--;
		}
		while(a[mid]>a[right] && right<n-1){
			right++;
		}
	}
	// Since unsorted are between left+1 to right-1;
	cout << "m= " <<  left+1 << " | n= " << right-1 << endl;
}
