#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int src, int dest) {

    // creating adjacency list
    unordered_map<int, set<int>> adjList;

    for (int i=0; i<edges.size() ; i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }


    // do BFS
    vector<bool> visited(n);
    vector<int> parent(n);

    queue<int> q;
    q.push(src);

    visited[src] = true;
    parent[src] = -1;

    while (!q.empty()) {
        
        int frontNode = q.front();
        q.pop();

        for (auto neighbour : adjList[frontNode]) {

            if (!visited[neighbour]) {
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
                q.push(neighbour);
            }
        }
    }


    // prepare for the shortest path
    vector<int> ans;

    int currentNode = dest;
    ans.push_back(dest);

    while (currentNode != src) {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    } 
    
    reverse(ans.begin(), ans.end());

    return ans;
}


int main() {



    return 0;
}