/*
DAA LAB: 8/9/25 Monday
Graph Traversal: BFS and DFS
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void buildAdjList(int n, int m, int Edges[][2], vector<vector<int>> &Adj) {
    for (int i = 0; i < m; i++) {
        int a = Edges[i][0];
        int b = Edges[i][1];
        Adj[a].push_back(b);
        Adj[b].push_back(a); // undirected graph
    }

    // cout << "Adjacency List:\n";
    // for (int i = 0; i < n; i++) {
    //     cout << i << ": ";
    //     for (int node : Adj[i]) {
    //         cout << node << " ";
    //     }
       
    // }
    // cout<<endl;
}

// BFS
void BFS(int src, vector<vector<int>> &Adj, vector<bool> &visited) {
    queue<int> q;
    q.push(src);
    visited[src] = true;

    cout << "BFS: ";
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int nbr : Adj[v]) {
            if (!visited[nbr]) {
                q.push(nbr);
                visited[nbr] = true;
            }
        }
    }
    cout << endl;
}

// DFS
void DFS(int v, vector<vector<int>> &Adj, vector<bool> &visited) {
    visited[v] = true;
    cout << v << " ";

    for (int nbr : Adj[v]) {
        if (!visited[nbr]) {
            DFS(nbr, Adj, visited);
        }
    }
}

int main() {
    int n = 7; // nodes
    int m = 8; // edges
    int Edges[][2] = {
        {0,3},{0,1},{2,3},{3,4},
        {1,2},{4,5},{4,6},{5,6}
    };

    vector<vector<int>> Adj(n);
    buildAdjList(n, m, Edges, Adj);

    // vector<bool> visitedBFS(n, false);
    // BFS(3, Adj, visitedBFS);

    vector<bool> visitedDFS(n, false);
    cout << "DFS: ";
    DFS(3, Adj, visitedDFS);
    cout << endl;

    return 0;
}
