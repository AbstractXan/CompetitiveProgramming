// Compute year with most people alive
// 15min approx
#include<bits/stdc++.h>
using namespace std;
int main(){
	cout << "Input number of people" << endl;
	int n; cin >> n;

	cout << "Input people's birth and death years" << endl;
	int birth[n] , death[n];

	for(int i=0;i<n;i++){
		cin >> birth[i] >> death[i];
	}

	sort(birth,birth+n);
	sort(death,death+n);

	int b=0,d=0; // Birth and death year indices
	int currPop=0;
	int maxPop=-1;
	int maxYear=birth[0];
	while(b<n){
		currPop++;
		// Catch up death years with birth years
		while(death[d]<birth[b]){
			currPop -= 1;
			d++;
		}
		cout << birth[b] << " " << currPop << endl;
		if(currPop>maxPop){maxPop=currPop;maxYear=birth[b];}
		b++;
	}

	cout << "Max pop in year: " << maxYear << endl;
	/* Printing
	for(int i=0;i<n;i++){
		cout << birth[i] << " " << death[i] << endl;
	}*/
}
