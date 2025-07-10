#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class graph {
    
    public :
    unordered_map<int, set<int>> adj;

    void addEdge(int u, int v, bool direction) {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        // creating an edge from u to v
        adj[u].insert(v);

        if (direction == 0) {
            adj[v].insert(u);
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



bool isCyclicDFS(unordered_map<int, set<int>> adjList, unordered_map<int, bool> &visited, int node, int parent) {

    visited[node] = true;

    for (auto neighbour : adjList[node]) {

        if (!visited[neighbour]) {
            bool cycleDetected = isCyclicDFS(adjList, visited, neighbour, node);
            if (cycleDetected) return true;
        }

        else if (neighbour != parent) {
            return true;
        }
    }

    return false;
}




bool isCycle(int V, vector<vector<int>>& edges) {

    graph g;

    for (int i=0 ; i < edges.size() ; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        g.addEdge(u, v, 0);
    }

    unordered_map<int, set<int>> &adjList = g.adj;
    unordered_map<int, bool> visited;

    // to handle disconnected components
    for (int i=0 ; i<V ; i++) {
        if (!visited[i]) {
            if (isCyclicDFS(adjList, visited, i, -1)) {
                return true;
            }
        }
    }

    return false;
}



int main() {    

    

    return 0;
}