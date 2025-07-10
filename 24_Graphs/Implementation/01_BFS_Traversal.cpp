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



// TC = O(V + E)
void bfs(unordered_map<int, set<int>> adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
    
    queue<int> q;
    q.push(node);

    visited[node] = true;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        // storing frontNode into ans
        ans.push_back(frontNode);

        // traversing all neighbours of the front node
        for (auto i : adjList[frontNode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}




vector<int> BFS(int vertex, vector<pair<int, int>> edges) {

    vector<int> ans;
    unordered_map<int, bool> visited;

    graph g;

    for (auto i : edges) {
        pair<int, int> p = i;
        g.addEdge(p.first, p.second, 0); 
    }


    unordered_map<int, set<int>> adjList = g.adj;

    
    // traverse all the components of a graph
    for (int i=0 ; i<vertex ; i++) {
        if(!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}




int main() {    

    

    return 0;
}