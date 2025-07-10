#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int kthSmallest(vector<int> &arr, int k) {

    priority_queue<int> pq;

    int size = arr.size();

    // step 1
    for (int i=0 ; i<k ; i++) {
        pq.push(arr[i]);
    }

    // step 2
    for (int i=k ; i<size ; i++) {
        if (arr[i] < pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // step 3
    int ans = pq.top();
    return ans; 
}



int main() {

    vector<int> arr = {7, 10, 4, 20, 15};
    int k = 4;
    int num = kthSmallest(arr, k);

    cout << "The kth smallest integer is : " << num << endl;

    return 0;
}