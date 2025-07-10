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



// here, the pair's first value denotes that the sum's value is same for both of the left and right subtrees and the second value denotes the sum.
pair<bool, int> isSumTreePair(Node* root) {

    // Base case
    if (root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root -> left == NULL && root -> right == NULL) {
        pair<bool, int> p = make_pair(true, root -> data);
        return p;
    }

    pair<bool, int> leftAns = isSumTreePair(root -> left);
    pair<bool, int> rightAns = isSumTreePair(root -> right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condition = (root -> data == leftAns.second + rightAns.second);

    pair<bool, int> ans;
    ans.first = (left && right && condition) ? true : false;

    if (ans.first) ans.second = 2 * root -> data;

    return ans;
}



bool isSumTree(Node* root) {
    return isSumTreePair(root).first;
}



int main() {

    Node *root = NULL;

    // creating a binary tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    isSumTree(root) ? cout << "Yes, It is a sum tree!" : cout << "No, It is not a sum tree!";

    return 0;
}