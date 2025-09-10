#include<iostream>
using namespace std;
int count=0;
void P1(){
 
    cout<<"Sameer"<<endl;
    count++;
    if(count==5){
        return;
    }
    P1();
}
void P2(int n){
    cout<<count<<endl;
    count++;
    while(count<=n){
        P2(n);
    }
    return;
}
void P3(int n){
    if(n<0){
        return;
    }
    cout<<n<<endl;
    P3(n-1);
}
void P4(int n,int sum){
    if(n<1){
                cout<<sum;
                return;
            }
            P4(n-1,sum+n);
}
void P5(int n, int fact){
    if(n<1){
                cout<<fact;
                return;
            }
            P5(n-1,fact*n);
}
int i=0;
void reverse(int arr[], int n){
        int temp=0;
        if(i>n/2){
            return;
        }
        else{
           swap(arr[i],arr[n-i-1]);
            i=i+1;

            reverse(arr,n);
        }
    }
void reversestr(string s,int i,int n){
    string temp;
     if(i>n/2){
        cout<<s<<endl;
        cout<<temp;
        if(s==temp){
            cout<<"Yes";
        }
        else{
            cout<<"No";
        }
            return;
        }
        else{
            temp[i] = s[i];
            s[i]=s[n-i-1];
            s[n-i-1]=temp[i];

            i=i+1;

            reversestr(s,i+1,n);
        }
}
int main(){
    string str="MADAM"; 
    int len=str.length();
    reversestr(str,0,len);
}