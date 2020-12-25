class Solution {
public:
    int tribonacci(int n) {
        int arr[n+3]; // +3 in case n=0
        arr[0]=0;
        arr[1]=1;
        arr[2]=1;

        int i=3;
        while(i<=n){
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
            i++;
        }
        return arr[n];
    }
};