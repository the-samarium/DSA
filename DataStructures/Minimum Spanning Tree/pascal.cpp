#include<iostream>
using namespace std;
//LAB29 september
int main(){
    int n =5;
    int mat[n][n];
    //matrix initilization
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           mat[i][j]=0;
       }
       cout<<endl;
   }
    for(int i=0;i<n;i++){
        mat[i][0]=1;
        mat[i][i]=1; //fst and lst element always 1
        for(int j=1;j<i;j++){
            mat[i][j]=mat[i-1][j]+mat[i-1][j-1];
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}