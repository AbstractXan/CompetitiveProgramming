#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int siz, sum;
	cout << "\nEnter the number of elements ";
	cin >> siz; 

	vector<int> arr;
	int prod = 1;
	for(int i=0; i<siz; i++){
		int temp;
		cin >> temp;
		arr.push_back(temp);
		prod *= temp;
	}
	
	for(int i=0; i<siz; i++){
		arr[i]=prod/arr[i];
		cout << arr[i] << " ";
	}
	
	cout << endl;
}
