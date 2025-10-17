// used to calcluate big powers calculations in log(n) time complexity
/*
x^n = (x^n/2)^2 if n is even
    = x * (x^n/2)^2 if n is odd
*/ 
#include<iostream>
using namespace std;

int findPower(int a , int b){
    if(b==0){
        return 1;
    }
    long long half = findPower(a,b/2);
    long long result = half*half;
    if(b%2==1){
        //i.e. power was odd, then we need to multiply result*a
        result*=a;

    }
    return result;
}


int main(){
    int res = findPower(2,20);
    cout<<res<<" ";
    return 0;
}