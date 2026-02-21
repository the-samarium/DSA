#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main()
{
    // int prices[] = {7, 1, 5, 3, 6, 4};
    // int profit = INT_MIN;
    // int buy = 0;
    // int sell = 0;
    // for (int i = 0; i < 6; i++)
    // {
    //     for (int j = i + 1; j < 6; j++)
    //     {
    //         // assume we buy on day i and sell on j
    //         int diff = prices[j] - prices[i];
    //         if (diff > profit)
    //         {
    //             profit = diff;
    //             buy = i;
    //             sell = j;
    //         }
    //     }
    // }
    // cout << "bought on " << buy << " sold on " << sell << " profit is " << profit << endl;

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] > target)
        {
            start = mid + 1;
        }
        else if (nums[mid] < target)
        {
            end = mid - 1;
        }
        else if (nums[mid] == target)
        {
            if (nums[mid - 1] == target)
            {
                if (nums[mid + 1] == target)
                {
                    // return {mid, mid + 1};
                    cout << mid << ", " << mid + 1;
                }
                // return {mid - 1, mid};
                cout << mid - 1 << ", " << mid;
            }
            else if (nums[mid + 1] == target)
            {
                // return {mid, mid + 1};
                cout << mid << ", " << mid + 1;
            }
            else
            {
                // return {mid, mid};
                cout << mid << ", " << mid;
            }
        }
        else
        {
            // return {-1, -1};
            cout << -1 << ", " << -2 + 1;
        }
    }
    return 0;
}