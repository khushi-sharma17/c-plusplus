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


// for left view
void solve(Node* root, vector<int> &ans, int level) {
    // base case
    if (root == NULL) return;

    // we entered into a new level
    if (level == ans.size()) {
        ans.push_back(root -> data);
    }

    solve(root -> left, ans, level + 1);
    solve(root -> right, ans, level + 1);
}




vector<int> leftView(Node *root) {
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}






// for right view
void solveRight(Node* root, vector<int> &ans, int level) {
    // base case
    if (root == NULL) return;

    // we entered into a new level
    if (level == ans.size()) {
        ans.push_back(root -> data);
    }

    solveRight(root -> right, ans, level + 1);
    solveRight(root -> left, ans, level + 1);
}



vector<int> rightView(Node *root) {
    vector<int> ans;
    solveRight(root, ans, 0);
    return ans;
}




int main() {

    Node *root = NULL;

    // creating a binary tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    vector<int> leftTraversal = leftView(root);
    vector<int> rightTraversal = rightView(root);

    cout << endl;
    for (int i : leftTraversal) {
        cout << i << " ";
    } cout << endl;

    for (int i : rightTraversal) {
        cout << i << " ";
    } cout << endl;

    return 0;
}