#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int minCost(vector<int>& arr) {

    // creating a min_heap
    priority_queue<int, vector<int>, greater<int>> min_pq;
    
    for (int i=0; i<arr.size() ; i++) {
        min_pq.push(arr[i]);
    }

    int cost = 0;

    while (min_pq.size() > 1) {

        int a = min_pq.top();
        min_pq.pop();

        int b = min_pq.top();
        min_pq.pop();

        int sum = a + b;
        cost += sum;

        min_pq.push(sum);
    }

    return cost;
}



int main() {

    vector<int> arr = {4, 3, 2, 6};

    int minCostOfRopes = minCost(arr);

    cout << "The minimum cost of ropes is : " << minCostOfRopes << endl;

    return 0;
}