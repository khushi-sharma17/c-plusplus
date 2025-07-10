// Maximum sum of non adjacent nodes

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



pair<int, int> solve(Node* root) {
    // base case
    if (root == NULL) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = solve(root -> left);
    pair<int, int> right = solve(root -> right);

    pair<int, int> result;
    result.first = root -> data + left.second + right.second;
    result.second = max(left.first, left.second) + max(right.first, right.second);

    return result;
}



int getMaxSum(Node *root) {
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}
// ans.first = maximum sum including nodes at current level
// ans.second = maximum sum excluding nodes at current level



int main() {

    Node *root = NULL;

    // creating a binary tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    int sum = getMaxSum(root);

    cout << endl << "The Maximum sum of non adjacent nodes is : " << sum << endl;

    return 0;
}