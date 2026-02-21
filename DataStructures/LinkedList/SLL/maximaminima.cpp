LEETCODE 2058
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         vector<int> crit;
        
//         ListNode* prev = head;
//         ListNode* curr = head->next;
//         int index = 1;

//         while (curr != nullptr && curr->next != nullptr) {
//             if ((curr->val < prev->val && curr->val < curr->next->val) ||
//                 (curr->val > prev->val && curr->val > curr->next->val)) {
//                 crit.push_back(index);
//                 //critical point maxima or minima
//             }
//             prev = curr;
//             curr = curr->next;
//             index++;
//         }

//         int n = crit.size();
//         if (n < 2) {
//             return {-1, -1};
//         }
//         int minDist = INT_MAX;
//         for (int i = 1; i < n; i++) {
//             minDist = min(minDist, crit[i] - crit[i - 1]);
//             //minimum distance is between adjacent nodes only
//         }

//         int maxDist = crit[n - 1] - crit[0];
//         //maximum distance is between first and last added index of a critical point

//         return {minDist, maxDist};
//     }
// };