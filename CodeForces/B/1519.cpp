#include<iostream>
using namespace std;
void solve(){
    int n, m, c;
    cin >> n >> m >> c;
    if(c == min(((n-1)+ n*(m-1)),((m-1)+(n-1)*(m)))){
        cout << "YES";
        return;
    }
    cout << "NO";
}
int main(){
    int t; cin >>  t;
    while(t-- > 0 ){
        solve();
    }
}