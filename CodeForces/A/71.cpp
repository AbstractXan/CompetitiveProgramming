#include<iostream>
#include<string>
#include<vector>
using namespace std;
string shorten(string str){
    if(str.size()>10){
            str = str[0] + to_string(str.size()-2) + str[str.size()-1];
    }
    return str;
}
int main(){
    int tests; cin>>tests;
    vector<string> arr;
    for(int t=0; t<tests; t++){
        string s;
        cin >> s;
        arr.push_back(shorten(s));
    }
    for(auto ans: arr){
        cout << ans << endl;
    }
    return 0;
}