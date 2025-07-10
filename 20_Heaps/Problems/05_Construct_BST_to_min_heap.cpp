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




void inOrder(Node* root, vector<int> &inOrderVector) {

    if (root == NULL) return;

    inOrder(root -> left, inOrderVector);
    inOrderVector.push_back(root -> data);
    inOrder(root -> right, inOrderVector);

}


// see this code also
Node* createMinHeapFromArray(vector<int>& arr) {

    if (arr.empty()) return NULL;

    vector<Node*> nodes;
    for (int val : arr) {
        nodes.push_back(new Node(val));
    }

    int n = arr.size();

    for (int i = 0; i <= (n - 2)/2; i++) {
        if (2*i + 1 < n) nodes[i] -> left = nodes[2*i + 1];
        if (2*i + 2 < n) nodes[i] -> right = nodes[2*i + 2];
    }

    return nodes[0];  // root of the min-heap
}




void preorderFill(Node* root, vector<int>& inorderArr, int& index) {

    if (root == nullptr) {
        return;
    }

    // Copy the next element from the inorder array
    root -> data = inorderArr[index++];

    // Fill left and right subtree
    preorderFill(root->left, inorderArr, index);  
    preorderFill(root->right, inorderArr, index);
}




int main() {

    Node* root = NULL;

    cout << "Enter data to create BST : " << endl;
    // 10 8 21 7 27 5 4 3 -1
    takeInput(root);

    cout << endl << "Printing the level order traversal : " << endl;
    levelOrderTraversal(root);


    vector<int> inOrderVector;
    inOrder(root, inOrderVector);

    for (auto i : inOrderVector) {
        cout << i << " ";
    }

    int index = 0;
    preorderFill(root, inOrderVector, index);

    cout << endl << "Printing the level order traversal : " << endl;
    levelOrderTraversal(root);


    return 0;
}