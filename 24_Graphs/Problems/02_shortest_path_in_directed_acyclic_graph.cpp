#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class graph {
    public :
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight) {
        // creating an edge from u to v
        pair<int, int> p = make_pair(v, weight);

        adj[u].push_back(p);
    }


    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << " -> ";

            for (auto j : i.second) {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << endl;
        }
    }
};



void topologicalSort(unordered_map<int, list<pair<int, int>>> adj, vector<bool> &visited, stack<int> &s, int node) {

    visited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour.first]) {
            topologicalSort(adj, visited, s, neighbour.first);
        }
    }

    s.push(node);
}



stack<int> topoSort(int V, unordered_map<int, list<pair<int, int>>> &adj) {

    vector<bool> visited(V);
    stack<int> s;

    // call DFS topological sort util function for all components
    for (int i=0 ; i<V ; i++) {
        if (!visited[i]) {
            topologicalSort(adj, visited, s, i);
        }
    }


    return s;
}




int main() {

    // int n;
    // cout << "Enter the number of nodes : ";
    // cin >> n;


    // int m;
    // cout << "Enter the number of edges : ";
    // cin >> m;


    graph g;


    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);


    g.printAdjList();


    int n = 6;

    // making a topological sorted stack
    stack<int> s = topoSort(n, g.adj);


    int src = 1;
    vector<int> distance(n);

    for (int i=0 ; i<n ; i++) {
        distance[i] = INT_MAX;
    }

    distance[src] = 0;

    while (!s.empty()) {
        int top = s.top();
        s.pop();

        if (distance[top] != INT_MAX) {
            for (auto i : g.adj[top]) {
                if ((distance[top] + i.second) < distance[i.first]) {
                    distance[i.first] = distance[top] + i.second;
                }
            }
        }
    }


    cout << "Answer is : " << endl;

    for (auto i : distance) {
        cout << i << " ";
    }
    cout << endl;
    

    return 0;
}