#include<iostream>
using namespace std;
#include<vector>
#include<queue>
//graph using adj matrix

//graph using adj list
//adj list is list of lists
void Adjl(vector<vector<int>>&Adjl, int Edges[][2],int n,int m){
    //n = no of edges
    for(int i=0;i<m;i++){
        int a = Edges[i][0]; //first no of pair
        int b = Edges[i][1]; //seconf number of pair

        //both number in pair are connected to each other
        Adjl[a].push_back(b);
        Adjl[b].push_back(a);
        //undirexted adj list
    }

    //printing adjanceny list
    cout<<"Adjacency list id a follows:\n";
    for(int i=0;i<n;i++){
        cout<<i<<"-> ";
         for (int node : Adjl[i]) {
            cout << node << " ";
        }
        cout<<endl;
    }
}
void dfs(int start, vector<bool> &visited, vector<vector<int>> &adj) {
    //select start node
    cout<<start<<" ";
    visited[start]=true;
    for(auto itr: adj[start]){
        if(visited[itr]!=true){
            dfs(itr,visited,adj);
        }
    }
}
void BFS(int start, vector<vector<int>> &adj,int nodes,int edgecount, int Edges[][2]){
    vector<bool> visited(nodes,false);
    queue<int> q;
    visited[start]=true;
    q.push(start);
    while(!q.empty()){
        int x = q.front();
        cout<<x<<" ";
        q.pop();

        for(auto nbr : adj[x]){
            if(visited[nbr]!=true){
                //if neighbour is unvisited print
                q.push(nbr);
                visited[nbr]=true;
            }
        }
    }
}

int main(){
    
    int n = 7; // nodes
    int m = 8; 
    vector<bool> visited(n, false);
    int Edges[][2] = {
        {0,3},{0,1},{2,3},{3,4},
        {1,2},{4,5},{4,6},{5,6}
    };
    vector<vector<int>>Adjlst(n);
    Adjl(Adjlst,Edges,n,m);
    cout<<"DFS is:"<<endl;
    dfs(2,visited,Adjlst);
    cout<<endl;
    cout<<"BFS is:"<<endl;
    BFS(2,Adjlst,n,m,Edges);
    return 0;
}