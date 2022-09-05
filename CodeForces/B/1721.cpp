#include<iostream>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n,m,sx,sy,d;
		cin >> n >> m >> sx >> sy >> d;

		if ( min(n-sx,sy-1)<=d && min(sx-1,m-sy) <= d)
			cout << -1 << endl;
		else
			cout << n+m-2 << endl; 
	
	}
	return 0;
}
