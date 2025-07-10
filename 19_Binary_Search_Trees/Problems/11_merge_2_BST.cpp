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




void inOrderVal(Node* &root, vector<int> &inorder) {
    if (root == NULL) return;

    inOrderVal(root -> left, inorder);
    inorder.push_back(root -> data);
    inOrderVal(root -> right, inorder);
}




void mergeArrays(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    // starting from the end of both the vector;
    int i = m-1;
    int j = n-1;

    int k = m + n - 1; // index for the merged vector (nums1)

    // Merge from the end to the beginning
    while(i >= 0 && j >= 0) {
        // compare the elements from both the vector and place the larger one in nums1;
        if(nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        }
        else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // If there are remaining elements in nums2, copy them to num1
    while(j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }

}




Node* inorderToBST(int start, int end, vector<int> &inorder) {
    // base case
    if (start > end) return NULL;

    int mid = start + (end - start) / 2;

    Node* root = new Node(inorder[mid]);

    root -> left = inorderToBST(start, mid - 1, inorder);
    root -> right = inorderToBST(mid + 1, end, inorder);

    return root;
}





vector<int> merge(Node *root1, Node *root2) {

    vector<int> bst1, bst2;

    // creating inorder of both the arrays
    inOrderVal(root1, bst1);
    inOrderVal(root2, bst2);

    int m = bst1.size();
    int n = bst2.size();

    bst1.resize(m + n);

    mergeArrays(bst1, m, bst2, n);


    // vector<int> mergedArray;
    // merge(bst1.begin(), bst1.end(), bst2.begin(), bst2.end(), back_inserter(mergedArray));
    // return mergedArray;

    return bst1;
}






int main() {


    Node* root1 = NULL;

    cout << "Enter data to create BST : " << endl;
    // 5 3 6 2 4 -1
    takeInput(root1);

    cout << endl << "Printing the level order traversal : " << endl;
    levelOrderTraversal(root1);



    Node* root2 = NULL;

    cout << "Enter data to create BST : " << endl;
    // 2 1 3 7 6 -1
    takeInput(root2);

    cout << endl << "Printing the level order traversal : " << endl;
    levelOrderTraversal(root2);


    vector<int> mergedArray = merge(root1, root2);

    for (int i : mergedArray) {
        cout << i << " ";
    }


    
    Node* mergedRoot = inorderToBST(0, mergedArray.size()-1, mergedArray);

    cout << endl << endl << "Printing the level order traversal : " << endl;
    levelOrderTraversal(mergedRoot);


    return 0;
}