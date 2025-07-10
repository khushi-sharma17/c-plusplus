#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach 1
int kthLargest(vector<int> &arr, int k) {

    vector<int> sumStore;
    int n = arr.size();

    for (int i=0; i<n ; i++) {
        int sum = 0;

        for (int j=i ; j<n ; j++) {
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }

    sort(sumStore.begin(), sumStore.end());

    return sumStore[sumStore.size() - k];
}




// Approach 2
// TC = O(n*2, logk)
// SC = O(k)
int kthLargestSecond(vector<int> &arr, int k) {

    priority_queue<int, vector<int>, greater<int>> min_heap;

    int n = arr.size();

    for (int i=0 ; i<n ; i++) {
        int sum = 0;

        for (int j=i; j<n ; j++) {
            sum += arr[j];

            if (min_heap.size() < k) {
                min_heap.push(sum);
            }

            else {
                if (sum > min_heap.top()) {
                    min_heap.pop();
                    min_heap.push(sum);
                }
            } 
        }
    }

    return min_heap.top();
}





int main() {

    vector<int> arr = {2, 6, 4, 1};
    int k = 3;
    int kthlargestSum = kthLargestSecond(arr, k);
    cout << "The kth largest element is : " << kthlargestSum << endl;

    return 0;
}