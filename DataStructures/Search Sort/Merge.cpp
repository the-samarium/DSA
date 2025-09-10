#include <iostream>
using namespace std;

void merge(int arr[], int p, int mid, int q) {
    int n1 = mid - p + 1;
    int n2 = q - mid;

    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i] = arr[p+i];
    for(int j=0;j<n2;j++) R[j] = arr[mid+1+j];

    int i=0, j=0, k=p;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void Mergesort(int arr[], int p, int q) {
    if(p < q){
        int mid = (p+q)/2;
        Mergesort(arr,p,mid);
        Mergesort(arr,mid+1,q);
        merge(arr,p,mid,q);
    }
}

int main() {
    int arr[] = {5,2,9,1,6,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    Mergesort(arr,0,n-1);

    for(int i=0;i<n;i++) cout << arr[i] << " ";
    return 0;
}
