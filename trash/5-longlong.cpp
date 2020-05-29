// Find next smallest palindrome

// Issue : Trailing zeroes
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

typedef long long int ll;

// Helper
ll FindLength(ll k){return ceil(log10(k));}
ll reverse(ll k){
    ll rev=0;
    while(k){ rev = rev*10 + k%10; k/=10; }
    return rev;
}
class Solution{
    ll number;
    public:
    Solution(ll k){number = k;}
    ll nextPrime();
};
ll Solution::nextPrime(){
    //FindLength
    cout << "called" << endl;
    ll length = FindLength(number);
    if(number<9){
        return number+1;
    }else if(number==9 || number==10){
        return 11;
    }

    bool isEvenLength = (fmod(length,2)==0);

    // left length and right length
    ll llen , rlen;
    rlen = length / 2;
    if(!isEvenLength){rlen += 1;}
    llen = length-rlen;

    ll left = number/pow(10,rlen);
    ll rev_left = reverse(left);

    ll mid_right = fmod( number ,pow(10,rlen)); // mid + right
    ll right = (isEvenLength)? mid_right : fmod(mid_right,pow(10,rlen-1));
    ll mid = (mid_right - right) / (pow(10,rlen-1)); // Mid for odd lengths
    ll num=0;

    // cout << left << " " << mid << " " << right << endl;

    if (rev_left > right){
        num = rev_left + left*pow(10,rlen);
        if(!isEvenLength){
            num+= ((mid) * pow(10,rlen-1));
        }
    } else if (rev_left == right){
        // Case 2 : If already a palindrome, find the next
        Solution n(number+1);
        num = n.nextPrime();
    } else {
        // Case 3 : find new
        if(isEvenLength){ 
            // 1234 -> 13 but 1999 -> 2002
            num = reverse(left+1) + (left + 1)*pow(10,rlen);
        } else {
            // 191 -> 201 not palindrom ; 192 -> 202 already a palindrome
            if (mid == 9 && (reverse(left+1)!=right) ){
                    Solution n((mid+1) * pow(10,rlen-1) + left * pow(10,rlen));
                    num = n.nextPrime();
            } else if (mid == 9 && (reverse(left+1)==right) ){ //If adding one gives a palindrome 192 -> 202
                num = right + (mid+1) * pow(10,rlen-1) + left * pow(10,rlen);
            } else { //Mid not 9
                // 131 -> 141 
                num = rev_left + (mid+1) * pow(10,rlen-1) + left * pow(10,rlen); 
            }
        }
        
    }

    return num;
}

vector<pair<ll,ll>> tests;
void runtests(){
    tests.push_back(make_pair(1234123,1234321));
    tests.push_back(make_pair(123123,123321));
    tests.push_back(make_pair(1234321,1235321));
    tests.push_back(make_pair(123321,124421));
    tests.push_back(make_pair(321321,322223));
    tests.push_back(make_pair(191,202));
    tests.push_back(make_pair(192,202));
    tests.push_back(make_pair(192,202));
    tests.push_back(make_pair(131,141));

    for(auto x:tests){
        Solution s(x.first);
        ll next = s.nextPrime();
        if(next==x.second){
            cout << "Correct" << endl;
        } else {
            cout << x.first << " " << x.second << " " << next << endl;

        }
    }
}
int main(){
    int testcases;
    cin >> testcases;
    for ( int i=0; i<testcases ; i++){
        ll number;
        cin >> number;
        Solution s(number);
        cout << s.nextPrime() << endl; 
    }
    // runtests();
}