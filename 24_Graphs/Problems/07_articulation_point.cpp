// Articulation point is a node in a graph which when removed will cause the graph to change into disconnected graphs.
// Tarjan's Algorithm

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void dfs(int &node, int parent, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<int> adj[], unordered_set<int> &artPoints, int timer) {

    visited[node] = true;
    disc[node] = low[node] = timer++;

    int child = 0;

    for (int neighbour : adj[node]) {

        if (neighbour == parent) continue;

        if (!visited[neighbour]) {
            dfs(neighbour, node, disc, low, visited, adj, artPoints, timer);
            low[node] = min(low[node], low[neighbour]);

            // check for articulation point or not
            if (low[neighbour] >= disc[node] && parent != -1) {
                artPoints.insert(node);
            }
            child++;
        }

        // back edge
        else {
            low[node] = min(low[node], disc[neighbour]);
        }
    }

    if (parent == -1 && child > 1) {
        artPoints.insert(node);
    }
}




vector<int> articulationPoints(int V, vector<int> adj[]) {
    
    int timer = 0;
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    vector<bool> visited(V, false);
    unordered_set<int> artPoints;


    // dfs
    for (int i=0 ; i<V ; i++) {
        if (!visited[i]) {
            dfs(i, -1, disc, low, visited, adj, artPoints, timer);
        }
    }

    if (artPoints.empty()) return {-1};

    vector<int> result(artPoints.begin(), artPoints.end());
    sort(result.begin(), result.end());

    return result;

}




int main() {



    return 0;
}