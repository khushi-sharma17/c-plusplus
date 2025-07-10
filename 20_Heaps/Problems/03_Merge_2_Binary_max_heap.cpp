// Merge 2 Binary MAX Heap
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Node {
    public :
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this -> data = data;
        this -> left = nullptr;
        this -> right = NULL;
    }
};



Node *buildTree(Node *root) {

    cout << "Enter the data : ";
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1) {
        return NULL;
    }

    // recursively calling itself
    cout << endl << "Enter the data for inserting in the left of : " << root -> data << endl;
    root -> left = buildTree(root -> left);

    cout << endl << "Enter the data for inserting in the right of : " << data << endl;;
    root -> right = buildTree(root -> right);

    return root;
}



// for 0 based indexing
void heapify(vector<int> &arr, int n, int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    }

    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}




vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {

    // step 1 : merge both arrays into one
    vector<int> ans;

    for (auto i : a) {
        ans.push_back(i);
    }

    for (auto i : b) {
        ans.push_back(i);
    }


    // step 2 : build heap using merged array
    int size = ans.size();

    for (int i = size/2 - 1 ; i>=0; i--) {
        heapify(ans, size, i);
    }

    return ans;
}



int main() {

    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {6, 7, 8, 9, 10};

    vector<int> ans = mergeHeaps(a, b, a.size(), b.size());

    cout << "Printing the array now : " << endl;
    for (int i=0 ; i < ans.size() ; i++) {
        cout << ans[i] << " ";
    } cout << endl;

    return 0;
}