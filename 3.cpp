#include <iostream>
#include <string>
using namespace std;
int substr(string a , string b){
    for (int i=0; i<a.size(); i++){ // i - a's index

        if(a[i]==b[0]){        
            int j=0; //b's index
            for ( ; j<b.size() ; j++ ){
                if ( a[i+j] == b[j] ){
                    continue;
                } else { break;}
            }
            if (j==b.size()){
                return 1;
            }
        }    
    }
    return 0;
}
int main(){
    // 24 inputs
    for (int tests=0; tests<24;tests++){
        string a,b;
        cin >> a >> b;
        cout << substr(a,b) << endl;       
    }
    return 0;
}