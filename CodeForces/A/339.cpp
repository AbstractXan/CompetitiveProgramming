#include<iostream>
#include<string>
using namespace std;
int main(){
    char delim = '+';
    string input; cin >> input;
    
    //Count array
    int countArray[3]; 
    countArray[0]=countArray[1]=countArray[2]=0;

    //Count number of instances of 1,2,3 
    for(auto letter: input){
        if(letter==delim)
            continue;
        else 
            countArray[letter-'1']++;
    }

    string output="";
    
    // Generate output for 1,2,3 in that order
    for(auto digitIndex=0; digitIndex<3 ; digitIndex++){
        for(auto j=0; j<countArray[digitIndex]; j++){
            output = output + delim + (char)('1'+digitIndex);
        }
    }

    output.erase(0,1);

    cout << output << endl;
}