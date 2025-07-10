// Topological sort using DFS
// Topological sort can only be applied on Directed Acyclic Graph.
// It is a linear ordering of vertices such that for every edge u-v, u always appears before v in that ordering.


#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void topologicalSort(vector<vector<int>> adjList, vector<bool> &visited, stack<int> &s, int node) {

    visited[node] = true;

    for (auto neighbour : adjList[node]) {
        if (!visited[neighbour]) {
            topologicalSort(adjList, visited, s, neighbour);
        }
    }

    s.push(node);
}


// TC = O(V + E)
// SC = O(n)
vector<int> topoSort(int V, vector<vector<int>>& edges) {

    // Creating an adjacency list
    vector<vector<int>> adjList(V);

    for (int i=0 ; i<edges.size() ; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }


    vector<bool> visited(V);
    stack<int> s;

    // call DFS topological sort util function for all components
    for (int i=0 ; i<V ; i++) {
        if (!visited[i]) {
            topologicalSort(adjList, visited, s, i);
        }
    }

    vector<int> ans;

    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}




int main() {

    int V = 6;
    vector<vector<int>> edges = {
        {1, 3}, {2, 3}, {4, 1}, {4, 0}, {5, 0}, {5, 2}
    };

    vector<int> result = topoSort(V, edges);

    // Print the result
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;


    return 0;
}