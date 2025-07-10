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




void dfs(unordered_map<int, set<int>> adjList, unordered_map<int, bool> &visited, vector<int> &component, int node) {

    component.push_back(node);
    visited[node] = true;

    // recursive call for every connected node
    for (auto i : adjList[node]) {
        if (!visited[i]) {
            dfs(adjList, visited, component, node);
        }
    }
}




vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {

    graph g;

    for (int i=0 ; i < edges.size() ; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        g.addEdge(u, v, 0);
    }

    unordered_map<int, set<int>> adjList = g.adj;

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;


    // for all nodes call dfs if not visited
    for (int i=0 ; i<V ; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(adjList, visited, component, i);
            ans.push_back(component);
        }
    }

}



int main() {    

    

    return 0;
}