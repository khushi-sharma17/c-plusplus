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
// SC = O(n)
vector<int> zigZagTraversal(Node* root) {

    vector<int> result;

    if (root == NULL) return result;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;


    while(!q.empty()) {

        int size = q.size();

        vector<int> ans(size);

        // processing each level
        for (int i=0 ; i<size ; i++) {
            Node* frontNode = q.front();
            q.pop();

            // Normal insert or reverse insert
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode -> data;

            if (frontNode -> left)  q.push(frontNode -> left);
            if (frontNode -> right)  q.push(frontNode -> right);
        }

        // need to change the direction now
        leftToRight = !leftToRight;

        for (auto i : ans) {
            result.push_back(i);
        }
    }

    return result;
}



int main() {

    Node *root = NULL;

    // creating a binary tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    vector<int> traversal = zigZagTraversal(root);

    for(int i : traversal) {
        cout << i << " ";
    }

    return 0;
}