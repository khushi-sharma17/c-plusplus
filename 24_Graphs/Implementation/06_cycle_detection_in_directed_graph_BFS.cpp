// we can use kahn's algorithm to show that a graph is not acyclic as topological sort can only be applied on DAG (Directed Acyclic Graph).

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool isCyclic(int V, vector<vector<int>> &edges) {

    // Creating an adjacency list
    vector<vector<int>> adjList(V);

    for (int i=0 ; i<edges.size() ; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }


    // find all indegrees
    vector<int> indegrees(V);

    for (auto i : adjList) {
        for (auto j : i) {
            indegrees[j]++;
        }
    }

    
    // push 0 indegree ones into the queue
    queue<int> q;
    
    for (int i=0 ; i<V ; i++) {
        if (indegrees[i] == 0) {
            q.push(i);
        }
    }


    // do BFS
    int cnt = 0;

    while (!q.empty()) {

        int frontNode = q.front();
        q.pop();

        cnt++;

        // neighbour indegree update
        for (auto neighbour : adjList[frontNode]) {

            indegrees[neighbour]--;

            if (indegrees[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    // count being equal to the vertices indicates that it is a valid topological sort, which means that there is no cycle in this graph.
    if (cnt == V) return false;
    else return true;
}



int main() {    

    

    return 0;
}