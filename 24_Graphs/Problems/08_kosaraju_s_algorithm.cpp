// to find out the strongly connected components

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// topological sort algo
void dfs(int node, vector<bool> &visited, stack<int> &s, const vector<vector<int>> &adj) {

    visited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour, visited, s, adj);
        }
    }

    s.push(node);
}



void revDfs(int node, vector<bool> &visited, const vector<vector<int>> &transpose) {
    visited[node] = true;

    for (auto neighbour : transpose[node]) {
        if (!visited[neighbour]) {
            revDfs(neighbour, visited, transpose);
        }
    }
}




int kosaraju(vector<vector<int>> &adj) {

    stack<int> s;
    int v = adj.size();
    vector<bool> visited(v, false);

    // Step 1: Fill stack with finish order (topo-like)
    for (int i=0 ; i<v ; i++) {
        if (!visited[i]) {
            dfs(i, visited, s, adj);
        }
    }


    // Step 2: Transpose the graph
    vector<vector<int>> transpose(v);

    for (int i=0 ; i<v ; i++) {
        for (auto neighbour : adj[i]) {
            transpose[neighbour].push_back(i);
        }
    }

    
    
    fill(visited.begin(), visited.end(), false);    // have to refalsify the entire visited array for further logic ahead
    
    // Step 3: DFS on transpose graph in stack order
    int count = 0;
    while (!s.empty()) {
        int top = s.top();
        s.pop();

        if (!visited[top]) {
            revDfs(top, visited, transpose);
            ++count;
        }
    }


    return count;
}


int main() {

    vector<vector<int>> adj = {{2, 3}, {0}, {1}, {4}, {}};
    int result = kosaraju(adj);
    cout << result << endl; // Output: 3

    return 0;
}