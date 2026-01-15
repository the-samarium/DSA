#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    stack<char> st;
    stack<int> temp; // int stack, not char — to store computed results
    vector<char> tokens = {'2', '1', '+', '3', '*'};

    // Push in reverse so st.top() gives left-to-right order
    for (int i = tokens.size() - 1; i >= 0; i--) {
        st.push(tokens[i]);
    }

    while (!st.empty()) {
        char top = st.top();
        st.pop(); 

        if (top != '+' && top != '-' && top != '*' && top != '/') {
            // It's a digit — convert char to int and push to temp
            temp.push(top - '0');
        } else {
            // It's an operator — pop TWO operands from temp
            int a = temp.top(); temp.pop();
            int b = temp.top(); temp.pop();

            int result = 0;
            if(top == '+') result = a + b;
            else if (top == '-') result = a - b;
            else if (top == '*') result = a * b;
            else                 result = a / b;

            // Push result back to temp for future operations
            temp.push(result);
        }
    }

    cout << "Result: " << temp.top() << endl; // Output: 9
    return 0;
}