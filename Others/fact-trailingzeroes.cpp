#include<bits/stdc++.h>
using namespace std;
int main(){
	cout << "Enter the number" << endl;
	int n;
	cin >> n;
	int fives=0;
	for(;n>=1;n--){
		if(n%5==0)
			fives+=floor(log10(n)/log10(5));
	}
	cout << fives << endl;
	return 0;
}
