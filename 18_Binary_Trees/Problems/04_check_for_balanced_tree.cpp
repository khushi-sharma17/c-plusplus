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



int height(Node *root){
    if (root == NULL) {
        return 0;
    }

    int left = height(root -> left);
    int right = height(root -> right);

    int ans = max(left, right) + 1;
    return ans;
}



// TC = O(n square)
bool isBalanced(Node* root) {
    
    // Base case
    if (root == NULL) return true;

    bool left = isBalanced(root -> left);
    bool right = isBalanced(root -> right);

    bool diff = abs(height(root -> left) - height(root -> right)) <= 1;

    (left && right && diff) ? true : false;   
}



// TC = O(n)
pair<bool, int> isBalancedFast(Node* root) {

    // Base case
    if (root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = isBalancedFast(root -> left);
    pair<bool, int> right = isBalancedFast(root -> right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;


    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;


    (leftAns && rightAns && diff) ? ans.first = true : ans.first = false;

    return ans;
}



int main() {

    Node* root = NULL;

    // Build the binary tree
    cout << "Enter elements of the binary tree:" << endl;
    root = buildTree(root);

    pair<bool, int> ans = isBalancedFast(root);

    if(ans.first) {
        cout << "The tree is balanced.";
    } else {
        cout << "The tree is not balanced.";
    }

    return 0;
}