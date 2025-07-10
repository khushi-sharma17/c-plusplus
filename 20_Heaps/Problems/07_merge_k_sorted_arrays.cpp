#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Node {
    public :
    int data;
    int row;
    int col;

    Node(int data, int row, int col) {
        this -> data = data;
        this -> row = row;
        this -> col = col;
    } 
};


class compare {
    public :
    bool operator() (Node* a, Node* b) {
        return a -> data > b -> data;
    }
};


// TC = O(k logk)
// SC = O(n*k)
vector<int> mergeKArrays(vector<vector<int>> arr, int K) {

    priority_queue<Node*, vector<Node*>, compare> pq;
    
    // step 1 : Enter all the first elements of the arrays
    for (int i=0; i<K ; i++) {
        Node* temp = new Node(arr[i][0], i, 0);
        pq.push(temp);
    }

    vector<int> ans;

    // step 2
    while (pq.size() > 0) {

        Node* temp = pq.top();
        ans.push_back( temp -> data );
        pq.pop();

        int i = temp -> row;
        int j = temp -> col;

        if (j+1 < arr[i].size()) {
            Node* next = new Node(arr[i][j+1], i, j+1);
            pq.push(next);
        } 
    }

    return ans;
}



int main() {

    vector<vector<int>> arr = {{2, 4, 6, 8, 10}, {1, 3, 5, 7, 9}};
    int k = 2;

    vector<int> mergedArray = mergeKArrays(arr, k);

    for (auto i : mergedArray) {
        cout << i << " ";
    }

    return 0;
}