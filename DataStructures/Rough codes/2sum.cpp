#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int i = 0;
    int j = nums.size() - 1;
      vector<pair<int, int>> result;
    sort(nums.begin(), nums.end());

    while (i < j)
    {
        if (nums[i] == nums[i+1]){
            i++;
        }
        if(nums[j]==nums[j-1]){
            j--;
        }
        int sum=nums[i]+nums[j];
        if(sum==target){
            return {nums[i],nums[j]};
        }
        else{
            if(sum<target){
                i++;
            }
            else{
                j--;
            }
            
        }
    }
    return {};
}

int main()
{
     vector<int> nums = {15, 2, 11, 7};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty())
        cout << "Pair found: " << result[0] << ", " << result[1] << endl;
    else
        cout << "No pair found." << endl;

    return 0;
}