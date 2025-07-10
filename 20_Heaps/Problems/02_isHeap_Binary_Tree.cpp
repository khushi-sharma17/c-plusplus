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




int countNodes(Node* root) {
    // base case
    if (root == NULL) return 0;

    int ans = 1 + countNodes(root -> left) + countNodes(root -> right);
    return ans;
}



bool isCBT(Node* root, int index, int totalCount) {
    // base case
    if (root == NULL) return true;

    if (index >= totalCount) {
        return false;
    }

    else {
        bool left = isCBT(root -> left, 2*index + 1, totalCount);
        bool right = isCBT(root -> right, 2*index + 2, totalCount);
        return (left && right);
    }
}



bool isMaxOrder(Node* root) {

    // leaf nodes
    if (root -> left == NULL && root -> right == NULL) return true;

    // only left exists
    if (root -> right == NULL) {    
        return (root -> data > root -> left -> data);
    }

    else {
        bool left = isMaxOrder(root -> left);
        bool right = isMaxOrder(root -> right);
         
        return (left && right && ((root -> data > root -> left -> data) && (root -> data > root -> right -> data)));
    }
}



bool isHeap(Node* root) {

    int index = 0;
    int totalCount = countNodes(root);
    
    return (isCBT(root, index, totalCount) && isMaxOrder(root));
}



int main() {


    Node *root = NULL;
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // level order traversal;
    cout << endl << "Printing the level order traversal : " << endl;
    levelOrderTraversal(root);


    isHeap(root) ? cout << "This Binary Tree is a Heap" : cout << "This Binary Tree is not a heap";

    return 0;
}