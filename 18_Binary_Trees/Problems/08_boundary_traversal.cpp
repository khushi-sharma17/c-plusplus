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



void traverseLeftNodes(Node* root, vector<int> &ans) {

    // base case
    if ((root == NULL) || (root -> left == NULL && root -> right == NULL)) return;

    ans.push_back(root -> data);

    if (root -> left) traverseLeftNodes(root -> left, ans);
    else traverseLeftNodes(root -> right, ans);
    
}



void traverseLeafNodes(Node* root, vector<int> &ans) {
    // base case
    if (root == NULL) return;

    if (root -> left == NULL && root -> right == NULL) {
        ans.push_back(root -> data);
    }

    traverseLeafNodes(root -> left, ans);
    traverseLeafNodes(root -> right, ans);
}




void traverseRightNodes(Node* root, vector<int> &ans) {
    // base case
    if ((root == NULL) || (root -> left == NULL && root -> right == NULL)) return;

    if (root -> right) traverseRightNodes(root -> right, ans);
    else traverseRightNodes(root -> left, ans);

    ans.push_back(root -> data);

}




vector<int> boundaryTraversal(Node *root) {
    
    vector<int> ans;

    // base case
    if(root == NULL) return ans;

    // cout << root -> data << " ";
    ans.push_back(root -> data);

    // traversing the left part
    traverseLeftNodes(root -> left, ans);

    // traversing leaf nodes in the left and the right subtree
    traverseLeafNodes(root -> left, ans);
    traverseLeafNodes(root -> right, ans);

    // traversing the right part
    traverseRightNodes(root -> right, ans);

    return ans;

}




int main() {

    Node *root = NULL;

    // creating a binary tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    vector<int> traversal = boundaryTraversal(root);

    for (int i : traversal) {
        cout << i << " ";
    } cout << endl;

    return 0;
}