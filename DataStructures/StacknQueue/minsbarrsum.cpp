#include <iostream>
#include <vector>
#include <climits>

//brute force approch 
//11/2/26
using namespace std;

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            vector<int> sb;
            for (int k = i; k <= j; k++)
            {
                sb.push_back(arr[k]);
            }

            int mn = INT_MAX;
            for (int k = 0; k < sb.size(); k++)
            {
                if (sb[k] < mn)
                {
                    mn = sb[k];
                }
            }

            sum += mn;
        }
    }

    cout << sum;
    return 0;
}
