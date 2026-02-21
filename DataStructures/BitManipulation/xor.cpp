#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        
        // Initialize the result vector 'arr' with size 'n'.
        // If we don't do this, accessing arr[i] will cause a segmentation fault.
        vector<int> arr(n);
        
        // The first element is always the same for both arrays
        arr[0] = pref[0];
        
        // Loop starting from the second element (index 1)
        for(int i = 1; i < n; i++) {
            // Apply the Inverse XOR logic to retrieve the original number
            arr[i] = pref[i] ^ pref[i-1];
        }
        
        return arr;
    }
};

// Main function for testing purposes
int main() {
    Solution sol;
    
    // Example test case: pref = [5,2,0,3,1]
    vector<int> pref = {5, 2, 0, 3, 1};
    
    vector<int> result = sol.findArray(pref);
    
    cout << "Original Array: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

/* =================================================================================
                                XOR LOGIC EXPLANATION
 =================================================================================
 
 1. The XOR Property (Self-Inverse):
    The most important property of XOR (^) is that it is its own inverse.
    - If A ^ B = C
    - Then A ^ C = B
    - And  B ^ C = A
    
    Also, remember that X ^ X = 0 (a number XORed with itself cancels out).

 2. The Problem Definition:
    We are given a prefix XOR array 'pref' where:
    pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]

    This means 'pref[i]' represents the cumulative XOR of all elements up to index 'i'.

 3. Deriving the Logic:
    We know that:
    pref[i]   = (arr[0] ^ arr[1] ^ ... ^ arr[i-1]) ^ arr[i]
    
    We also know that:
    pref[i-1] = (arr[0] ^ arr[1] ^ ... ^ arr[i-1])
    
    Therefore, we can rewrite pref[i] as:
    pref[i] = pref[i-1] ^ arr[i]

    To isolate 'arr[i]', we XOR both sides by 'pref[i-1]':
    pref[i] ^ pref[i-1] = pref[i-1] ^ arr[i] ^ pref[i-1]
    
    Since pref[i-1] ^ pref[i-1] becomes 0:
    pref[i] ^ pref[i-1] = 0 ^ arr[i]
    
    Final Formula:
    arr[i] = pref[i] ^ pref[i-1]

 =================================================================================
*/