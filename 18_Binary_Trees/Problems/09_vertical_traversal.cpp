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



vector<vector<int>> verticalOrder(Node *root) {

    map<int, map<int, vector<int>>> nodes;
    queue <pair <Node*, pair<int, int>>> q;

    vector<vector<int>> ans;

    if (root == NULL) return ans;

    // in the second pair in the below line, it denotes the first part as the horizontal distance and the second partas the level.
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty()) {

        pair <Node*, pair<int, int>> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int horizontal_distance = temp.second.first;
        int level = temp.second.second;

        nodes[horizontal_distance][level].push_back(frontNode -> data);

        if (frontNode -> left) q.push(make_pair(frontNode -> left, make_pair(horizontal_distance - 1, level + 1)));
        if (frontNode -> right) q.push(make_pair(frontNode -> right, make_pair(horizontal_distance + 1, level + 1)));
    }


    for (auto i : nodes) {
        vector<int> col;
        for (auto j : i.second) {
            col.insert(col.end(), j.second.begin(), j.second.end());
        }
        ans.push_back(col);
    }

    return ans;
}




vector<vector<int>> verticalOrderAnotherMethod(Node *root) {
    vector<vector<int>> ans;

    if (root == NULL) return ans;

    // Map: HD -> list of node values
    map<int, vector<int>> verticalMap;

    // Queue: pair<Node*, HD>
    queue<pair<Node*, int>> q;
    q.push({root, 0});


    while (!q.empty()) {
        pair<Node*, int> p = q.front();
        Node* frontNode = p.first;
        q.pop();

        int hd = p.second;

        verticalMap[hd].push_back(frontNode -> data);

        if (frontNode -> left) {
            q.push({frontNode -> left, hd - 1});
        }
        if (frontNode -> right) {
            q.push({frontNode -> right, hd + 1});
        }
    }

    // Extracting values in left-to-right HD order
    for (auto &entry : verticalMap) {
        ans.push_back(entry.second);
    }

    return ans;
    
}




int main() {

    Node *root = NULL;

    // creating a binary tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1 
    root = buildTree(root);

    vector<vector<int>> traversal = verticalOrder(root);

    cout << "[";
    for (vector<int> row : traversal) {
        cout << " [";
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << "] ";
    }
    cout << "]";

    return 0;
}