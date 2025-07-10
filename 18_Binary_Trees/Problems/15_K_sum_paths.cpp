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
        this -> left = NULL;
        this -> right = NULL;
    }
};



Node* buildTree(Node* root) {

    cout << "Enter the data : ";
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1) {
        return NULL;
    }

    cout << endl << "Enter the data for inserting in the left of : " << root -> data << endl;
    root -> left = buildTree(root -> left);

    cout << endl << "Enter the data for inserting in the right of : " << data << endl;
    root -> right = buildTree(root -> right);
    
    return root;
}



// TLE for this 
void solve(Node* root, int k, int &count, vector<int> path) {
    
    // base case
    if (root == NULL) return;

    path.push_back(root -> data);

    // left part
    solve(root -> left, k, count, path);

    // right part
    solve(root -> right, k, count, path);

    // checking for k sum
    int size = path.size();
    int sum = 0;
    for (int i = size-1; i >= 0 ; i--) {
        sum += path[i];
        if (sum == k) {
            count++;
        }
    }

    path.pop_back();
}




int sumK(Node *root, int k) {
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;    
}




int main() {

    Node *root = NULL;

    // creating a binary tree
    // 1 3 2 -1 -1 1 -1 -1 5 -2 -1 -1 -1
    root = buildTree(root);

    int count = sumK(root, 5);

    cout << endl << "The count of the K sum paths for the tree is : " << count << endl;

    return 0;
}