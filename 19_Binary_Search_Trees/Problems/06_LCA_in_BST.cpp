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




Node* LCA(Node* root, Node* n1, Node* n2) {
    
    // base case
    if (root == NULL) return NULL;

    if ((root -> data < n1 -> data) && (root -> data < n2 -> data)) {
        return LCA(root -> right, n1, n2);
    } 

    else if ((root -> data > n1 -> data) && (root -> data > n2 -> data)) {
        return LCA(root -> left, n1, n2);
    }
        
    return root; 
}




int main() {

    Node* root = NULL;

    cout << "Enter data to create BST : " << endl;
    // 10 8 21 7 27 5 4 3 -1
    takeInput(root);

    cout << endl << "Printing the level order traversal : " << endl;
    levelOrderTraversal(root);


    Node* lca = LCA(root, root -> left, root -> right);
    cout << endl << "The lowest common ancestor is : " << lca -> data ;


    return 0;
}