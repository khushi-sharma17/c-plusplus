// Construct a binary tree from inorder and postorder traversal

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




Node* solve(vector<int> &inorder, vector<int> &postOrder, int &postOrderIndex, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex) {

    // base case
    if (postOrderIndex < 0 || inOrderStart > inOrderEnd) {
        return NULL;
    }

    // creating a root node for the element
    int element = postOrder[postOrderIndex--];
    Node* root = new Node(element);

    // find element's index in inorder
    int position = nodeToIndex[element];

    // recursive calls
    // In case of postorder, we first built the right sub tree
    root -> right = solve(inorder, postOrder, postOrderIndex, position + 1, inOrderEnd, n, nodeToIndex);
    root -> left = solve(inorder, postOrder, postOrderIndex, inOrderStart, position-1, n, nodeToIndex);

    return root;

}





Node *buildTree(vector<int> &inorder, vector<int> &postOrder) {

    int n = inorder.size();
    int postOrderIndex = n-1;
    int inOrderIndex = 0;

    map<int, int> nodeToIndex;

    // creating nodes to index mapping
    createMapping(inorder, nodeToIndex, n);

    Node* ans = solve(inorder, postOrder, postOrderIndex, inOrderIndex, n-1, n, nodeToIndex);
    return ans;
}





int main() {

    Node *root = NULL;

    // creating a binary tree

    vector<int> inorder = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int> postOrder = {8, 4, 5, 2, 6, 7, 3, 1};

    root = buildTree(inorder, postOrder);

    levelOrderTraversal(root);

    return 0;
}


// TC = O(logn) + O(n) = O(n logn)
// logn coz the insertion time complexity of map is logn.