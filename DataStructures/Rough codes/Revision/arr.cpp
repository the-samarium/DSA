#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void reverse(int arr[], int size)
{
    int i = 0;
    int j = size - 1;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

// find unique

void unique(int arr[], int size)
{
    unordered_map<int, int> freq;

    for (int i = 0; i < size; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = 0; i < size; i++)
    {
        if (freq[arr[i]] == 1)
            cout << arr[i] << " ";
    }
    cout << endl;
}

// find duplicate
void duplicate(int arr[], int size)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < size; i++)
    {
        freq[arr[i]]++;
    }
    for (int i = 0; i < size; i++)
    {
        if (freq[arr[i]] > 1)
        {
            cout << arr[i] << " ";
            freq[arr[i]] = 0; // mark as printed
        }
    }
    cout << endl;
}
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void intersect(int arr1[], int size1, int arr2[], int size2)
{
    unordered_map<int, int> freq;
    vector<int> ans;

    for (int i = 0; i < size1; i++)
    {
        freq[arr1[i]]++;
    }

    for (int j = 0; j < size2; j++)
    {
        if (freq[arr2[j]] > 0)
        {
            ans.push_back(arr2[j]);
            freq[arr2[j]]--;
        }
    }

    for (int x : ans)
        cout << x << " ";
    cout << endl;
}

// pair sum
pair<int, int> pairsum(int arr[], int size, int target)
{
    //return the first pair of number whose sum is equal to target
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return {arr[i], arr[j]};
            }
        }
    }
    return {-1, -1};
}
//

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 2, 3, 1, 4, 4, 7, 8, 0, 1, 12};
    int arr2[] = {1, 2, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int target =6;

    // reverse(arr, size);
    // unique(arr, size);
    // duplicate(arr, size);
    // intersect(arr, size, arr2, size2);
    auto p = pairsum(arr, size, target);
    if (p.first != -1)
        cout << p.first << " " << p.second;
    return 0;
}
