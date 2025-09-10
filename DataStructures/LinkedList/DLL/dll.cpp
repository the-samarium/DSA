#include <iostream>
using namespace std;

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
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *temp = head;
    head = head->next;
    head->back = nullptr;
    delete temp;
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
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    Node *tmp = curr;
    curr = curr->back;
    curr->next = nullptr;
    delete tmp;
}


void deleteKthelement(Node* head,int k){
    if (head == nullptr || k <= 0) return;

    Node*temp=head;
    int count=1;
    while(count<k){
        temp=temp->next;
        count+=1;
    }
    //now we are at the element to be deleted
    Node*prev=temp->back;
    prev->next=temp->next;

    Node*further=temp->next;
    further->back=temp->back;

    delete temp;
}

void addKthIndexelement(Node*& head, int index, int element) {
    if (index <= 0) return;

    Node* add = new Node(element, nullptr, nullptr);

    // Insert at head
    if (index == 1) {
        add->next = head;
        if (head != nullptr) head->back = add;
        head = add;
        return;
    }

    Node* curr = head;
    int count = 1;

    while (count < index - 1 && curr != nullptr) {
        curr = curr->next;
        count++;
    }

    if (curr == nullptr) {
        delete add; // index > length+1
        return;
    }

    add->next = curr->next;
    add->back = curr;
    if (curr->next != nullptr) curr->next->back = add;
    curr->next = add;
}

void addbforehead(Node* &head,int element){
    Node* curr=head;
    Node* temp=new Node(element,nullptr,nullptr);
    curr->back=temp;
    temp->next=curr;
    head=temp;
}

void addafterhead(Node* head, int x){

     if (head==nullptr) return; // if head is null, do nothing
    Node* add = new Node(x,nullptr,nullptr);
    add->next=head->next;
    if (head->next != nullptr) {  
        head->next->back = add;
    }
    head->next=add;
    add->back=head;
}


int main()
{
    cout << "Doubly LL"<<endl;
    int arr[] = {0,1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = new Node(arr[0], nullptr, nullptr);
    Node *mover = head;
    for (int i = 1; i < 10; i++)
    {
        Node *temp = new Node(arr[i], nullptr, mover); // set back pointer to current node
        mover->next = temp;
        mover = temp;
    }
    cout << "Initial Doubly LL:" << endl;
    printLL(head);

    cout << "After deleting head" << endl;
    deleteHead(head);
    printLL(head);

    cout << "After deleting tail" << endl;
    deleteTail(head);
    printLL(head);

    cout << "After deleting 4th element" << endl;
    deleteKthelement(head,4);
    printLL(head);

    cout<<"After adding element 100 at index 3"<< endl;
    addKthIndexelement(head,3,100);
    printLL(head);

    cout<<"After adding element 99 before head"<< endl;
    addbforehead(head,99);;
    printLL(head);

    cout<<"After adding element 56 after head"<< endl;
    addafterhead(head,56);;
    printLL(head);
    return 0;
}