// diameter of a tree = longest path between any two end nodes be it either leaf or right nodes.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>

class TreeNode {
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


TreeNode<int> *buildTree() {

    cout << "Enter the data : ";
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    TreeNode<int>* root = new TreeNode<int>(data);

    // recursively calling itself
    cout << endl << "Enter the data for inserting in the left of : " << data << endl;
    root -> left = buildTree();

    cout << endl << "Enter the data for inserting in the right of : " << data << endl;;
    root -> right = buildTree();

    return root;
}


// TC = O()
int height(TreeNode<int> *root){
    if (root == NULL) {
        return 0;
    }

    int left = height(root -> left);
    int right = height(root -> right);

    int ans = max(left, right) + 1;
    return ans;
}


// TC = O(n square)
int diameter(TreeNode<int> *root){
    // base case
	if (root == NULL) {
        return 0;
    }

    int option1 = diameter(root -> left);
    int option2 = diameter(root -> right);

    int option3 = height(root -> left) + height(root -> right);

    int ans = max(option1, max(option2, option3));

    return ans;
}




// TC = O(n)
// SC = O(height) || O(n) if a skewed tree
pair<int, int> diameterFast(TreeNode<int> *root) {

    // base case, when the root is NULL, then both our diameter and height will be 0.
	if (root == NULL) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root -> left);
    pair<int, int> right = diameterFast(root -> right);

    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second;

    pair<int, int> ans;
    ans.first = max(opt1, max(opt2, opt3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}




int main() {

    // Build the binary tree
    cout << "Enter elements of the binary tree:" << endl;
    TreeNode<int>* root = buildTree();

    // Calculate the number of leaf nodes
    // int diam = diameter(root);

    int diam = diameterFast(root).first;

    cout << endl << "The diameter of the binary tree is : " << diam << endl;

    return 0;
}