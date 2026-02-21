#include<iostream>
#include<vector>
using namespace std;
int  main(){
    vector<int> nums={1,1,2,3,3,4,4,8,8};
    // Find the max value to determine the required size
    int max_val = 0;
    for(int x : nums) if(x > max_val) max_val = x;

    // This creates a vector of size (max_val + 1) and sets every element to 0
    vector<int> hash(max_val + 1, 0);
    cout<<"Hello world";
        if (nums.size() == 0) {
            // return -1;
            cout<<-1;
        }
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        for (int i = 0; i < hash.size(); i++) {
            if (hash[i] == 1) {
                // return i;
                cout<<i;
            }
        }
        
        return 0;
    }
