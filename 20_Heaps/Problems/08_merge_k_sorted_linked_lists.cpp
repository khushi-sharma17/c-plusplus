#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Node {
    public :
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = nullptr;
    }
};


class compare {
    public :
    bool operator() (Node* a, Node* b) {
        return a -> data > b -> data;
    }
};



// first element of k linked lists 
// TC = O(n*k logk)
// SC = O(k)
Node* mergeKLists(vector<Node*>& arr) {

    priority_queue<Node*, vector<Node*>, compare> pq;

    int k = arr.size();

    if (k == 0) return NULL;

    for (int i=0 ; i<k ; i++) {
        if (arr[i] != NULL) {
            pq.push(arr[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;


    while (pq.size() > 0) {

        Node* top = pq.top();
        pq.pop();

        if (top -> next != NULL) {
            pq.push(top -> next);
        }

        if (head == NULL) {     // LL is empty
            head = top;
            tail = top;
        } 

        else {      // insert at end
            tail -> next = top;     
            tail = top;
        }
    }

    return head;
}



int main() {

    

    return 0;
}