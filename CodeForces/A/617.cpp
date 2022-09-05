#include<iostream>
using namespace std;
int main(){
	long long int pos; cin >> pos; //Position of elephant
	if(pos%5==0)
		cout << pos/5;
	else
		cout << (pos/5) + 1;
	return 0;	
}
