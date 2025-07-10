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



// Inorder of BST is sorted
// LNR traversal
void inOrder(Node* root) {
    // base case
    if (root == NULL) {
        return;
    }

    inOrder(root -> left);      // left
    cout << root -> data << " ";        // Node
    inOrder(root -> right);     // right
}



// NLR traversal
void preOrder(Node* root) {
    // base case
    if (root == NULL) {
        return;
    }

    cout << root -> data << " ";        // Node
    preOrder(root -> left);      // left
    preOrder(root -> right);     // right
}



// LRN traversal
void postOrder(Node* root) {
    // base case
    if (root == NULL) {
        return;
    }

    postOrder(root -> left);      // left
    postOrder(root -> right);     // right
    cout << root -> data << " ";        // Node
}




Node* minVal(Node* root) {
    
    Node* temp = root;

    while (temp -> left != NULL) {
        temp = temp -> left;
    }
    return temp;
}




Node* maxVal(Node* root) {

    Node* temp = root;

    while (temp -> right != NULL) {
        temp = temp -> right;
    }
    return temp;
}




int main() {

    Node* root = NULL;

    cout << "Enter data to create BST : " << endl;
    // 10 8 21 7 27 5 4 3 -1
    takeInput(root);

    cout << endl << "Printing the level order traversal : " << endl;
    levelOrderTraversal(root);

    cout << endl << "Inorder traversal is : " << endl;
    inOrder(root);

    cout << endl << "preOrder traversal is : " << endl;
    preOrder(root);

    cout << endl << "postOrder traversal is : " << endl;
    postOrder(root);

    return 0;
}