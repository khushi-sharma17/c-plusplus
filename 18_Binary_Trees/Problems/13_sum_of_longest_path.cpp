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



void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {

    if (root == NULL) {
        if (len > maxLen) {
            maxLen = len;
            maxSum = sum;
        } else if (len == maxLen) {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum += root -> data;
    solve(root -> left, sum, maxSum, len + 1, maxLen);
    solve(root -> right, sum, maxSum, len + 1, maxLen);
}



int sumOfLongRootToLeafPath(Node *root) {
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = INT_MIN;

    solve(root, sum, maxSum, len, maxLen);

    return maxSum;
}



int main() {

    Node *root = NULL;

    // creating a binary tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    int result = sumOfLongRootToLeafPath(root);

    cout << endl << "The sum of the longest path from root to the leaf node is : " << result << endl;

    return 0;
}


// TC = O(n)
// SC = O(h)