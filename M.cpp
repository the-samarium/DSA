#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

    Node(int data,Node*next){
        this->data=data;
        this->next=next;
    }
};

int main(){
    Node*head=new Node(0,nullptr);
    Node*curr=head;
    for(int i=1;i<5;i++){ // Changed loop condition here
        Node*n=new Node(i,nullptr);
        curr->next=n;
        curr=curr->next;
    }

    curr=head;
    cout<<"Linked List built is as follows: "<<endl;
        while(curr!=nullptr){
            cout << curr->data;
            if(curr->next != nullptr) cout << " -> ";
            curr = curr->next;
        }
        cout << endl;
    return 0;
}