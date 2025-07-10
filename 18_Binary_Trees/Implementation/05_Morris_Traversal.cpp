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




vector<int> inOrderMorris(Node* root) {

    vector<int> result;
    Node* curr = root;

    while (curr != nullptr) {

        if (curr -> left == nullptr) {
            // if no left child visit this node and go right
            result.push_back(curr -> data);
            curr = curr -> right;
        }

        else {
            // finding the inorder predecessor of curr
            Node* prev = curr -> left;
            
            while (prev -> right != nullptr && prev -> right != curr) {
                prev = prev -> right;
            }

            // make curr the right child of its inorder predecessor
            if (prev -> right == nullptr) {
                prev -> right = curr;
                curr = curr -> left;
            } else {
                // reverting the changes made in the tree structure
                prev -> right = nullptr;
                result.push_back(curr -> data);
                curr = curr -> right;
            }
        }
    }

    return result;
}




void preOrderMorris(Node* root) { 

    while (root)  { 
        
      	// If left child is null, print the 
      	// current node data. Move to  right child. 
        if (root->left == nullptr)  { 
            cout<<root->data<<" "; 
            root = root->right; 
        } 
        else { 
            
          	// Find inorder predecessor 
            Node* current = root->left; 
            while (current->right && current->right != root) 
                current = current->right; 

            // If the right child of inorder predecessor
          	// already points to this node 
            if (current->right == root)  { 
                current->right = nullptr; 
                root = root->right; 
            } 

            // If right child doesn't point to this node, then print this 
            // node and make right child point to this node 
            else { 
                cout<<root->data<<" "; 
                current->right = root; 
                root = root->left; 
            } 
        } 
    } 
} 




vector<int> postorderTraversal(Node* root) {
    vector<int> res;
    Node* current = root;

    while (current != NULL) {
        // If right child is null,
        // put the current node data
        // in res. Move to left child.
        if (current->right == NULL) {
            res.push_back(current -> data);
            current = current->left;
        }
        else {
            Node* predecessor = current->right;
            while (predecessor->left != NULL
                   && predecessor->left != current) {
                predecessor = predecessor->left;
            }
            // If left child doesn't point
            // to this node, then put in res
            // this node and make left
            // child point to this node
            if (predecessor->left == NULL) {
                res.push_back(current -> data);
                predecessor->left = current;
                current = current->right;
            }
            // If the left child of inorder predecessor
            // already points to this node
            else {
                predecessor->left = NULL;
                current = current->left;
            }
        }
    }
    // reverse the res
    reverse(res.begin(), res.end());
    return res;
}





int main() {

    Node *root = NULL;

    // creating a binary tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    vector<int> result = inOrderMorris(root);

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}