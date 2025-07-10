// Kahn's Algorithm
// topological sort using BFS

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> topoSort(int V, vector<vector<int>>& edges) {

    // Creating an adjacency list
    unordered_map<int, set<int>> adjList(V);

    for (int i=0 ; i<edges.size() ; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].insert(v);
    }


    // find all indegrees
    vector<int> indegrees(V);

    for (auto i : adjList) {
        for (auto j : i.second) {
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
    vector<int> ans;

    while (!q.empty()) {
        
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        // neighbour indegree update
        for (auto neighbour : adjList[frontNode]) {

            indegrees[neighbour]--;

            if (indegrees[neighbour] == 0) {
                q.push(neighbour);
            }
        }
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