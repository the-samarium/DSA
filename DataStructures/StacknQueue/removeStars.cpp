//
// Created by SAMEER on 20.2.26.
//
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
    string  s = "erase*****";
    //if star , remove the nearest non-star char from string, along with the start itself
    stack<char> st;
    for (int i = 0;i<s.length();i++) {
        if (s[i]=='*') {
            if (!st.empty()) {
                st.pop();
            }
        }
        else {
            st.push(s[i]);
        }
    }
    string res;
    while (!st.empty()) {
        char x = st.top();
        res.push_back(x);
        st.pop();
    }
    //reverse the string to get final answer
    reverse(res.begin(),res.end());
    cout<<res;
    return 0;
}

/*
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
**Whenever we see a '*', we need to remove the closest character before it.
This is similar to an undo operation, so a stack is a good choice because it follows Last In First Out (LIFO)**

# Approach
<!-- Describe your approach to solving the problem. -->
1. *Traverse the string character by character.*

1. *If the character is not '*', push it into the stack.*

1. *If the character is '*', pop the top element from the stack (if not empty).*

1. *After processing the whole string, the stack contains the final characters.*

1. *Pop all elements from the stack into a string and reverse it to get the correct order.*

 */
