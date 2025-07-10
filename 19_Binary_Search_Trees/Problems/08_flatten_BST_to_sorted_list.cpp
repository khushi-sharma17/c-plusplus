#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Node {
public : 
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};


// TC of insertion = O(logn)
Node* insertIntoBST(Node* &root, int data) {

    // base case
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data > root -> data) {
        // insertion in the right part
        root -> right = insertIntoBST(root -> right, data);
    } else {
        root -> left = insertIntoBST(root -> left, data);
    }

    return root;
}



void takeInput(Node* &root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}




void levelOrderTraversal(Node* root) {
    
    queue<Node*> q;

    q.push(root);
    q.push(NULL);   // including a separator, so that we can print the values in a tree format

    while(!q.empty()) {

        Node* temp = q.front();
        q.pop();

        // earlier level is traversed
        if (temp == NULL) {
            cout << endl;

            if(!q.empty()) {    // queue still has some child nodes
                q.push(NULL);
            }
        } 
        else {
            cout << " " << temp -> data << " " ;

            // condition = if temp left is not NULL
            if (temp -> left) {
                q.push(temp -> left);
            }

            // condition = if temp right is not NULL
            if (temp -> right) {
                q.push(temp -> right);
            }
        }
    }
}




void inOrderVal(Node* root, vector<int> &inorder) {
    if (root == NULL) return;

    inOrderVal(root -> left, inorder);
    inorder.push_back(root -> data);
    inOrderVal(root -> right, inorder);
}




Node *flattenBST(Node *root) {

    vector<int> inorder;

    inOrderVal(root, inorder);

    int n = inorder.size();

    Node* newNode = new Node(inorder[0]);

    Node* curr = newNode;

    for (int i=1; i<n ; i++) {
        Node* temp = new Node(inorder[i]);
        curr -> left = NULL;
        curr -> right = temp;

        curr = temp;
    }

    curr -> left = NULL;
    curr -> right = NULL;

    return newNode;
}





int main() {

    Node* root = NULL;

    cout << "Enter data to create BST : " << endl;
    // 10 8 21 7 27 5 4 3 -1
    takeInput(root);

    cout << endl << "Printing the level order traversal : " << endl;
    levelOrderTraversal(root);


    root = flattenBST(root);

    Node* temp = root;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> right;
    }

    return 0;
}