/*
Time limit:	5s
Source limit:	50000B
Memory limit:	1536MB
Calculator
*/
#include<iostream>
#include<string>
using namespace std;
//Helper
bool isOp(char c){ return c=='+'||c=='-'||c=='*';}
string genSpaces(int n){ string ret=""; for (int i=0;i<n;i++){ret+=' ';} return ret;}
string genDashes(int n){ string ret=""; for (int i=0;i<n;i++){ret+='-';} return ret;}
int n(char c){return c-'0';} // convert to number
char c(int n){return n+'0';} // convert to charachter
//arithmetic functions
void formatadd(string a, char op , string b, string c){
    int max_length = max(max(a.size(),b.size()+1),c.size());
    cout << genSpaces(max_length-a.size()) << a << endl;
    cout << genSpaces(max_length-b.size()-1) << op << b << endl;
    cout << genDashes(max_length) << endl;
    cout << genSpaces(max_length-c.size()) << c << endl;
}
void add(string a, string b){
    int sum = 0, carry = 0;
    int la = a.size()-1;
    int lb = b.size()-1;
    int lc = max(la,lb);
    string str_sum="";
    int i = 0 ;
    for ( ; i <= min(la,lb); i++ ){
        sum += carry + n(a[la-i]) + n(b[lb-i]);
        carry = sum/10;
        sum %= 10;
        str_sum = c(sum)+str_sum; //append 
        sum = 0; // reset sum
    }
    // if one greater than other, keep adding
    string bigger = (la >= lb)? a : b;
    for ( ; i<=lc ; i++){
        sum += n(bigger[lc-i]) + carry;
        carry = sum/10;
        sum %= 10;
        str_sum = c(sum)+str_sum; //append 
        sum = 0; // reset sum
    }

    if ( carry ){
        str_sum = c(carry)+str_sum;
    }
    formatadd(a,'+',b,str_sum);
}
void sub(string a , string b){
    int diff = 0, carry = 0;
    int la = a.size()-1;
    int lb = b.size()-1;
    int lc = max(la,lb);
    string str_diff="";
    int i = 0 ;
    for ( ; i <= lb; i++ ){
        diff = (-1) * carry + n(a[la-i]) - n(b[lb-i]);
        if (diff<0){ diff+=10; carry=1; } else {carry=0;}
        str_diff = c(diff)+str_diff; //append 
        diff = 0; // reset sum
    }
    for ( ; i<=la ; i++){
        diff = (-1) * carry + n(a[la-i]);
        if (diff<0){ diff+=10; carry=1; } else {carry=0;}
        if (i==la && diff==0){break;}
        str_diff = c(diff)+str_diff; //append 
        diff = 0; // reset sum
    }
    formatadd(a,'-',b,str_diff);
}
void solve(string a, char op, string b){
    switch (op){
        case '+':
            add(a,b); break;
        case '-':
            sub(a,b); break;
        case '*':
            // mult(a,b); 
            break;
    }
}
int main(){
    int testcases;
    cin >> testcases;
    for ( int i = 0 ; i < testcases ; i++){
        string s;
        cin >> s;
        int j = 0;

        string a ="", b="";
        char op;
        for ( ; !isOp(s[j]) ; j++ ){
            a += s[j];
        }
        op=s[j++];
        for ( ; j<s.size() ; j++ ){
            b += s[j];
        }

        // cout << a << " " << op << " " << b << endl;

        solve(a,op,b);
    }
}