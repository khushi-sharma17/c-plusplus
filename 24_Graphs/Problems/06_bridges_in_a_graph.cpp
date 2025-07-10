// bridge in a garph = a bridge is any graph that is defined as an edge, which when remove, makes the graph disconneceted (or more precisely, increase the connecetd components in a graph)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> adjList, vector<bool> &visited, int &parent, int node, int &timer, vector<int> &low, vector<int> &disc, vector<vector<int>> &result) {

    visited[node] = true;
    disc[node] = low[node] = timer++;

    for (auto neighbour : adjList[node]) {
        if (neighbour == parent) continue;

        if (!visited[neighbour]) {
            dfs(adjList, visited, node, neighbour, timer, low, disc, result);
            low[node] = min(low[node], low[neighbour]);

            // check edge is bridge or not ?
            if (low[neighbour] > disc[node]) {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }

        else {
            // back edge
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}



vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {

    vector<vector<int>> adjList(v);

    for (int i=0 ; i < edges.size() ; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    vector<bool> visited(v, false);


    vector<vector<int>> result;

    // dfs
    for (int i=0 ; i<v ; i++) {
        if (!visited[i]) {
            dfs(adjList, visited, parent, i, timer, low, disc, result);
        }
    }

    return result;
}



int main() {



    return 0;
}