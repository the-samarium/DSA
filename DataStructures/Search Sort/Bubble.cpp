#include <iostream>
#include <vector>
using namespace std;

void Bubblesort(vector<int>& arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    vector<int> arr={5,1,4,2,8};
    Bubblesort(arr,arr.size());
    for(int x:arr){
     cout<<x<<" ";
    }   
    return 0;
}
