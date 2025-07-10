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





bool isCyclicBFS(unordered_map<int, set<int>> adjList, unordered_map<int, bool> &visited, int node) {

    unordered_map<int, int> parent;
    parent[node] = -1;
    visited[node] = true;

    queue<int> q;
    q.push(node);

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        for (auto neighbour : adjList[frontNode]) {

            if (visited[neighbour] == true && parent[frontNode] != neighbour) {
                return true;
            }

            else if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
    }

    return false;
}




bool isCycle(int V, vector<vector<int>>& edges) {

    graph g;

    for (int i=0 ; i<edges.size() ; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        g.addEdge(u, v, 0);
    }

    unordered_map<int, set<int>> adjList = g.adj;
    unordered_map<int, bool> visited;

    // to handle disconnected components
    for (int i=0 ; i<V ; i++) {
        if (!visited[i]) {
            if (isCyclicBFS(adjList, visited, i)) {
                return true;
            }
        }
    }

    return false;
}




int main() {    

    

    return 0;
}