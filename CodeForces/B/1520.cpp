#include<iostream>
#include<vector>
using namespace std;
int solution(int num){
    if(num<10){
        return num;
    }
    string s = to_string(num);
    for(int i=0; i<s.size(); i++){ s[i] = s[0]; } //   777 // 2222
    bool inc = to_string(num) < s;
    return (9 * s.size()) - ( '9' - s[0] ) - inc;
}
int main(){
    int tests; cin>>tests;
    vector<int> arr;
    int max;
    for(int t=0; t<tests; t++){
        int i; cin >> i;
        arr.push_back(i);
    }
    for(auto ans: arr){
        cout << solution(ans) << endl;
    }
    return 0;
}