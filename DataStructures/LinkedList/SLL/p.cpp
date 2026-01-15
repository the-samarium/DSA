#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespa std;
struct Node
{
    int data;
    Node *next;

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
} void printll(Node *head)
{
    cout << "Linked list: ";
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = new Node(arr[0], nullptr);
    Node *curr = head;
    while (curr != nullptr)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            Node *tmp = new Node(arr[i], nullptr);
            curr->next = tmp;
            curr = curr->next;
        }
    }
    printll(head);
    vector<int> v = {5, 2, 9, 1};
    sort(v.begin(), v.end());

    return 0;
}