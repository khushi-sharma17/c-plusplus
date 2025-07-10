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




vector<Node*> findPreSuc(Node* root, int key) {

    vector<Node*> ans;

    // find key
    Node* temp = root;

    Node* pred = NULL;
    Node* succ = NULL;

    while (temp -> data != key) {

        if (temp -> data > key) {
            succ = temp;    // possible succesor
            temp = temp -> left;
        }    
        else {
            pred = temp;    // possible predecessor
            temp = temp -> right;
        }
    }

    // predecessor
    Node* leftTree = temp -> left;
    while (leftTree != NULL) {
        pred = leftTree;
        leftTree = leftTree -> right;
    }

    // sucessor
    Node* rightTree = temp -> right;
    while (rightTree != NULL) {
        succ = rightTree;
        rightTree = rightTree -> left;
    }

    ans.push_back(pred);
    ans.push_back(succ);

    return ans;
}





int main() {

    Node* root = NULL;

    cout << "Enter data to create BST : " << endl;
    // 10 8 21 7 27 5 4 3 -1
    takeInput(root);

    cout << endl << "Printing the level order traversal : " << endl;
    levelOrderTraversal(root);


    vector<Node*> ans = findPreSuc(root, 10);

    for (Node* i : ans) {
        cout << i -> data << " ";
    }
    
    return 0;
}