#include<iostream>
#include<string>
#include<cmath>
typedef long long int ll;
using namespace std;
void addOne(string &s, int p){
    int c=1;
    while(p>=0 && c==1){
        if(s[p]=='9'){
            s[p]='0';
        } else {
            s[p] += c;
            c=0;
        }

        p--;
    }
}
bool checkAllNine(string s){
    string zeroes = "";
    bool set=false;
    for(ll i=0;i<s.size();i++){
        if(set){ zeroes+="0"; }
        if(s[i]!='9'){
            return false;
        }
        set=true;
    }
    cout << "1" << zeroes << "1" << endl;
    return true;
}
void copy(string &s, int l, int r){
    while(l>=0 && r <s.length()){
        s[r++] = s[l--];
    }
}
void tryOverriding(string s , int l , int r, bool even){

    int state=0; // 0 if undecided, 1 if less , 2 if >
    int mid = even ? l : l+1;
    int left = l, right = r;
    while ( l>=0 && r<s.length() ){
        if(state==0){
            // If less; add +1 to mid
            if(s[l]<s[r]){
                state=1;
                addOne(s,mid);
                l=left;r=right; //Reset to override
                continue;
            }
            // if greater, start overriding
            if(s[l]>s[r]){s[r]=s[l];state=2;}
        }else{
            // if state assigned 1 or 2, keep overriding
            s[r]=s[l]; //copying
        }
        l--;r++;
    }

    if(state==0 && l<0){ //if state 0 throughout => palindrome
        addOne(s,mid);
        if(even){
            copy(s,mid,mid+1);
        } else {
            copy(s,mid-1,mid+1);
        }
    }

    cout << s << endl;
}
string cleaned(string s){
    string ret="";
    ll i=0;
    while(s[i]=='0'){
        i++;
    }
    while(i<s.size()){
        ret+=s[i++];
    }
    return ret;
}
int main(){
    ll i,t , l;
    cin >> t;
    string num;
    for(i=0;i<t;i++){
        cin >> num;
        num = cleaned(num);
        l = num.size();
        bool b = checkAllNine(num);
        if(b){continue;}
        bool isEven = fmod(l,2)==0;
        // Even
        if(isEven){ 
            // 1221 9999
            int mid = (l/2)-1; //mid index o indexed
            tryOverriding(num,mid,mid+1,isEven);
        }else{ // Odd
            if(l<1 && num[0]<9){ 
                cout << num[0]+1 << endl;
            }
            int mid = (l/2);
            tryOverriding(num,mid-1,mid+1, isEven);
        } 
    }
}