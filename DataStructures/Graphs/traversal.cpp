#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Build adjacency list
void buildAdjList(vector<vector<int>> &adj, int edges[][2], int edgesCount) {
    for (int i = 0; i < edgesCount; i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        adj[x].push_back(y);
        adj[y].push_back(x); // undirected
    }
}

void BFS(int start,int nodes,int edgecount, int edges[][2],vector<vector<int>>Adjls){
    //take start node, print it, and do this with all adjacent unvisited node
    queue<int> q;
    vector<bool>visited(nodes, false);
    //push on queue
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        //while q is not empty
        int x = q.front();
        cout<<x<<",";
        q.pop();
        for(auto itr : Adjls[x]){
            if(visited[itr]==false){
                visited[itr]=true;
                q.push(itr);
            }
        }
    }
}

void DFS(int start,vector<bool>visited, vector<vector<int>>Adjls){
     //select start node
    cout<<start<<" ";
    visited[start]=true;
    for(auto itr: Adjls[start]){
        if(visited[itr]!=true){
            DFS(itr,visited,Adjls);
        }
    }

}

int main() {
    int nodes = 7;
    int edgesCount = 8;
    int edges[][2] = {
        {0, 3}, {0, 1}, {2, 3}, {3, 4},
        {1, 2}, {4, 5}, {4, 6}, {5, 6}
    };

    vector<vector<int>> adjList(nodes);
    buildAdjList(adjList, edges, edgesCount);

    // --- BFS ---
    int start = 2;
    BFS(start,nodes,edgesCount,edges,adjList);
   

    // --- DFS ---
       vector<bool>visited(nodes, false);
    cout << "DFS: ";
    // dfs(2, visitedDFS, adjList);
    cout << endl;

    //pascals triangle
    int n =5;
    int mat[n][n];
    //matrix initilization
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           mat[i][j]=0;
       }
       cout<<endl;
   } 
   mat[0][0]=1;
   mat[1][0]=1;
   mat[1][1]=1;
   for(int i=2;i<n;i++){
    mat[i][0]=1;
    mat[i][i]=1;
    for(int j=1;j<i;j++){
        mat[i][j]=mat[i-1][j]+mat[i-1][j-1];
    }
   }
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
          cout<<mat[i][j]<<" ";
       }
       cout<<endl;
   } 

    return 0;
}
