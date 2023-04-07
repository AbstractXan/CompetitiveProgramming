#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int nums;
        cin >> nums;
        vector<int> v;
        int minn = INT_MAX ;
        int maxx = 0;
        int maxxdiff = 0;
        while(nums--){
            int x; cin >> x;
            if(!v.empty())
                maxxdiff = max(maxxdiff, x-v.back());

            v.push_back(x);
            maxx = max(maxx,x); 
            minn = min(minn,x);
            
        }

        maxxdiff = max(maxxdiff, v.back()-v.front());
        
        if(minn==v.front()||maxx==v.back())
            cout << maxx-minn << endl;
        else{ 
            int max1 = maxx-v.front();
            int max2 = v.back()-minn;
            int maxxx = max(max1,max2);
            cout << max(maxxx,maxxdiff) << endl;
        }
    }
    return 0;
}

/**
 *  3 1 5 8 2 --> 8 , 2 
 *  3 1 8 5 2
 */