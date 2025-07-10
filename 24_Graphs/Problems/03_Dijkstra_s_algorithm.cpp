#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

    // creating an adjacency list 
    unordered_map<int, list<pair<int, int>>> adjList;

    for (int i=0 ; i<edges.size() ; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }

    vector<int> distance(V, INT_MAX);

    set<pair<int, int>> st;

    // Initializing distance and set with source node
    distance[src] = 0;
    st.insert(make_pair(0, src));



    while (!st.empty()) {
        // fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // remove top record
        st.erase(st.begin());

        // traverse on neighbours
        for (auto neighbour : adjList[topNode]) {

            if ((nodeDistance + neighbour.second) < distance[neighbour.first]) {

                auto record = st.find(make_pair(distance[neighbour.first], neighbour.first));
                
                // if record found, then erase it
                if (record != st.end()) {
                    st.erase(record);
                }

                // distance update
                distance[neighbour.first] = nodeDistance + neighbour.second;

                // push the record into the set
                st.insert(make_pair(distance[neighbour.first], neighbour.first));
            }
        }
    }

    return distance;
}



int main() {



    return 0;
}