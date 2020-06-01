// Time limit:	6s
// Source limit:	50000B
// Memory limit:	1536MB
#include <iostream>
#include <cmath>
#include<vector>
using namespace std;
class Solution{
    vector<vector<long long int>> sol;
    public :
    void printSol(){
        for(auto t = sol.begin(); t!=sol.end();++t){
            for(auto e: *t){
                cout << e << endl;
            }
            cout << endl;
        }
    }
    bool checkPrime(long long int m){
        if(m<=1){return false;}
        if(m==2){return true;}
        long long int s = sqrt(m);
        for(int i=3;i<=s;i+=2){
            if (m%i==0){return false;}
        }
        return true;
    }
    void getPrime(long long int m ,long long int n){
        long long int k=m;
        vector<long long int> v;
        if (m<=2){v.push_back(2);}
        if (m%2==0){k++;}
        for (;k<=n;k+=2){
            if(checkPrime(k)){
                v.push_back(k);
            }
        }
        sol.push_back(v);
    }
};
int main(){
    int testcases;
    cin >> testcases;
    Solution sol;
    for(int i=0;i<testcases;i++){
        long long int m,n;
        cin >> m >> n;
        sol.getPrime(m,n);
    }

    sol.printSol();
    return 0;
}