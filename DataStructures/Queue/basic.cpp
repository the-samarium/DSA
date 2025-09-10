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


class Queue
{
    public:
    void enqueue(int x, Node* &head){
        //inserting at tail
        Node* n = new Node(x,nullptr);
        Node* curr = head;
        if (head == nullptr) // queue empty
        {
            head = n;
        }
        while(curr->next!=nullptr){
            curr=curr->next;
        }
        curr->next=n;
        cout<<"\nAdded element: "<<n->data;
    }
    void dequeue(Node*&head){
        //removing head node and and making the next node head
        Node* curr = head; 
        if (head == nullptr) // queue empty
        {
            cout<<"\nEmpty Queue";
        }
        head=curr->next;
        cout<<"\nDequeued : "<<curr->data;
        delete curr;
    }
    void front(Node*&head){
        //return value of head
        cout<<"\nFront element is "<<head->data;
    }
    void PrintQ(Node*&head){
        Node* curr = head;
        cout<<"\nPrinting Queue as follows: ";
        while(curr!=nullptr){
            cout<<curr->data<<",";
            curr=curr->next;
        }
    }
};

int main()
{
    //Queue is like a line or a queue of people
    //Works on FIFO principle
    //Operations: enqueue->to rear, dequque->from front, front->gives front element
    //queue can be implemented using a Linked list
    Queue q1;
    Node *head = nullptr;

    int choice, val;
    do
    {
       
        cout << "\n--- Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Print Queue\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter value: ";
            cin >> val;
            if (head == nullptr)
                head = new Node(val, nullptr);
            else
                q1.enqueue(val, head);
            break;

        case 2:
            q1.dequeue(head);
            break;

        case 3:
            q1.front(head);
            break;

        case 4:
            q1.PrintQ(head);
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
