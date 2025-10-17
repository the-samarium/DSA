#include<iostream>
using namespace std;

int Fact(int n){
    if (n <= 1) {
        return 1; // Base case
    }
    int fact = n * Fact(n-1); 
    return fact;
}


int main(){
    int res = Fact(5);
    // The corrected output will be 120
    cout << "5 factorial is: " << res;
    return 0;
}