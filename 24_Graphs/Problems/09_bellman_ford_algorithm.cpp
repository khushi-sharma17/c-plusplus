// bellman ford algorithm

// though there should be no negative cycle in your graph
// but you can use this algo to find out the negative cycle

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
    vector<int> dist(V+1, 1e9);

    dist[src] = 0;

    // n-1 times 
    for (int i=1 ; i<V ; i++) {
        // tarverse on edge list
        for (int j=0 ; j<edges.size() ; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != 1e9 && ((dist[u] + w) < dist[v])) {
                dist[v] = dist[u] + w;
            }
        }
    }


    // checking for negative cycle
    bool flag = false;
    for (int j=0 ; j<edges.size() ; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != 1e9 && ((dist[u] + w) < dist[v])) {
            flag = true;
        }
    }

    if (flag == false) return dist;
    return {-1};
}


int main() {

    int V = 5;
    vector<vector<int>> edges = {{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};
    int src = 0;
    vector<int> result = bellmanFord(V, edges, src);  // Output: [0, 5, 6, 6, 7]

    return 0;
}