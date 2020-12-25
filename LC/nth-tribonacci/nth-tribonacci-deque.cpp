#include<deque>
class Memo{
    std::deque<int> d;
    public:
    long int dsum;
    Memo(){
        this->d.push_back(0);
        this->d.push_back(1);
        this->d.push_back(1);
        dsum = 2;
    }
    
    void next(){
        int front = this->d.front();
        this->d.push_back(this->dsum);
        this->d.pop_front();
        this->dsum += this->dsum;
        this->dsum -= front;
    }
};

class Solution {
public:
    int tribonacci(int n) {
        Memo m;
        if(n==0){return 0;}
        if(n==1 || n==2){return 1;}
        while(n>3){
            m.next();
            n--;
        }
        return m.dsum;
    }
};