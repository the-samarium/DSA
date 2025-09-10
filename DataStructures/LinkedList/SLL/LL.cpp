#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

void printLL(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << ",";
        curr = curr->next;
    }
    cout << endl;
}

void deleteHead(Node *&head)
{
    if (head == nullptr)
        return;
    Node *temp = head;
    Node *prev = nullptr;
    head = head->next;
    delete temp;
}

void insertHead(Node *&head, int x)
{
    Node *temp = new Node(x, nullptr);
    temp->next = head; // temp node pointing to node
    head = temp;
}

void insertTail(Node *head, int y)
{
    Node *temp = new Node(y, nullptr);

    Node *curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = temp;
}

void deleteTail(Node *&head)
{
    if (head == nullptr)
        return;
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *curr = head;
    Node *prev = nullptr;
    while (curr->next != nullptr)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = nullptr;
    delete curr;
}

void deleteKthElement(Node *head, int k)
{
    if (head == nullptr)
        return;
    if (k == 1)
    {

        Node *temp = head;
        Node *prev = nullptr;
        head = head->next;
        delete temp;
    }
    else
    {
        int count = 0;
        Node *temp = head;
        Node *prev = head;
        while (temp != nullptr)
        {
            count += 1;
            if (count == k)
            {
                prev->next = prev->next->next;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
}

void addAtKth(Node *&head, int k, int n)
{
    int count = 0;
    Node *curr = head;
    Node *prev = nullptr;
    Node *temp = new Node(n, nullptr);
    while (count < k)
    {
        prev = curr;
        curr = curr->next;
        count += 1;
    }
    prev->next = temp;
    temp->next = curr;
}

void ClearLL(Node *&head)
{
    Node *curr = head;
    Node *prev = nullptr;
    while (curr->next != nullptr)
    {
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    head = nullptr;
    delete curr;
}

void LengthLL(Node *&head)
{
    int len = 0;
    Node *curr = head;

    while (curr != nullptr)
    {
        len++; 
        curr = curr->next;
    }

    cout << "Length of linked list is: " << len << endl;
}

void searchElement(Node *head, int key)
{

    Node *curr = head;
    int flag = 0;
    while (curr != nullptr)
    { // check until the end of the list
        if (curr->data == key)
        {
            cout << "Element found in LL" << endl;
            flag += 1;
            break;
        }
        curr = curr->next;
    }
    if (flag == 0)
    {

        cout << "Element not found" << endl;
    }
}

void addKelementsatEnd(Node *&head, int num)
{
    cout << "Enter the elements you want to insert at end one after another: " << endl;
    for (int i = 0; i < num; i++)
    {
        int val;
        cin >> val;
        Node *temp = new Node(val, nullptr);

        if (!head)  // empty list
        {
            head = temp;
        }
        else
        {
            Node *curr = head;
            while (curr->next != nullptr)
                curr = curr->next;
            curr->next = temp;
        }
    }
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    Node *head = new Node(arr[0], nullptr);
    Node *curr = head;
    for (int i = 1; i < 5; i++)
    {
        Node *temp = new Node(arr[i], nullptr);
        curr->next = temp;
        curr = temp;
    }

    cout << "Initial list: ";
    printLL(head);
    LengthLL(head);
    cout << "--------------------------" << endl;

    cout << "Opeartion : Adding 5 elements at end of LL ";
    addKelementsatEnd(head,5);
    printLL(head);
    LengthLL(head);
    cout << "--------------------------" << endl;


    // cout << "Operation: Delete Head" << endl;
    // deleteHead(head);
    // printLL(head);
    // LengthLL(head);
    // cout << "--------------------------" << endl;

    // cout << "Operation: Delete Tail" << endl;
    // deleteTail(head);
    // printLL(head);
    // LengthLL(head);
    // cout << "--------------------------" << endl;

    // cout << "Operation: Delete 3rd Element" << endl;
    // deleteKthElement(head, 3);
    // printLL(head);
    // LengthLL(head);
    // cout << "--------------------------" << endl;

    // cout << "Operation: Insert Head (10)" << endl;
    // insertHead(head, 10);
    // printLL(head);
    // LengthLL(head);
    // cout << "--------------------------" << endl;

    // cout << "Operation: Insert Tail (11)" << endl;
    // insertTail(head, 11);
    // printLL(head);
    // LengthLL(head);
    // cout << "--------------------------" << endl;

    // cout << "Operation: Insert at 3rd Position (55)" << endl;
    // addAtKth(head, 3, 55);
    // printLL(head);
    // LengthLL(head);
    // cout << "--------------------------" << endl;

    // cout << "Operation: Find element 3" << endl;
    // searchElement(head, 3);
    // printLL(head);
    // LengthLL(head);
    // cout << "--------------------------" << endl;

    // cout << "Operation: Clear Linked List" << endl;
    // ClearLL(head);
    // printLL(head);
    // LengthLL(head);
    // cout << "--------------------------" << endl;

    return 0;
}
