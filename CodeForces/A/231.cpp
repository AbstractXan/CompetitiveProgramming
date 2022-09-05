#include<iostream>
using namespace std;
int main(){
	int nProbs; cin >> nProbs;
	int solvable=0;
	for(int i=0;i<nProbs;i++){
		int a,b,c;
		cin >> a >> b >> c;
		if(a+b+c>=2)
			solvable++;
	}
	cout << solvable;
	return 0;
}
