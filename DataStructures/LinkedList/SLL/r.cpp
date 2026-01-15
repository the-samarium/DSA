#include <iostream>
#include<stack>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

void push_front(int data, Node *&head)
{
    // pass by refrence for head to changes take place globaly
    Node *temp = new Node(data, head);
    // got the node to be inserted
    head = temp;
}

void push_back(int data, Node *&tail)
{
    Node *tmp = new Node(data);
    Node *curr = tail;
    curr->next = tmp;
    tail = tmp;
}

void printll(Node *head)
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

void pop_front(Node *&head)
{
    Node *curr = head;
    head = head->next;
    curr->next = NULL;

    delete curr;
}
void pop_back(Node *head, Node *&tail)
{
    Node *curr = head;
    Node *ptr = curr;
    while (curr !=nullptr)
    {
        ptr = curr;
        curr = curr->next;
    }
    //ptr is second last node;
    ptr->next=NULL;
    tail = ptr;
    delete curr;
}

int main()
{
    stack<int> st;
    st.size()
    cout << "Enter length of linked list: ";
    int length;
    cin >> length;

    if (length <= 0)
    {
        cout << "List length must be positive";
        return 0;
    }

    int data;
    cout << "Enter elements:\n";

    // Create head
    cin >> data;
    Node *head = new Node(data);
    Node *curr = head;

    // Create remaining nodes
    for (int i = 1; i < length; i++)
    {
        cin >> data;
        Node *temp = new Node(data);
        curr->next = temp;
        curr = temp;
    }
    Node *tail = curr; // tail node

    // Display linked list
    printll(head);

    // add node at start
    push_front(99, head);
    printll(head);
    push_back(99, tail);
    printll(head);
    pop_front(head);
    printll(head);
    pop_back(head,tail);
    printll(head);
    return 0;
}
// g++ .\r.cpp -o r.exe
// .\r.exe