//Operations using only add
#include<bits/stdc++.h>
using namespace std;
int d(int a,int b){
	int t=0,q=0;
	while(t<a){
		t+=b;
		q+=1;
	}
	return q;
}
int sub(int a, int b){
	int i=b;
	int diff=0;
	for(;i<=a;i++){
		diff++;
	}
	return diff;
}
int mult(int a,int b){
	for(int i=b;i>0;i--){
		a+=a;
	}
	return a;
}
int main(){
	cout<<"Input a and b: " << endl;
	int a,b;
	cin>> a >> b;
	cout << "a/b=" << d(a,b) << endl;
	cout << "a-b=" << sub(a,b) << endl;
	cout << "a*b=" << mult(a,b) << endl;
	return 0;
}



