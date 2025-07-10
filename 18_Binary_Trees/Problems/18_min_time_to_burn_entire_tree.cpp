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



// step 1 : create nodeToParent mapping 
// step 2 : also return target node
Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent) {

    Node* res = NULL;
    queue<Node*> q;
    q.push(root);

    // root has no parent
    nodeToParent[root] = NULL;

    while (!q.empty()) {

        Node* front = q.front();
        q.pop();

        if (front -> data == target) res = front;


        if (front -> left) {
            nodeToParent[front -> left] = front;
            q.push(front -> left);
        }

        if (front -> right) {
            nodeToParent[front -> right] = front;
            q.push(front -> right);
        }

    }

    return res;

}



// burn the tree in min time
int burnTree(Node* root, map<Node*, Node*> &nodeToParent) {
    map<Node*, bool> visited;
    queue<Node*> q;

    q.push(root);
    visited[root] = true;

    int time = 0;

    while (!q.empty()) {

        int size = q.size();

        // for marking the addition in the time value.
        bool flag = false;

        for (int i=0; i<size ; i++) {
            // process neighbouring nodes
            Node* front = q.front();
            q.pop();

            // for the left child
            if (front -> left && !visited[front -> left]) {
                q.push(front -> left);
                visited[front -> left] = true;
                flag = true;
            }

            // for the right child
            if (front -> right && !visited[front -> right]) {
                q.push(front -> right);
                visited[front -> right] = true;
                flag = true;
            }

            if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
                flag = true;
            }
        }

        if (flag == true) {
            time++;
        }
    }

    return time;
}




int minTime(Node* root, int target) {

    map<Node*, Node*> nodeToParent;
    Node* targetNode = createParentMapping(root, target, nodeToParent);

    int time = burnTree(targetNode, nodeToParent);

    return time;
}




int main() {

    Node *root = NULL;

    // creating a binary tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    int time = minTime(root, 7);

    cout << "The minimum time to burn the entire tree is : " << time << endl;

    return 0;
}