// Approach 2 : Pointers
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
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	int p1=0, p2=0;
	while(p1<a.size() && p2<b.size()){
		if(a[p1]-b[p2]>=0 && a[p1]-b[p2]<diff){
			diff = a[p1]-b[p2];
			reta = a[p1];
			retb = b[p2];
		}

		if(a[p1]<b[p2]){
			p1++;
		} else if(a[p1]==b[p2]){
			break;
		} else {
			p2++;
		}
	}

	cout << "(" << reta << "," << retb << ")" << endl;
	return 0;
}
