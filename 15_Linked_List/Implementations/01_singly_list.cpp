// Linked lists is a type of linear data structure which is a collection of nodes.
// a node contains some data and the address of another node.

/*
Why linked lists ?
--> dynamic data structure (can grow/ shrink the size at run time)
--> no memory wastage.
--> insertion na deletion easy here - no shift needed
--> no continuous storage needed.
*/

/*
Types of linked lists = 
--> singly LL
--> doubly LL
--> circular LL
--> circular doubly LL 
*/

// Insertion at any position in a linked list.



#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;


    // constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }


    // destructor
    ~Node() {
        int value = this -> data;


        // This code recursively deletes all nodes, if you delete one node, it deletes the entire rest of the list!

        // // memory free 
        // if(this -> next != NULL) {
        //     delete next;
        //     this -> next = NULL;
        // }

        cout << "Memory is free for node with data " << value << endl;
    }
};




// by reference of the head, because we want to make changes in the original list and not make a new copy of the original one.
void insertAtHead(Node* &head, int data) {

    // Creating a new node here
    Node *temp = new Node(data);    // in heap

    temp -> next = head;
    head = temp;

}




void insertAtTail(Node* &tail, int data) {
    // Creating a new node here.
    Node *temp = new Node(data);    // in heap

    tail -> next = temp;
    // tail = tail -> next;
    tail = temp;
}




void insertAtPosition(Node* &tail, Node* &head, int position, int data) {

    // inserting at the start 
    if(position == 1) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    // The purpose of subtracting 1 in the condition count < position - 1 is to ensure that the loop stops when count becomes equal to position - 1. This is because, in the context of inserting a node at a specific position, you want to stop at the node just before the desired position so that you can correctly link the new node with the surrounding nodes during the insertion process. 
    while(cnt < position - 1) {
        temp = temp -> next;
        cnt++;
    }

    // inserting at last position 
    // This also updates the position of the tail.
    if(temp -> next == NULL) {
        insertAtTail(tail, data);
        return;
    }

    // Creating a node for the data part
    Node* nodeToInsert = new Node(data);

    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}





// traversing a linked list 
void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }   
    cout << endl;
}






// deleting in a linked list position wise

void deleteNode(int position, Node* &head, Node* &tail) {

    // deleting first or start node 
    if(position == 1) {
        Node* temp = head;
        head = head -> next;

        // freeing the memory of the start node.
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

        if(curr -> next == NULL) {
            tail = prev;
            tail -> next = NULL;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;
    }
}




// deleting in a node value wise
void deleteNodeByValue(int value, Node* &head, Node* &tail) {

    Node* curr = head;
    Node* prev = NULL;
    
    while(curr != NULL) {

        if (curr -> data == value) {

            // If it is the head node
            if (curr == head) {
                head = head -> next;

                // If it is also the only node in the whole list
                if (curr == tail) {
                    tail = NULL;
                }

                Node* temp = curr;
                curr = curr -> next;
                delete temp;
            } 

            // If it is in the middle or at the tail
            else {
                prev -> next = curr -> next;

                if (curr == tail) {
                    tail = prev;
                }
                Node* temp = curr;
                curr = curr -> next;
                delete temp;
            }
            
        } else {
            prev = curr;
            curr = curr -> next;
        }
    }
}




int main() {

    // created a new node
    Node* node1 = new Node(10);       // In heap   // Last element
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;

    // head pointed to node 1 at the starting
    Node* head = node1;
    // tail pointed to node 1 at the starting 
    Node* tail = node1;

    print(head);

    insertAtHead(head, 12);
    print(head);

    insertAtHead(head, 14);
    print(head);

    insertAtTail(tail, 87);
    print(head);

    insertAtPosition(tail, head, 3, 56);
    print(head);

    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl << endl;

    deleteNode(2, head, tail);
    print(head);

    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl << endl;


    deleteNodeByValue(87, head, tail);
    print(head);
    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl << endl;

    return 0;
}