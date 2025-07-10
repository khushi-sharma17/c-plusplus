
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
        this -> left = nullptr;
        this -> right = NULL;
    }
};



Node *buildTree(Node *root) {

    cout << "Enter the data : ";
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1) {
        return NULL;
    }

    // recursively calling itself
    cout << endl << "Enter the data for inserting in the left of : " << root -> data << endl;
    root -> left = buildTree(root -> left);

    cout << endl << "Enter the data for inserting in the right of : " << data << endl;;
    root -> right = buildTree(root -> right);

    return root;
}




void reverseLevelOrderTraveral(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    stack<Node*> s;

    q.push(root);
    q.push(NULL);       // including a separator, so that we can print the values in a tree format

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        s.push(temp);

        if (temp == NULL) {

            if(!q.empty()) {    // queue still has some child nodes
                q.push(NULL);
            }
        } 
        else {
            if (temp -> right) q.push(temp -> right);       // right first 
            if (temp -> left) q.push(temp -> left);     // then left
        }
    }

    while(!s.empty()) {
        s.top() ? cout << s.top() -> data << " " : cout << endl;
        s.pop();
    }
}





// Iterative Inorder traversal (LNR)
void inOrder(Node* root) {

    stack<Node*> s;
    Node* curr = root;

    while(curr != NULL || !s.empty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr -> left;
        }

        curr = s.top();
        s.pop();
        cout << curr -> data << " ";
        curr = curr -> right;
    }

    cout << endl;
}




// Iterative Preorder Traversal (NLR)
void preOrder(Node* root) {

    if (root == NULL) return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();

        cout << curr -> data << " ";

        if(curr -> right) s.push(curr -> right);
        if(curr -> left) s.push(curr -> left);
    }

    cout << endl;
}




// Iterative PostOrder Traversal (LRN)
void postOrder(Node* root) {
    
    if (root == NULL) return;

    stack<Node*> st1, st2;
    st1.push(root);

    // filling the elements in stack2 in the order of (NRL)
    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);

        if (curr -> left) st1.push(curr -> left);
        if (curr -> right) st1.push(curr -> right);
    }

    while (!st2.empty()) {
        cout << st2.top() -> data << " ";
        st2.pop();
    }

    cout << endl;
}





int main() {

    Node *root = NULL;

    // creating a binary tree
    root = buildTree(root);


    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // reverse level order traversal;
    // cout << endl << "Printing the reverse level order traversal : " << endl;
    // reverseLevelOrderTraveral(root);



    cout << endl << "Inorder traversal is : " << endl;
    inOrder(root);

    cout << endl << "preOrder traversal is : " << endl;
    preOrder(root);

    cout << endl << "postOrder traversal is : " << endl;
    postOrder(root);


    return 0;
}