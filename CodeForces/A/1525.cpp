#include<iostream>
using namespace std;
int gcd(int n1,int n2){
    if(n1==0 || n2==0){
        return 0;
    }
    while(n1 != n2)
    {
        if(n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }
    return n1;
}

int solve(int percent){
    int hcf = gcd(percent,100);

    // 0% means all water
    if(hcf==0){return 1;}
    
    return (100)/hcf;
}
int main(){
    int tests; cin>>tests;
    for(int t=0; t<tests; t++){
        int percent;
        cin >> percent;
        cout << solve(percent) << endl;        
    }
    return 0;
}