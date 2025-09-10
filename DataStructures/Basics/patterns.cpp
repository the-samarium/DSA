#include<iostream>
using namespace std;

void pattern1(int n) {
    // Top half of the diamond
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            cout << " ";
        }
        for(int j = 0; j < 2 * i + 1; j++){
            cout << "*";
        }
        for(int j = 0; j < n - i - 1; j++){
            cout << " ";
        }
        cout << endl;
    }

    // Bottom half of the diamond
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        for(int j = 0; j < 2 * (n - i) - 1; j++){
            cout << "*";
        }
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        cout << endl;
    }
}
void pattern2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern3(int n){
    for(int i=0;i<n;i++){
        for(int j=n;j>i;j--){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern4(int n){
    int x=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<x;
            if(x==0){
                x=1;
            }
            else{
                x=0;
            }
        }
         cout<<endl;
    }
}
void pattern5(int n){
    int x=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<x<<" ";
            x++;
        }
        cout<<endl;
    }
}
void pattern6(int n){
    string str="ABCDE";
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<str[j];
        }
        cout<<endl;
    }
}
void pattern7(int n){
     string str="ABCDE";
    for(int i = 0; i < n; i++){
        for(int j = 0; j <=n-i-1; j++){
            cout << str[j];
        }
        cout << endl;
    }
}
void pattern8(int n){
    string str="ABCDEFGH";
    int x=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<str[x];
        }
        x++;
        cout<<endl;
    }
}
void pattern9(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // Print '*' on the border, else space
            if(i == 0 || i == n-1 || j == 0 || j == n-1){
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}
int main() {
    // pattern2(5);
    // pattern3(5);
    pattern9(5);
    return 0;
}
