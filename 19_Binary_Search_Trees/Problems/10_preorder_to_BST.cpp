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


// TC of insertion = O(logn)
Node* insertIntoBST(Node* &root, int data) {

    // base case
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data > root -> data) {
        // insertion in the right part
        root -> right = insertIntoBST(root -> right, data);
    } else {
        root -> left = insertIntoBST(root -> left, data);
    }

    return root;
}



void takeInput(Node* &root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
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




Node* solve(int pre[], int mini, int maxi, int &i, int size) {

    // index out of size
    if (i >= size) return NULL;

    // out of range
    if (pre[i] < mini || pre[i] > maxi) return NULL;

    Node* root = new Node(pre[i++]);

    root -> left = solve(pre, mini, root -> data, i, size);
    root -> right = solve(pre, root -> data, maxi, i, size);

    return root;
}




Node* Bst(int pre[], int size) {

    int mini = INT_MIN;
    int maxi = INT_MAX;    
    
    int i = 0;
    return solve(pre, mini, maxi, i, size);

}





int main() {

    Node* root = NULL;

    int pre[] = {20, 10, 5, 15, 13, 35, 30, 42};
    int size = sizeof(pre)/sizeof(pre[0]);

    root = Bst(pre, size);

    cout << endl << "Printing the level order traversal : " << endl;
    levelOrderTraversal(root);

    return 0;
}