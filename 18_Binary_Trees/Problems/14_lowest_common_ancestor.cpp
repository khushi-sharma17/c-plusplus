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



// TC = O(n)
// SC = O(height)
Node* LCA(Node* root, Node* n1, Node* n2) {

    // Base case
    if (root == NULL) return NULL;

    if (root == n1 || root == n2) return root;

    Node* leftAns = LCA(root -> left, n1, n2);
    Node* rightAns = LCA(root -> right, n1, n2);

    if (leftAns != NULL && rightAns != NULL) return root;
    else if (leftAns != NULL && rightAns == NULL) return leftAns;
    else if (leftAns == NULL && rightAns != NULL) return rightAns;
    else return NULL;

}




int main() {

    Node *root = NULL;

    // creating a binary tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    Node* node1 = root -> left -> left;
    Node* node2 = root -> right -> left;
    Node* ansNode = LCA(root, node1, node2);

    cout << endl << "The Lowest Common Ancestor is : " << ansNode -> data << endl;

    return 0;
}