#include <iostream>
#include <queue> // for this 
#include <bits/stdc++.h>
using namespace std;


int main() {

    // using priority queue
    cout << "Priority queue : " << endl;
    // max heap
    priority_queue<int> pq;

    pq.push(4);
    pq.push(5);
    pq.push(7);
    pq.push(2);

    cout << "Element at top : " << pq.top() << endl;
    pq.pop();
    cout << "Element at top : " << pq.top() << endl;
    cout << "Size is : " << pq.size() << endl;


    if (pq.empty()) {
        cout << "pq is empty!" << endl;
    } else {
        cout << "pq is not empty!" << endl << endl;
    }



    // min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(4);
    minHeap.push(5);
    minHeap.push(7);
    minHeap.push(2);


    cout << "Element at top : " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Element at top : " << minHeap.top() << endl;
    cout << "Size is : " << minHeap.size() << endl;


    if (minHeap.empty()) {
        cout << "minHeap is empty!" << endl;
    } else {
        cout << "minHeap is not empty!" << endl;
    }

    return 0;
}