#include<iostream>
using namespace std;
#include<vector>
#include<array>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>

#include<algorithm>

void vectors(){
    //vector is a container in cpp stl used when we dont know the size of the container as arrays have fixed size
    //vector is a dynamic array
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << "Vector elements: ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    cout<<v.capacity()<<endl;
    cout<<v.size()<<endl;
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    
}
void arrays(){
    array<int,4> a={1,2,3,4};
    int size=a.size();
    cout<<"Array elements:";
    for(int i=0;i<size;i++){
        cout<<a[i]<<",";
    }
    cout<<endl;
    cout<<"Empty or Not:"<<a.empty()<<endl;
    cout<<"First element: "<<a.front()<<endl;

}
void dequeue(){
    //doubly-ended queue is an array type where we can perform operations on both ends start and end.
    //data is NOT stored at continous memory locations unlike vectors and arrays
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(5);
    d.push_front(2);
    cout<<d.at(2)<<endl;
    // d.pop_back();
    // d.pop_front();
    int size=d.size();
    cout<<"dequeue is: ";
    for(int i=0;i<size;i++){
        cout<<d[i]<<",";
    }
    cout<<endl;
}
void lists(){
    //list is similar to vector , just difference is that the vector does NOT provide the push_front operation
    list<int> ls;
    ls.push_back(10);
    ls.push_front(20);
    int size=ls.size();
    cout<<"List elements are:";
   
    for(int i: ls){
        cout<<i<<",";
    }
    cout<<endl;
}
void Stack(){
    //Works on LIFO concept
    stack<string> s;
    s.push("Sameer");
    s.push("Chavan");
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
}
void Queue(){
    //FIFO Principle
    queue<string> q;
    q.push("Sam");
    q.push("Andy");
    q.push("Tony");
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    q.pop();
}
void Set(){
//elements in set are SORTED and ALWAYS UNIQUE i.e, no duplicate elements
    set<int> s;
    s.insert(5);
    s.insert(3);
    s.insert(27);
    s.insert(3);
    s.insert(5);
    s.insert(33);
    s.insert(9);
    s.insert(1);
    //for eaxh loop
    for(auto i:s){
        cout<<i<<endl;
    }
    cout<<"Is 5 present or not in the set? "<<s.count(5)<<endl;
}
void Maps(){
    map<int,string> m;
    m[1]="Sameer";
    m[2]="VIIT";
    m[3]="ENTC";
    //key=value pair
    m.insert({5,"Aniket"});
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<"Find if 13 present: "<<m.count(13)<<endl;
    cout<<"Find if 3 present: "<<m.count(3)<<endl;
}


int main(){

    // vectors();
    // arrays();
    // dequeue(); 
    // lists();
    // Stack();
    // Queue();
    // Set();
    // Maps();

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    cout<<binary_search(v.begin(),v.end(),5)<<endl;

    array<int,5> arr={5,6,7,8,9};
    cout<<arr.begin()<<arr.end()<<endl;
    bool found=binary_search(arr.begin(),arr.end(),5);
    cout<<found<<endl;
    return 0;
}