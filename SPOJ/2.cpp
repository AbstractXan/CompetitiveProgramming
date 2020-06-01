// Time limit:	6s
// Source limit:	50000B
// Memory limit:	1536MB
#include <iostream>
#include <cmath>
using namespace std;
bool checkPrime(long long int m){
    if(m<=1){return false;}
    if(m==2){return true;}
    long long int s = sqrt(m);
    for(int i=3;i<=s;i+=2){
        if (m%i==0){return false;}
    }
    return true;
}
void printPrime(long long int m ,long long int n){
    long long int k=m;
    if (m<=2){cout << 2 << endl;}
    if (m%2==0){k++;}
    for (;k<=n;k+=2){
        if(checkPrime(k)){
            cout << k << endl;
        }
    }
    cout << endl;
}

int main(){
    int testcases;
    cin >> testcases;
    for(int i=0;i<testcases;i++){
        long long int m,n;
        cin >> m >> n;
        printPrime(m,n);
    }
    return 0;
}