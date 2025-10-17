#include <iostream>
#include <vector>
using namespace std;

/*
Quick sort: it is a divide-and -conquer algo
1. elemwnt n-1 is pivot
2. take 2 pointers p at index 0 and q at 0 index. both move rhs
3. if arr[i]<pivot: swap elements at i and p, i++ p++ ; else: only i++ if arr[i];
4. do this while i< n-1;

TC: nlogn or n^2 in worst case 
*/

void quicksort(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivot = arr[end];
    int p = start;

    // i is iteration index, p is partitoon
    for (int i = start; i < end;)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i], arr[p]);
            i++;
            p++;
        }
        else
        {
            i++;
        }
    }
    swap(arr[p], arr[end]); // at lst place pivot in correct position

    // recurrsion
    quicksort(arr, start, p - 1);
    quicksort(arr, p + 1, end);

    // at last we hope that the calls return us the correct results
}

int main()
{
    vector<int> arr = {30, 23, 55, 12, 9, 78, 8, 16, 1, 2}; // unsorted array
    cout << "Unsorted array is :" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    quicksort(arr, 0, arr.size() - 1);
    cout << "Sorted array is :" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}