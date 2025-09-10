//
// Created by SAMEER on 16-06-2025.
//
#include<iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i=0;i<n-1;i++) {
        int min=i;
        for(int j=i+1;j<n;j++){
           if(arr[j]<arr[min]) {
               min = j;
           }

            }
        if (min!=i) {
            swap(arr[min],arr[i]);
        }
        }

    for (int j=0;j<n;j++) {
        cout<<arr[j]<<" ";
    }
}

void bubbleSort(int arr[], int n) {
     for (int i=0;i<n;i++) {
         for (int j=0;j<n;j++) {
             if (arr[j]>arr[j+1]) {
                 swap(arr[j],arr[j+1]);
             }
         }
     }

    for (int j=0;j<n;j++) {
        cout<<arr[j]<<" ";
    }
}

void insertionSort(int arr[], int n) {
    for (int i=0;i<n;i++) {
        int j=i;
        while (j>0,arr[j-1]>arr[j]) {
            swap(arr[j-1],arr[j]);
            j--;
        }

        for (int k=0;k<n;k++) {
            cout<<arr[k]<<" ";
        }
    }

}
void merge(int arr[], int s, int mid, int e) {
    int n1 = mid - s + 1;     // size of left half
    int n2 = e - mid;         // size of right half

    int left[n1], right[n2];

    // Copy data into left and right arrays
    for (int i = 0; i < n1; i++)
        left[i] = arr[s + i];  // from arr[s...mid]
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];  // from arr[mid+1...e]

    // Merge left[] and right[] into arr[]
    int i = 0, j = 0, k = s;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // Copy remaining elements from left[] (if any)
    while (i < n1)
        arr[k++] = left[i++];

    // Copy remaining elements from right[] (if any)
    while (j < n2)
        arr[k++] = right[j++];
}

void mergeSort(int arr[],int s,int e) {

    // base case
    if (s>=e) {
        return;
    }
    int mid=(s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);


}
int main(){
        cout<<"Enter the number of elements you want to enter: ";
        int n;
        cin>>n;
        cout<<"Enter the elements: ";
        int arr[n];
        int length = sizeof(arr) / sizeof(arr[0]);

    // cout<<"Sorted array by selection sort: "<<endl;
    // selectionSort(arr,n);

    cout<<"Sorted array by bubble sort: "<<endl;
    mergeSort(arr,0,length-1);
    for (int j=0;j<length;j++) {
        cin>>arr[j];
    }

    return 0;
}