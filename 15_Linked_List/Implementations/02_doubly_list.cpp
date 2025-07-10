// A node in a doubly linked list has : prev part, data part and next part.

#include <iostream>
using namespace std;

class Node {
    
    public :
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int data) {
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~Node() {

        int val = this -> data;
        
        // if(this -> next != NULL) {
        //     delete next;
        //     this -> next = NULL;
        // }

        cout << "Memory is free for node with data " << val << endl << endl;
    }
};





// traversing a linked list
void print(Node* &head) {
    Node *temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}





// gives length of the doubly linked list
int getLength(Node* &head) {
    int len = 0;
    Node *temp = head;

    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }
    return len;
}





void insertAtHead(Node* &head, int data) {
    // Creating a new node here for the data.
    Node *temp = new Node(data);

    if(head != NULL) {
        temp -> next = head;
        head -> prev = temp;
    }
    
    // give the correct position of the head here.
    head = temp;
}





void insertAtTail(Node* &tail, int data) {
    // creating a new node here for the data part.
    Node *temp = new Node(data);
    
    if(tail != NULL) {
        tail -> next = temp;
        temp -> prev = tail;
    }

    // giving the correct position of the tail here.
    tail = temp;
}






void insertAtAnyPosition(Node* &head, Node* &tail, int position,  int data) {

    // Inserting at start
    if(position == 1) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int count = 1;

    // The purpose of subtracting 1 in the condition count < position - 1 is to ensure that the loop stops when count becomes equal to position - 1. This is because, in the context of inserting a node at a specific position, you want to stop at the node just before the desired position so that you can correctly link the new node with the surrounding nodes during the insertion process. 
    while(count < position - 1) {
        temp = temp -> next;
        count++;
    }

    // inserting at the last
    if(temp -> next == NULL) {
        insertAtTail(tail, data);
        return;
    }

    // creating a new node for the data part
    Node* nodeToInsert = new Node(data);

    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}




// deleting a node position wise
void deleteNode(int position, Node* &head, Node* &tail) {
    
    // deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;

        // freeing the memory of the start node
        temp -> next = NULL;    

        delete temp;
    }

    else {
        // deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < position) {
            prev = curr;
            curr = curr -> next;
            count++;
        }

        // tail needs to be updated
        if(curr -> next == NULL) {
            tail = prev;
            tail -> next = NULL;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}




// deleting a node value wise
void deleteNodeByValue(int value, Node* &head, Node* &tail) {

    Node* curr = head;
    Node* prev = NULL;


    while (curr != NULL) {

        if (curr -> data == value) {

            // If it is the head node
            if (curr == head) {
                head -> next -> prev = NULL;
                head = head -> next;
                
                // If it is also the only node in the whole list
                if (curr == tail) {
                    tail = NULL;
                }
    
                Node* temp = curr;
                curr = curr -> next;
                delete temp;
            }
    
            // if it is in the middle or at the end
            else {

                if (curr == tail) {
                    tail = prev;
                    prev -> next = NULL;
                    delete curr;
                    return;
                } 
                
                else {
                    prev -> next = curr -> next;
                    curr -> next -> prev = prev;
                }

                Node* temp = curr;
                curr = curr -> next;
                delete temp;
            }
        } 
        
        else {
            // looping here
            prev = curr;
            curr = curr -> next;
        }
    }
    
}




int main() {

    // Creating a new node
    Node *node1 = new Node(10);

    Node *head = node1;
    Node *tail = node1;

    print(head);

    cout << "The length of the node is : " << getLength(head) << endl << endl;
    
    insertAtHead(head, 67);
    print(head);
    
    insertAtTail(tail, 89);
    print(head);
    
    insertAtAnyPosition(head, tail, 3, 47);
    print(head);
    
    insertAtAnyPosition(head, tail, 1, 90);
    print(head);

    deleteNode(1, head, tail);
    print(head);
    
    deleteNode(3, head, tail);
    print(head);
    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl << endl;
    
    cout << "The length of the node is : " << getLength(head) << endl << endl;
    
    
    print(head);
    deleteNodeByValue(89, head, tail);
    print(head);
    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl << endl;

    return 0;
}