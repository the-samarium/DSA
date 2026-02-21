#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *next;
    // Modified constructor to have a default nullptr for convenience
    Node(int data, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

void printLL(Node *head)
{
    Node *curr = head;
    cout << "------------------------------" << endl;
    cout << "List:" << endl;
    while (curr != nullptr)
    {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
    cout << "------------------------------" << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,12,13,14};
    Node *head = new Node(arr[0], nullptr);
    Node *curr = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr);
        curr->next = temp;
        curr = curr->next;
    }

    printLL(head);

    // int target = 3;
    // Node *leftHead = new Node(0, nullptr);
    // Node *lt = leftHead;

    // Node *rightHead = new Node(0, nullptr);
    // Node *pt = rightHead;

    // curr = head;
    // while (curr != nullptr)
    // {
    //     // LeetCode 86: elements < target go left, elements >= target go right
    //     if (curr->data < target)
    //     {
    //         Node *temp = new Node(curr->data, nullptr);
    //         lt->next = temp;
    //         lt = lt->next;
    //     }
    //     else
    //     {
    //         Node *temp = new Node(curr->data, nullptr);
    //         pt->next = temp;
    //         pt = pt->next;
    //     }
    //     curr = curr->next;
    // }

    // // Link the end of the 'less than' list to the start of the 'greater than' list
    // // rightHead is a dummy node, so we point to rightHead->next
    // lt->next = rightHead->next;

    // // The actual start of our result is the node after our left dummy
    // Node *result = leftHead->next;

    // printLL(result);

    curr = head;
    int k = 3;
    int length = 0;
    while (curr != nullptr)
    {
        length++;
        curr = curr->next;
    }
    // now curr has length of ll
    int size = length / k;
    cout << k;
    cout << endl;
    cout << length % k;

    return 0;
}