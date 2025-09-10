#include <iostream>
using namespace std;

void countdigits(int n) {
    int x = 0;  // initialize x to 0
    while (n > 0) {
        n = n / 10;
        x++;
    }
    cout << "No of digits are " << x << endl;
}

void reverse(int n){
    int number=n;
    int out = 0;
    while (n > 0) {
        int x = n % 10;
        out = out * 10 + x;
        n = n / 10;
    }
    cout<<out<<endl;
    if(out==number){
        cout<<"Number is a plaindrome";
    }
}

int main() {
    // countdigits(100);     
    // countdigits(562789); 
    // countdigits(7);  
    reverse(256);  
    reverse(121);   
    return 0;
}
