#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution{
    stack<string> s;
    public:
    
    // Returns ab<op>
    string clamp(string b, string op, string a){
        return a.append(b.append(op));
    }

    // extract a <op> b from stack when hit ')'
    void collapse(){
        string a , b , op;
        b = s.top(); s.pop();
        op = s.top(); s.pop();
        a = s.top(); s.pop();
        s.pop(); // remove bracket
        string coll = clamp(b,op,a);
        s.push(coll);
    }

    void printRPN(string str){
        for(int i=0;i<str.size();i++){
            if(str[i]==')'){
                collapse();
                continue;
            }
            string c;
            c = str[i];
            s.push(c);
        }

        cout << s.top() << endl;
    }
};
int main(){
    int testcases;
    cin >> testcases;
    for (int i=0; i<testcases; i++){
        string str; 
        cin >> str;
        Solution sol;
        sol.printRPN(str);
    }
}