#include<iostream>
int main(){
    int n; std::cin >> n; 
    if(n>=4 && n%2==0){
        std::cout << "YES";
        return 0;
    }
    std::cout << "NO";
}