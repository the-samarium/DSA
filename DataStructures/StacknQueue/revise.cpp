//
// Created by SAMEER on 20.2.26.
//
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
int main() {
    string s = "(]";
    stack<char> st;
    bool flag = true;
    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i]=='{' || s[i]=='(' || s[i] == '[') {
            //if its opening bracket push it on stack
            st.push(s[i]);
        }
        else {
            //if it closing bracket, compare it with top of stack , if matches to complete opening closing, pop and move
            if ((s[i]=='}' && st.top()=='}') || (s[i]==']' && st.top()=='[') || (s[i]==')' && st.top()=='(')) {
                st.pop();
            }
            else {
                cout<<"Invalid paranthesis"<<endl;
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        cout<<"Valid parenthesis"<<endl;
    }
    return 0;
}