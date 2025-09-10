#include <iostream>
using namespace std;
int main()
{
    // input
    int n;
    
    cout << "Enter size of array: ";
    cin >> n;
    cout << endl;

    int arr[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cout << endl;
    }

    // precomputation
    int hash[13] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] = hash[arr[i]] + 1;
    }

    // result;
    for (int i = 0; i < n; i++)
    {
        cout << hash[i] << endl;
    }
}