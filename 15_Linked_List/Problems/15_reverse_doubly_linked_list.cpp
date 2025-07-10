#include <iostream>
using namespace std;

class Node {
    public :
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};


void insertAtHead(Node* &head, Node* &tail, int data) {
    // if the list is empty
    Node* newNode = new Node(data);

    if (head == NULL && tail == NULL) {
        head = newNode;
        tail = newNode;
    }

    // if the list is not empty
    else {
        newNode -> next = head;
        newNode -> prev = NULL;
        head = newNode;
    }
}


void insertAtTail(Node* &head, Node* &tail, int data) {
    // if the list is empty
    Node* newNode = new Node(data);

    if (head == NULL && tail == NULL) {
        head = newNode;
        tail = newNode;
    }

    // if the list is not empty
    else {
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
}


void print(Node* head) {

    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


void reversing_by_just_using_prev_pointer(Node* head, Node* tail) {
    
    Node* temp = tail;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> prev;
    }
    cout << endl;
}



void reversing_in_memory(Node* &head, Node* &tail) {
    Node* curr = head;
    Node* temp = NULL;

    // swapping next and prev for all nodes
    while(curr != NULL) {
        temp = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = temp;
        curr = curr -> prev;
    }

    temp = head;
    head = tail;
    tail = temp;
}



int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 3);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 9);
    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 13);

    print(head);
    cout << "Head : " << head -> data << endl;
    cout << "Tail : " << tail -> data << endl << endl;


    reversing_by_just_using_prev_pointer(head, tail);
    cout << "Head : " << head -> data << endl;
    cout << "Tail : " << tail -> data << endl << endl;


    reversing_in_memory(head, tail);
    print(head);
    cout << "Head : " << head -> data << endl;
    cout << "Tail : " << tail -> data << endl << endl;

    return 0;
}