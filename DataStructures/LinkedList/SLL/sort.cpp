#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
}; 

void rev(Node *head)   
{
    stack<int> st;
    Node *temp = head;

    // push data into stack
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    // overwrite data from stack
    temp = head;
    while (!st.empty())
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
}

void printl(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    Node *head = new Node(arr[0], nullptr);
    Node *curr = head;

    for (int i = 1; i < 5; i++)
    {
        curr->next = new Node(arr[i], nullptr);
        curr = curr->next;
    }

    cout << "Initial list: ";
    printl(head);

    cout << "--------------------------" << endl;

    cout << "Reversed list: ";
    rev(head);
    printl(head);

    cout << "--------------------------" << endl;

    return 0;
}
