#include <iostream>
#include<vector>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
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

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    Node* head = new Node(arr[0],nullptr,nullptr);
    Node* curr = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,nullptr);
        temp->prev = curr;
        curr->next=temp;
        curr=curr->next;
    }
    printLL(head);
    cout<<"Prev node of 5 is "<<endl;
    int x =0;
    curr=head;
    while(x<4){
        curr = curr->next;
        x+=1;
    }
    cout<<curr->prev->data<<endl;
    return 0;
}