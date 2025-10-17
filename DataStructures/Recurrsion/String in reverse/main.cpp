//print a string in reverse
#include<iostream>
#include<string>
using namespace std;

void revString(string &str, int index){
    if(index>=str.length()){
        return;
    }
    //we know, or assume that revString will reverse the string alraedy and print it;
    revString(str,index+1);
    //we assume from 1 to length, all reversed characters are peinted, so at last print the first character
    cout<<str[index]; //here now index =0
}

int Fibo(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return (Fibo(n-1)+Fibo(n-2));
}


int main(){
    string str="Sameer";
    revString(str,0);
    int x = Fibo(4);
    cout<<x;
    return 0;
}