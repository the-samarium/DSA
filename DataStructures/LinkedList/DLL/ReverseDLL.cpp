#include <iostream>
using namespace std;
#include <stack>
class Node
{
public:
    int data;
    Node *next;
    Node *back;
    Node(int data, Node *next, Node *back)
    {
        this->data = data;
        this->next = next;
        this->back = back;
    }
};

void Display(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << ",";
        curr = curr->next;
    }
}

void SwapReverse(Node*& head) {
    Node* curr = head;
    Node* temp = nullptr;

    while (curr != nullptr) {
        // Swap next and back for current node
        temp = curr->next;
        curr->next = curr->back;
        curr->back = temp;
        // Move to the next node (which is back after swap)
        curr = curr->back;
    }

    // After loop, temp will be at the node before null (new head)
    head=temp->back;
}


void Reverse(Node * head){
    stack<int> St;
    Node * temp = head;
    while(temp!=nullptr){
        St.push(temp->data);
        temp=temp->next;
    }
    //now stack contains all data values in reverse oreder from Last in value direction
    temp=head; //again pt temp to head
    while (temp!=nullptr)
    {
        temp->data=St.top();
        St.pop();
        temp=temp->next;
    }
    //TC = O(2n)
    //SC = O(n) due to external stack
}



int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    Node *head = new Node(arr[0], nullptr, nullptr);
    Node *mover = head;
    for (int i = 1; i < 5; i++)
    {

        Node *node = new Node(arr[i], nullptr, nullptr);
        mover->next = node;
        node->back = mover;
        mover = mover->next;
    }
    cout<<"Initial LL is: "<<endl;
    Display(head);
    cout<<"\nReversed LL is: "<<endl;
    SwapReverse(head);
    Display(head);
}