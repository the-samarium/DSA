#include <iostream>
#include <vector>
using namespace std;

void rearrangeArray(vector<int> &nums)
{
    bool flag = true; // true = expect Positive, false = expect Negative
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {

        if (flag == true)
        {
            if (nums[i] < 0)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (nums[j] >= 0)
                    {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
        else
        {
            if (nums[i] >= 0)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (nums[j] < 0)
                    {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
        // Toggle the flag
        flag = !flag;
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    // TC:O n^2 and SC: O(1)
}

void rearrangeOncomp(vector<int> &nums)
{
    vector<int> pos;
    vector<int> neg;
    int n = nums.size();

    // Separate into two lists
    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= 0)
        {
            pos.push_back(nums[i]);
        }
        else
        {
            neg.push_back(nums[i]);
        }
    }

    int p = 0;
    int k = 0;
    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        if (flag == true)
        {
            nums[i] = pos[p];
            p++;
        }
        else
        {
            nums[i] = neg[k];
            k++;
        }

        flag = !flag;
    }

    // Print result
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> array = {1, 2, -3, 4, -5, -6};
    rearrangeArray(array);
    rearrangeOncomp(array);
    return 0;
}