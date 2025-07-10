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

    ~Node() {
        int val = this -> data;

        if(this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }
        cout << "Memory is free for node with data " << val << endl;
    }
};


void InsertAtHead(Node* &head, int data) {

    Node* temp = new Node(data);

    temp -> next = head;
    head = temp;
}


void InsertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);

    tail -> next = temp;
    tail = temp;
}


void InsertAtAnyPosition(Node* &head, Node* &tail, int position, int data) {
    if(position == 1) {
        InsertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position - 1) {
        temp = temp -> next;
        cnt++;
    }

    // inserting at last position 
    if(temp -> next == NULL) {
        InsertAtTail(tail, data);
        return;
    }

    // Creating a node for the data part
    Node* nodeToInsert = new Node(data);

    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}


void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}



// simple reverse by looping the list
Node* reverse_list(Node* &head) {

    if (head == NULL || head -> next == NULL) {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}





// recursive first solution
Node* recursive_reverse_linked_list(Node* &head, Node* curr, Node* prev) {
    
    // base case
    if(curr == NULL) {
        head = prev;
        return prev;
    }

    Node* forward = curr -> next;
    recursive_reverse_linked_list(head, forward, curr);

    // it will come to this after going throuh the entire recursive stack first and will meet the first curr which was currently pointed to the head of the original list.
    curr -> next = prev;

    return head;
}




// recursive second solution
// it will return the head of the reverse list

Node* recursive_reverse(Node* &head) {
    
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    Node* smallHead = recursive_reverse(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return smallHead;
}





int main() {

    Node* node1 = new Node(0);

    Node* head = node1;
    Node* tail = node1;

    Node* curr = head;
    Node* prev = NULL;

    InsertAtTail(tail, 1);
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 3);
    InsertAtTail(tail, 4);
    InsertAtTail(tail, 5);

    print(head);


      
    // head = reverse_list(head);
    // print(head);



    Node* newHead = recursive_reverse_linked_list(head, curr, prev);
    print(newHead);


    // head = recursive_reverse(head);
    // print(head);


  

    return 0;
}

// Time Complexity = O(n)
// space complexity = O(1)
// space complexity = O(n) --> for recursive solution


// Hw = reverse of doubly linked list