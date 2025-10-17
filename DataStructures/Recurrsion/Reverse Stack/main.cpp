// reverse a stack using recurrsion
#include <iostream>
#include <stack>
using namespace std;

void addBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }

    // we have stack in order, 4 3 2 1. We have to reverse this stack to add x at bottom
    stack<int> temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    temp.push(x);
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
}


void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;

    int x = st.top(); // 5
    st.pop();
    reverseStack(st);
    // after this we hav =e the reversed stack, we assume as 4 3 2 1, we just have to add x at bottom of the stack
    addBottom(st, x);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "Initial Stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout<<endl;
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverseStack(st);

    
    cout << "Reversed Stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}