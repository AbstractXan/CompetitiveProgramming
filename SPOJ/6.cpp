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
string genChar(char c,int n){ string ret=""; for (int i=0;i<n;i++){ret+=c;} return ret;}
int n(char c){return c-'0';} // convert to number
char c(int n){return n+'0';} // convert to charachter
//arithmetic functions
void formatadd(string a, char op , string b, string c){
    int max_length = max(max(a.size(),b.size()+1),c.size());
    cout << genChar(' ',max_length-a.size()) << a << endl;
    cout << genChar(' ',max_length-b.size()-1) << op << b << endl;
    cout << genChar(' ',max_length-max(c.size(),b.size()+1))<<genChar('-',max(c.size(),b.size()+1)) << endl;
    cout << genChar(' ',max_length-c.size()) << c << endl;
}
string add(string a, string b){
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
    return str_sum;
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

    string newret = "";
    int j=0;
    for(;j<str_diff.size();j++){if(str_diff[j]!='0'){break;}}
    for(;j<str_diff.size();j++){newret+=str_diff[j];}
    formatadd(a,'-',b,newret);
}
string mult(string a , char b){
    if (b=='0'){return "0";}
    int la = a.size()-1;
    int carry=0, prod;
    int b_int = n(b);
    string ret="";
    for ( int i=0; i<=la ; i++ ){
        prod=n(a[la-i])*(b_int)+carry;
        ret = c(prod%10) + ret;
        carry=prod/10;
    }
    
    if(carry){ret = c(carry)+ret;}
    return ret;
}
void mult(string a , string b){
    long unsigned int la=a.size()-1, lb=b.size()-1,lc;
    string answer="0";
    string prods[lb+1];
    lc = max(la+1,lb+2);
    for(long unsigned int i=0;i<=lb;i++){
        string unit_prod = mult(a,b[lb-i]);
        prods[i] = unit_prod;
        lc = max(lc,unit_prod.size() + i); // update max
        answer = add(unit_prod+genChar('0',i),answer);
    }

    // Format
    cout << genChar(' ',lc-a.size()) << a << endl;
    cout << genChar(' ',lc-b.size()-1) << '*' << b << endl;
    long unsigned int first_dash_len = max(la+1,max(lb+2,prods[0].size()));
    cout << genChar(' ',lc-first_dash_len)<<genChar('-',first_dash_len) << endl;
    for (long unsigned int i=0;i<=lb;i++){
        string prod = prods[i];
        cout << genChar(' ',lc-prod.size()-i) << prod << genChar(' ',i) << endl;
    } 
    if (lb>0){
        cout << genChar(' ',lc-max(lb+1,answer.size())) << genChar('-',max(lb+1,answer.size())) << endl;
        cout << genChar(' ',lc-answer.size())<<answer << endl;
    }
}
void solve(string a, char op, string b){
    switch (op){
        case '+':
            formatadd(a,'+',b,add(a,b)); break;
        case '-':
            sub(a,b); break;
        case '*':
            mult(a,b); break;
    }
    cout << endl;
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