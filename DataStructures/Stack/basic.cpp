#include <iostream>
#include <vector>
#include <stack> //USE THIS FOR DSA AND PROBLEM SOLVING
using namespace std;

class Stack
{
    vector<int> v;

public:
    void PUSH(int x)
    {
        v.push_back(x);
    }

    void POP()
    {
        if (!v.empty())
            v.pop_back();
        else
            cout << "Stack Underflow\n";
    }

    int TOP()
    {
        if (!v.empty())
            return v.back();
        else
        {
            cout << "Stack is empty\n";
            return -1; // sentinel value
        }
    }

    void PrintStack()
    {
        if (v.empty())
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack (vector-based): ";
        for (int x : v)
            cout << x << " ";
        cout << "\n";
    }
};

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

class StackL
{
public:
    void PUSH(int x, Node *&head)
    {
        Node *curr = head;
        Node *tmp = new Node(x, nullptr);
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        // now curr is at last node
        curr->next = tmp;
    }

    void POP(Node *&head)
    {
        if (head == nullptr)
        {
            cout << "Underflow\n";
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            cout << "Stack now empty\n";
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
        cout << "Popped last element\n";
    }

    void TOP(Node *&head)
    {
        if (head == nullptr)
        {
            cout << "Stack is empty\n";
            return;
        }
        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        cout << "Top is " << curr->data << "\n";
    }

    void PrintStack(Node *head)
    {
        if (head == nullptr)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack (LL-based): ";
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }
};


int main()
{
    Stack s1;         // vector-based stack
    StackL s2;        // linked list based stack
    Node *head = nullptr;

    int choice, val;
    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Push (Vector)\n";
        cout << "2. Pop (Vector)\n";
        cout << "3. Top (Vector)\n";
        cout << "4. Print (Vector)\n";
        cout << "5. Push (Linked List)\n";
        cout << "6. Pop (Linked List)\n";
        cout << "7. Top (Linked List)\n";
        cout << "8. Print (Linked List)\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            s1.PUSH(val);
            break;

        case 2:
            s1.POP();
            break;

        case 3:
            cout << "Top (Vector): " << s1.TOP() << "\n";
            break;

        case 4:
            s1.PrintStack();
            break;

        case 5:
            cout << "Enter value: ";
            cin >> val;
            if (head == nullptr)
                head = new Node(val, nullptr);
            else
                s2.PUSH(val, head);
            break;

        case 6:
            s2.POP(head);
            break;

        case 7:
            s2.TOP(head);
            break;

        case 8:
            s2.PrintStack(head);
            break;

        case 9:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 9);

    return 0;
}
