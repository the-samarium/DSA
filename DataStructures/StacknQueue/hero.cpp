//
// Created by SAMEER on 18.2.26.
//
#include<iostream>
#include<stack>
using namespace std;

class Que {
    public:
        stack<int> inp;
        stack<int> op;
        void enqueue(int x);
        int dequeue();
        int front();
        bool isEmpty();
};

void Que ::enqueue(int x) {
    inp.push(x);
}

int Que::dequeue() {
    if (op.empty()) {
        if (inp.empty()) {
            cout << "Queue empty" << endl;
            return -1;
        }

        while (!inp.empty()) {
            op.push(inp.top());
            inp.pop();
        }
    }

    int x = op.top();
    op.pop();
    return x;
}


int Que :: front() {
    if (op.empty()) {
        //if op  empty
        if (inp.empty()) {
            cout<<"Queue empty"<<endl;
            return 0;
        }
        while (!inp.empty()) {
            op.push(inp.top());
            inp.pop();
        }
    }

    return op.top();
}
bool Que :: isEmpty() {
    if (op.empty() && inp.empty()) {
        return true;
    }
    return false;
}
int main() {
    cout<<"Implementing queue using stack"<<endl;
    Que q;
    cout<<"Pushing :"<<5<<endl;
    q.enqueue(5);
    cout<<"Pushing :"<<10<<endl;
    q.enqueue(10);
    cout<<"Pushing :"<<15<<endl;
    q.enqueue(15);
    cout<<"Front is :"<<q.front()<<endl;
    cout<<"Popping :"<<q.dequeue()<<endl;
    cout<<"Front is :"<<q.front()<<endl;
    cout<<"Popping :"<<q.dequeue()<<endl;
    cout<<"Front is :"<<q.front()<<endl;
    cout<<"Popping :"<<q.dequeue()<<endl;
    cout<<"Front is :"<<q.front()<<endl;
    cout<<"Popping :"<<q.dequeue()<<endl;

}