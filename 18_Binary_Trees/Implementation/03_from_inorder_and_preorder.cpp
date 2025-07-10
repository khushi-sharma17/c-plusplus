// Construct a binary tree from inorder/preorder/postorder traversal

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



void createMapping(vector<int> &inorder, map<int, int> &nodeToIndex, int n) {
    for (int i = 0; i<n ; i++) {
        nodeToIndex[inorder[i]] = i; 
    }
}




Node* solve(vector<int> &inorder, vector<int> &preorder, int &preOrderIndex, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex) {

    // base case
    if (preOrderIndex >= n || inOrderStart > inOrderEnd) {
        return NULL;
    }

    // creating a root node for the element
    int element = preorder[preOrderIndex++];
    Node* root = new Node(element);

    // find element's index in inorder
    int position = nodeToIndex[element];

    // recursive calls
    root -> left = solve(inorder, preorder, preOrderIndex, inOrderStart, position-1, n, nodeToIndex);
    root -> right = solve(inorder, preorder, preOrderIndex, position + 1, inOrderEnd, n, nodeToIndex);

    return root;

}





Node *buildTree(vector<int> &inorder, vector<int> &preorder) {

    int preOrderIndex = 0;
    int inOrderIndex = 0;
    int n = inorder.size();

    map<int, int> nodeToIndex;

    // creating nodes to index mapping
    createMapping(inorder, nodeToIndex, n);

    Node* ans = solve(inorder, preorder, preOrderIndex, inOrderIndex, n-1, n, nodeToIndex);
    return ans;
}





int main() {

    Node *root = NULL;

    // creating a binary tree

    vector<int> inorder = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int> preorder = {1, 2, 4, 8, 5, 3, 6, 7};

    root = buildTree(inorder, preorder);

    levelOrderTraversal(root);

    return 0;
}