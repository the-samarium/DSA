#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node(int data, Node*next){
        this->data=data;
        this->next=next;
    }
}
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

int main(){
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
    cout << "--------------------------" << endl;

    return 0;
}