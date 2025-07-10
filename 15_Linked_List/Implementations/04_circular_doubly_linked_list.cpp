
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

    ~Node() {
        int value = this -> data;

        // if(this -> next != NULL) {
        //     delete next;
        //     this -> next = NULL;
        // }
        cout << "Memory is free for node with data " << value << endl;
    }
};



void InsertNode(Node* &tail, int element, int data) {

    // if the list is empty
    if (tail == NULL) {
        Node* temp = new Node(data);
        temp -> next = temp;
        temp -> next -> prev = temp;
        tail = temp;
    }

    else {

        Node* curr = tail;

        while(curr -> data != element) {
            curr = curr -> next;
        }

        Node* nodeToInsert = new Node(data);
        nodeToInsert -> next = curr -> next;
        curr -> next -> prev = nodeToInsert;
        curr -> next = nodeToInsert;
        nodeToInsert -> prev = curr;
        tail = nodeToInsert -> next;
    }
}



void print(Node* tail) {

    Node* temp = tail;
    
    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while (tail != temp);

    cout << endl;
}



int getSize(Node* tail) {

    Node* temp = tail;

    if (tail == NULL) {
        cout << "List is empty!" << endl;
        return 0;
    }

    int len = 0;
    
    do {
        tail = tail -> next;
        len++;
    } while (tail != temp);

    return len;
}


void deleteNode(Node* &tail, int element) {
    // if the list is already empty
    if (tail == NULL) {
        cout << "List is empty!" << endl;
        return;
    } 

    Node* prev = NULL;
    Node* curr = tail;
    
    // if the list contains only one value
    if (curr -> next == tail && curr -> data == element) {
        delete tail;
        return;
    }

    while (curr -> data != element) {
        prev = curr;
        curr = curr -> next;
    }

    prev -> next = curr -> next;
    curr -> next -> prev = prev;
    curr -> next = NULL;
    delete curr;
}


int main() {

    Node* tail = NULL;

    // here, the element value doesn't matter, coz, the list is empty at the start.
    InsertNode(tail, 6, 3);
    cout << "tail : " << tail -> data << endl << endl;
    print(tail);

    InsertNode(tail, 3, 5);
    print(tail);

    InsertNode(tail, 5, 7);
    print(tail);

    InsertNode(tail, 7, 9);
    print(tail);

    InsertNode(tail, 5, 6);
    cout << "tail : " << tail -> data << endl << endl;
    print(tail);

    deleteNode(tail, 3);
    cout << "tail : " << tail -> data << endl << endl;
    print(tail);

    deleteNode(tail, 5);
    cout << "tail : " << tail -> data << endl << endl;
    print(tail);


    // cout << sizeof(tail) << endl;

    cout << "The size of the Linked list is : " << getSize(tail);


    return 0;
}