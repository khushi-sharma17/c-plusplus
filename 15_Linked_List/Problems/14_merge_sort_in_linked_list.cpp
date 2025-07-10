#include <iostream>
using namespace std;

class Node {
    public : 
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};



void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);

    temp -> next = head;
    head = temp;
}



void insertAtTail(Node* &head, Node* &tail, int data) {

    Node* newNode = new Node(data);

    // if the list is empty
    if (head == NULL && tail == NULL) {
        head = newNode;
        tail = newNode;
    } 
    
    else {
        tail -> next = newNode;
        tail = newNode;
    }
}





void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}



Node* getMiddle(Node* head) {

    Node* slow = head;
    Node* fast = head -> next;  // Start fast one step ahead to stop at previous mid

    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    // slow now points to node **before** actual mid
    return slow;
}



Node* merge(Node* &left, Node* &right) {

    if (left == NULL) return right;
    if (right == NULL) return left;

    // dummy node
    Node* ans = new Node(-1);
    Node* temp = ans;

    // merging two sorted linked list
    while(left != NULL && right != NULL) {

        if (left -> data < right -> data) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    while (left != NULL) {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }

    while (right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }

    ans = ans -> next;
    return ans;
}



Node* mergeSort(Node* &head) {

    // base case
    if (head == NULL || head -> next == NULL) {
        return head;
    }

    Node* mid = getMiddle(head);

    // breaking linked list into two halves, after finding the mid;
    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL;


    // recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    
    // merging and sorting both left and right halves
    Node* result = merge(left, right);

    return result;
}


int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 9);
    insertAtTail(head, tail, 2);

    print(head);


    head = mergeSort(head);
    print(head);


    return 0;
}

// TC = O(n logn) 
// SC = O(logn)