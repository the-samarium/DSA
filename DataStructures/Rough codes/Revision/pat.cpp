#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums)
{

    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int ele = nums[i];
        int num = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == ele)
            {
                num++;
            }
        }
        if (num > (n / 2))
        {
            return ele;
        }
    }
};

void moveZeroes(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] != 0)
                {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 5;

    for (int i = 1; i <= n; i++)
    {
        // print spaces
        for (int s = 1; s <= n - i; s++)
        {
            cout << " ";
        }

        // print hashes
        for (int j = 1; j <= i; j++)
        {
            cout << "#";
        }

        cout << endl;
    }
    vector<int> arr = {1, 2, 0, 3, 4, 5, 6, 0, 7, 0, 9, 1, 0, 3};
    // moveZeroes(arr);
    // unordered_map<int, int> map;
    // map.insert
    cout<<majorityElement(arr);
        // set<int> set;
        // for (int i = 0; i < arr.size(); i++)
        // {
        //     set.insert(arr[i]);
        // }
        // for (auto x : set)
        // {
        //     cout << x << " ";
        // }
        // int x = set.size();
        // cout << x;

        return 0;
}
