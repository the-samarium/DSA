#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data, Node *next) : data(data), next(next) {}
};

void printLL(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << (curr->next ? " -> " : "");
        curr = curr->next;
    }
    cout << endl;
}

void llloop(Node *head)
{
    unordered_map<Node*, bool> mp;
    Node *curr = head;

    while (curr != nullptr)
    {
        if (mp[curr]) {
            cout << "Loop detected" << endl;
            return;
        }
        mp[curr] = true;
        curr = curr->next;
    }

    cout << "No loop detected" << endl;
}


int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    if (arr.empty())
        return 0;

    // 1. Build the list
    Node *head = new Node(arr[0], nullptr);
    Node *curr = head;
    for (size_t i = 1; i < arr.size(); i++)
    {
        curr->next = new Node(arr[i], nullptr);
        curr = curr->next;
    }

    cout << "Initial list: ";
    printLL(head);

    ////////////////////////////////////////////////////////
    vector<int> arr2 = {1, 2, 3, 4, 5};

    Node *head2 = new Node(arr2[0], nullptr);
    Node *curr2 = head2;
    Node *save = nullptr; // must be outside

    for (size_t i = 1; i < arr2.size(); i++)
    {
        curr2->next = new Node(arr2[i], nullptr);
        curr2 = curr2->next;

        if (i == 3)
        {                 // value = 4
            save = curr2; // save node 4
        }
    }

    curr2->next = save; // create cycle

   
//////////////////////////////////////////////////////////////

    // 2. Odd-Even Reordering Logic
    if (head != nullptr && head->next != nullptr)
    {
        Node *odd = head;
        Node *even = head->next;
        Node *evenHead = even; // Save the start of the even list

        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next; // Link odd to next odd
            odd = odd->next;        // Move odd pointer

            even->next = odd->next; // Link even to next even
            even = even->next;      // Move even pointer
        }
        odd->next = evenHead; // Connect the end of Odd list to Head of Even list
    }

    cout << "Reordered list: ";
    printLL(head);
    llloop(head);
    llloop(head2);
    return 0;
}