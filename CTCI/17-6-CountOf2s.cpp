#include<bits/stdc++.h>
using namespace std;

// 2XX X2X XX2 = 3*1*pow(10,2)
// i.e. size*pow(10,size-1)
int permuteTwo(int size){
	if(size==0){return 0;}
	return size*pow(10,size-1);
}

int findTwos(string num){
	int twos=0;
	for(int i=0;i<num.size();i++){
		int digit=num[i]-'0';

		if(digit>2){
			// 3XX -> 1[2X] 2[2X]
			// digit>2 consider 'size' for permutation
			// digit-1 permutations of 2XX
			// +  pow(10,size)
			if(i==num.size()-1){twos+=1;break;}
			twos+= (digit-1)*permuteTwo(num.size()-i-1) + pow(10,num.size()-i);
		} else if(digit==2){
			if(i==num.size()-1){twos+=1;break;}
			// 2XX -> 2X X2 and 200 -> 2XX
			// All subsequent numbers have 2 in prefix
			
			string sub = num.substr(i+1,num.size());
			twos += atoi(sub.c_str())+1;
		} else {
			// 1XX -> 2X X2
			// consider 'size-1' for permutation
			twos+=permuteTwo(num.size()-i-1);
		}
	}
	
	return twos;
}
int main(){
	string num;
	cout << "Enter a number" << endl;
	cin >> num;
	cout << "Number of twos: " << findTwos(num) << endl;
}
