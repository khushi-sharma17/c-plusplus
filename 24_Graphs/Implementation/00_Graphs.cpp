#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// for adjacency list
class graph {
    public :
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        // creating an edge from u to v
        adj[u].push_back(v);

        if (direction == 0) {
            adj[v].push_back(u);
        } 
    }


    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};






// for adjacency matrix
void addEdge(vector<vector<int>> &mat, int i, int j) {
    mat[i][j] = 1;
    mat[j][i] = 1;      // the graph is undirected
}



void displayMatrix(vector<vector<int>> &mat) {
    int V = mat.size();

    for (int i=0 ; i<V ; i++) {
        for (int j=0 ; j<V ; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}





int main() {

    // adj list
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;


    int m;
    cout << "Enter the number of edges : ";
    cin >> m;


    graph g;


    for (int i=0 ; i<m ; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);     // creating an undirected graph
    }


    // printing graph
    g.printAdjList();














    // adj matrix
    
    // creating a graph with 4 vertices and no edges
    // Note that all values are initialized as 0
    int V = 4;
    vector<vector<int>> mat(V, vector<int>(V, 0));

    // Now adding edges one by one
    addEdge(mat, 0, 1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);


    /* Alternatively we can also create using below
       code if we know all edges in advacem

     vector<vector<int>> mat = {{ 0, 1, 0, 0 },
                                { 1, 0, 1, 0 },
                                { 0, 1, 0, 1 },
                                { 0, 0, 1, 0 } }; */


    cout << "Adjacency matrix representation : " << endl;
    displayMatrix(mat);


    return 0;
}