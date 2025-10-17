#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// function to return precedence
int priority(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return 0;
}

// function to convert infix to postfix
string IntoPost(string s) {
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        // operand
        if ((c >= 'A' && c <= 'Z') || 
            (c >= 'a' && c <= 'z') || 
            (c >= '0' && c <= '9')) {
            ans += c;
        }
        // opening bracket
        else if (c == '(') {
            st.push(c);
        }
        // closing bracket
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // remove '('
        }
        // operator
        else {
            while (!st.empty() && priority(c) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // pop remaining operators
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

string InToPre(string s){
    //in prefix, operators are first and numbers next
    
}
int main() {
    string exp = "(A+B)*C-D";
    cout << "Infix:   " << exp << endl;
    cout << "Postfix: " << IntoPost(exp) << endl;
    return 0;
}
