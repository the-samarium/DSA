#include <iostream>
using namespace std;

// checking palindrome number and array
int main()
{
    int num = 1224;
    int rev = 0;
    cout << num << endl;
    while (num > 0)
    {
        int digit = num % 10;
        rev = rev * 10 + digit;
        num = num / 10;
    }
    cout << rev << endl;

    int arr[] = {1, 2, 3, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    int j = n - 1;
    int flag = 0;
    while (i < j)
    {
        if (arr[i] != arr[j])
        {
            cout << "No palindrome array";
            flag += 1;
            break;
        }
        i++;
        j--;
    }
    if (flag == 0)
    {
        cout << "Array is palindrome";
    }
    return 0;
}