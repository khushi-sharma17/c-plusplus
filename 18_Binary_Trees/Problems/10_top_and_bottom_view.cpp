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




vector<int> topView(Node *root) {

    vector<int> ans;

    if (root == NULL) return ans;

    // Horizontal distance -> node data
    map<int, int> topNode;

    // pair is of Node and horizontal distance
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int horizontal_distance = temp.second;

        // make one to one mapping, if one value is present for a horizontal distance then do nothing.
        // In the below code, you tried to find the entry of the nodes corresponding to the horizontal_distance in the mapping, if you didn't find one, it adds the first node -> data into the mapping corresponding to the HD.
        if (topNode.find(horizontal_distance) == topNode.end()) {
            topNode[horizontal_distance] = frontNode -> data;
        }

        if (frontNode -> left) q.push(make_pair(frontNode -> left, horizontal_distance - 1));
        if (frontNode -> right) q.push(make_pair(frontNode -> right, horizontal_distance + 1));
    }

    for (auto i : topNode) {
        ans.push_back(i.second);
    }

    return ans;
}



// only change in the bottom view will be the condition corresponding to the mapping
vector<int> bottomView(Node *root) {

    vector<int> ans;

    if (root == NULL) return ans;

    // Horizontal distance -> node data
    map<int, int> topNode;

    // pair is of Node and horizontal distance
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int horizontal_distance = temp.second;

        // makes the mapping one to one and the last value for the node -> data will be added to the HD and the other values will be discarded.
        topNode[horizontal_distance] = frontNode -> data;

        if (frontNode -> left) q.push(make_pair(frontNode -> left, horizontal_distance - 1));
        if (frontNode -> right) q.push(make_pair(frontNode -> right, horizontal_distance + 1));
    }

    for (auto i : topNode) {
        ans.push_back(i.second);
    }

    return ans;
    
}



int main() {

    Node *root = NULL;

    // creating a binary tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    vector<int> topTraversal = topView(root);
    vector<int> bottomTraversal = bottomView(root);

    cout << endl;
    for (int i : topTraversal) {
        cout << i << " ";
    } cout << endl;

    for (int i : bottomTraversal) {
        cout << i << " ";
    } cout << endl;

    return 0;
}