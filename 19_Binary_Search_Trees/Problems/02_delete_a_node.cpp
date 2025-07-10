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



Node* minVal(Node* root) {
    
    Node* temp = root;

    while (temp -> left != NULL) {
        temp = temp -> left;
    }
    return temp;
}



Node* deleteFromBST(Node* &root, int val) {
    // base case
    if (root == NULL) {
        return NULL;
    }


    if (root -> data == val) {
        // 0 child
        if (root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }



        // 1 child - two cases

        // left child
        if (root -> left != NULL && root -> right == NULL) {
            Node* temp = root -> left;
            delete root;
            return temp;
        } 
        // right child
        else if (root -> left == NULL && root -> right != NULL) {
            Node* temp = root -> right;
            delete root;
            return temp;
        }



        // 2 child
        if (root -> left != NULL && root -> right != NULL) {
            int mini = minVal(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }

    }


    else if (root -> data > val) {
        root -> left = deleteFromBST(root -> left, val);
        return root;
    }
    
    else {
        root -> right = deleteFromBST(root -> right, val);
        return root;
    }
} 




int main() {

    Node* root = NULL;

    cout << "Enter data to create BST : " << endl;
    // 10 8 21 7 27 5 4 3 -1
    takeInput(root);

    cout << endl << "Printing the level order traversal : " << endl;
    levelOrderTraversal(root);

    
    root = deleteFromBST(root, 10);


    cout << endl << "Printing the level order traversal : " << endl;
    levelOrderTraversal(root);


    return 0;
}