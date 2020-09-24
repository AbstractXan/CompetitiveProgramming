#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool findPair(vector<int> arr, int sum){
	
	sort(arr.begin(),arr.end());	
	unsigned int left=0, right=arr.size()-1;
	
	while(left < right){
		int pair_sum = arr[left] + arr[right];
		if ( pair_sum > sum ){
			right--;
		} else if ( pair_sum < sum ){
			left++;
		} else {
			return true;
		}
	}
	return false;
}

int main()
{
	int siz, sum;
	cout << "\nEnter the number of elements ";
	cin >> siz; 
	cout << "\nEnter the sum ";
	cin >> sum;

	vector<int> arr;
	for(int i=0; i<siz; i++){
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	if (findPair(arr,sum)){
		cout << "\nYes";
	} else {
		cout << "\nNo";
	}
}
