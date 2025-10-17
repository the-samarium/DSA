#include <iostream>
#include <stack>
using namespace std;

// Helper function to insert element in sorted order (descending)
void insertSorted(stack<int> &st, int x) {
    // Base case: stack empty or top smaller than x
    if (st.empty() || st.top() < x) {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    insertSorted(st, x);
    st.push(temp);
}

// Recursive function to sort the stack
void sortStack(stack<int> &st) {
    if (st.empty()) return;
    int x = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, x);
}

int main() {
    stack<int> st;

    int arr[] = {1, 23, 12, 54, 65, 32, 20, 9, 67, 8, 6};
    for (int x : arr)
        st.push(x);

    cout << "Original stack (top to bottom): ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    sortStack(st);

    cout << "Sorted stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
