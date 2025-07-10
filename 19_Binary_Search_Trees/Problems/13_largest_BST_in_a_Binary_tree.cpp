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




Node* buildFromLevelOrder(Node* root) {

    queue<Node*> q;

    cout << "Enter data for root : ";
    int data;
    cin >> data;
    root = new Node(data);

    q.push(root);


    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node data for the value, " << temp -> data << " : " << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter right node data for the value, " << temp -> data << " : "  << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }

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




class Info {
    public : 
    int maxi;
    int mini;
    bool isBST;
    int size;
};




Info solve(Node* root, int &maxSize) {
    // Base case
    if (root == NULL) {
        return {INT_MIN, INT_MAX, true, 0};
    }

    Info left = solve(root -> left, maxSize);
    Info right = solve(root -> right, maxSize);

    Info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root -> data, right.maxi);
    currNode.mini = min(root -> data, left.mini);
    left.isBST && right.isBST && (root -> data > left.maxi && root -> data < right.mini) ? currNode.isBST = true : currNode.isBST = false;

    // updating the answer
    if (currNode.isBST) {
        maxSize = max(maxSize, currNode.size);
    }

    return currNode;
}




int largestBst(Node *root) {
    int maxSize = 0;
    Info temp = solve(root, maxSize);
    return maxSize;
}





int main() {

    Node* root = NULL;

    cout << "Enter data to create BST : " << endl;
    root = buildFromLevelOrder(root);

    cout << endl << "Printing the level order traversal : " << endl;
    levelOrderTraversal(root);


    int largestBSTSize = largestBst(root);
    cout << "The size of the largest BST in a binary tree is : " << largestBSTSize;

    return 0;
}