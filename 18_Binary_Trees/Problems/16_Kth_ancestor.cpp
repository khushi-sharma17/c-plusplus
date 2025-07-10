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




Node* solve(Node* root, int &k, int node) {

    // base case
    if (root == NULL) return NULL;

    if (root -> data == node) {
        return root;
    }

    Node* leftAns = solve(root -> left, k, node);
    Node* rightAns = solve(root -> right, k, node);


    if (leftAns != NULL && rightAns == NULL) {
        k--;
        if (k <= 0) {
            k = INT_MAX;    // to lock the answer and always pass the leftAns in the recursive tree above
            return root;
        }
        return leftAns;
    }


    if (leftAns == NULL && rightAns != NULL) {
        k--;
        if (k <= 0) {
            k = INT_MAX;    // to lock the answer and always pass the rightAns in the recursive tree above
            return root;
        }
        return rightAns;
    }

    return NULL;
}



int kthAncestor(Node *root, int k, int node) {
    Node* ans = solve(root, k, node);
    return (!ans || ans -> data == node) ? -1 : ans -> data;
}




int main() {

    Node *root = NULL;

    // creating a binary tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    int kth = kthAncestor(root, 2, 7);

    cout << endl << "The Kth ancestor for the node 7 is : " << kth << endl;

    return 0;
}