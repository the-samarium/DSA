#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter your m: ";
    cin>>m;
    if(m>=90){
        cout<<"Grade is O";
    }
    else if(m>=75 && m<90){
         cout<<"Grade is A";
    }
    else if(m>=55 && m<75){
         cout<<"Grade is B";
    }
    else if(m>=45 && m<55){
         cout<<"Grade is C";
    }
    else if(m>=35 && m<45){
         cout<<"Grade is D";
    }
    else if(m<35){
         cout<<"Fail";
    }
    else{
        cout<<"Invalid input!";
    }
   
    return 0;
}