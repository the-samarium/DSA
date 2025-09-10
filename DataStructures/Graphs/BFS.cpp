/*
DAA LAB: 8/9/25 Monday
BFS is a graph traversing algorithm. (Bredth First Search)
1. Choose the source node(any node from graph).
2. Print the selected node.
3. Visit all nodes at 1 edge distance from source node, the after all, visit all nodes which are 2 edges away from source node, and so on.
3. Repeat these steps for all UNVISITED nodes.
NOTE: We visit all nodes *only once*
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void ADL(int m, vector<int> Adjl[], int Edges[][2]) {
    //Undirected graph adjacency list
    for(int i = 0; i < m; i++) { // Use m, not n
        int a = Edges[i][0];
        int b = Edges[i][1];
        Adjl[a].push_back(b);
        Adjl[b].push_back(a);
    }

    cout << "Adjacency List:\n";
    for (int i = 0; i < 7; i++) { // For 7 nodes
        cout << i << " -> ";
        for (int node : Adjl[i]) {
            cout << node << " ";
        }
        cout << endl;
    }
}


void BFS(int src,vector<int> AdjList[],int nodes){
    //adjm is a graph
    queue<int> Queue; //creatimg a queue
    bool visited[nodes]={false}; //boolean visited array
    //addig the source node in the queue
    Queue.push(src);
    //changing visited status of src node in array visited;
    visited[src]=true;
    cout<<"BFS: ";
    while(!Queue.empty()){
        //removing the elemnt from the queue
        int rmv = Queue.front();
        Queue.pop();
        cout<<rmv<<" ";
        //add unvisited neighbours of the src node, 
         for (int nbr : AdjList[rmv]) {
            if (visited[nbr]==false) {
                Queue.push(nbr);
                visited[nbr] = true;
            }
        }
    }

}


int main(){
    int n = 7; // nodes
    int m = 8; // edges
    int Edges[][2] = {
        {0,3},{0,1},{2,3},{3,4},
        {1,2},{4,5},{4,6},{5,6}
    };
    vector<int> AdjList[n];
    ADL(m,AdjList,Edges);
    BFS(3,AdjList,n);
    return 0;
}