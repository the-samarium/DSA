#include <iostream>
#include <vector>
using namespace std;

void printGraph(const vector<vector<int>>& adjm, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << adjm[i][j] << " ";
        }
        cout << endl;
    }
}

void Initial(vector<vector<int>>& adjm, int m)
{ // initilizing the matrixx with zeros
    adjm.assign(m, vector<int>(m, 0));
}

int main()
{
    int n = 7; // nodes
    int m = 8; // edges
    int Edges[][3] = {
        {0, 3, 3}, {0, 1, 5}, {2, 3, 7}, {3, 4, 10}, {1, 2, 1}, {4, 5, 2}, {4, 6, 6}, {5, 6, 5}};

    vector<vector<int>> Graph; // graph matrix with n rows n columns

    Initial(Graph, n);
    cout << "Graph Initilization:" << endl;
    printGraph(Graph, n);

    cout << "Undirected Graph using Adj. matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        int x = Edges[i][0];
        int y = Edges[i][1];
        Graph[x][y] = 1;
        Graph[y][x] = 1;
    }
    printGraph(Graph, n);

    Initial(Graph, n); // 0 matrix again

    cout << "Directed Graph using Adj. matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        int x = Edges[i][0];
        int y = Edges[i][1];
        Graph[x][y] = 1;
    }
    printGraph(Graph, n);

    Initial(Graph, n); // 0 matrix again

    cout << "Undirected weighted Graph using Adj. matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        int x = Edges[i][0];
        int y = Edges[i][1];
        int w = Edges[i][2];
        Graph[x][y] = w;
        Graph[y][x] = w;
    }
    printGraph(Graph, n);

    Initial(Graph, n); // 0 matrix again

    cout << "Directed weighted Graph using Adj. matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        int x = Edges[i][0];
        int y = Edges[i][1];
        int w = Edges[i][2];
        Graph[x][y] = w;
    }
    printGraph(Graph, n);



    cout<<"Adjacency List :"<<endl;
    return 0;
}
