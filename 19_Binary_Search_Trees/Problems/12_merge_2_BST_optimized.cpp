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




void convertIntoSortedDLL(Node* root, Node* &head) {

    if (root == NULL) return;

    // for right part
    convertIntoSortedDLL(root -> right, head);

    root -> right = head;
    if (head != NULL) head -> left = root;
    head = root;

    // for left part 
    convertIntoSortedDLL(root -> left, head);
}




// merging two sorted linked list
Node* mergeLinkedList(Node *root1, Node *root2) {
    Node* head = NULL;
    Node* tail = NULL;

    while (root1 != NULL && root2 != NULL) {

        if (root1 -> data < root2 -> data) {
            if (head == NULL) {
                head = root1;
                tail = root1;
                root1 = root1 -> right;
            }
            else {
                tail -> right = root1;
                root1 -> left = tail;
                tail = root1;
                root1 = root1 -> right;
            }
        }

        else { 
            if (head == NULL) {
                head = root2;
                tail = root2;
                root2 = root2 -> right;
            }
            else {
                tail -> right = root2;
                root2 -> left = tail;
                tail = root2;
                root2 = root2 -> right;
            }
        }
    }


    while (root1 != NULL) {
        tail -> right = root1;
        root1 -> left = tail;
        tail = root1;
        root1 = root1 -> right;
    }

    while (root2 != NULL) {
        tail -> right = root2;
        root2 -> left = tail;
        tail = root2;
        root2 = root2 -> right;
    }

    return head;
}




int countNodes(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL) {
        cnt++;
        temp = temp -> right;
    }

    return cnt;
}




// creating a BST from a sorted LL
Node* sortedLLToBST(Node* &head, int n) {
    // Base case
    if (n <= 0 || head == NULL) return NULL;

    Node* left = sortedLLToBST(head, n/2);
    Node* root = head;
    root -> left = left;

    head = head -> right;

    root -> right = sortedLLToBST(head, n - n/2 - 1);
    return root;
}




Node* mergeBST(Node* root1, Node* root2) {


    // converting BST into sorted LL in-place
    Node* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1 -> left = NULL;

    Node* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2 -> left = NULL;


    // merge sorted LL
    Node* head = mergeLinkedList(head1, head2);


    // convert sorted LL into BST
    return sortedLLToBST(head, countNodes(head));

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



    Node* head = mergeBST(root1, root2);
    cout << endl << "Printing the level order traversal : " << endl;
    levelOrderTraversal(head);
    
    return 0;
}


// Steps : 
// 1. Convert a BST into sorted LL.
// 2. Merge 2 sorted LL
// 3. sorted LL -> BST