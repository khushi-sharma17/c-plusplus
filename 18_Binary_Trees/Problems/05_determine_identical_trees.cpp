// Determin if two trees are identical or not.

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


// TC = O(n)
// SC = O(height of the tree)
bool isIdentical(Node *r1, Node *r2) {

    // Base cases
    if (r1 == NULL && r2 == NULL) return true;
    
    if (r1 == NULL && r2 != NULL) return false;
    
    if (r1 != NULL && r2 == NULL) return false;


    bool left = isIdentical(r1 -> left, r2 -> left);
    bool right = isIdentical(r1 -> right, r2 -> right);

    bool value = r1 -> data == r2 -> data;

    return (left && right && value) ? true : false;

}



int main() {

    Node *r1 = NULL;
    Node *r2 = NULL;

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
    r1 = buildTree(r1);
    r2 = buildTree(r2);

    isIdentical(r1, r2) ? cout << "Identical!" : cout << "Not Identical!";

    return 0;
}
