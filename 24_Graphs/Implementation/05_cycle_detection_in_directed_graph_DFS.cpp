#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool isCyclicDFS(unordered_map<int, bool> &visited, unordered_map<int, set<int>> adjList, unordered_map<int, bool> &dfsVisited, int node) {

    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adjList[node]) {

        if (!visited[neighbour]) {
            bool cycleDetected = isCyclicDFS(visited, adjList, dfsVisited, neighbour);
            if (cycleDetected) return true;
        }

        // visited[neighbour] && dfsVisited[neighbour] 
        else if (dfsVisited[neighbour]) {
            return true;        // a cycle is found
        }
    }

    dfsVisited[node] = false;       // backtracking
    return false;
}



// O(N + E)
bool isCyclic(int V, vector<vector<int>> &edges) {

    unordered_map<int, set<int>> adjList;

    for (auto &edge : edges) {
        int u = edge[0], v =  edge[1];
        adjList[u].insert(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    // call dfs for all the components
    for (int i=1; i<=V ; i++) {
        if (!visited[i]) {
            bool cycleFound = isCyclicDFS(visited, adjList, dfsVisited, i);
            if (cycleFound) return true;
        }
    }

    return false;
}



int main() {    

    

    return 0;
}