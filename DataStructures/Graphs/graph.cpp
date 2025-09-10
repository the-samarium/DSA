#include <iostream>
using namespace std;
#include <vector>
// undirected graph
void buildUndirectedAdjM(int edges[][2], int m, int n, int adjm[100][100]) {
    // initialize matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adjm[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        adjm[x][y] = 1;
        adjm[y][x] = 1;  
    }
}

// directed graph
void buildDirectedAdjM(int edges[][2], int m, int n, int adjm[100][100]) {
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adjm[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        adjm[x][y] = 1;   
    }
}


void printAdjM(int adjm[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjm[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 7; // nodes
    int m = 7; // edges
    int Edges[][2] = {
        {0,3},{0,1},{2,3},{3,4},
        {1,2},{4,5},{4,6},{5,6}
    };

    int adjm[100][100]; // allocate matrix

    cout << "Undirected:\n";
    buildUndirectedAdjM(Edges, m, n, adjm);
    printAdjM(adjm, n);

    cout << "\nDirected:\n";
    buildDirectedAdjM(Edges, m, n, adjm);
    printAdjM(adjm, n);



    //adjacency list using vector
    vector<int> AdjsList[n];
    vector<int>AdjListDir[n];//always equal to no of nodes
    for(int i=0;i<n;i++){
        int a = Edges[i][0];
        int b = Edges[i][1];
        AdjsList[a].push_back(b);
        AdjsList[b].push_back(a); //push double connections for undirected graph
    }
    cout << "Adjacency List (Undirected):\n";
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (int node : AdjsList[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    //Directed graph adjacency list
    for(int i=0;i<n;i++){
        int a = Edges[i][0];
        int b = Edges[i][1];
        AdjListDir[a].push_back(b); //push single connections for undirected graph
    }

    cout << "Adjacency List (Directed):\n";
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (int node : AdjListDir[i]) {
            cout << node << " ";
        }
        cout << endl;
    }



    return 0;
}


//con of adjancency matrix is that it uses unwanted space