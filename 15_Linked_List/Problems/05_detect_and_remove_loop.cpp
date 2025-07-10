// Floyd's cycle detection algorithm

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



void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);

    tail -> next = temp;
    tail = temp;
}



void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}




// detecting whether a loop is present or not 
Node* floyd_detection(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            // This returned 'slow' node doesn't guarantee that the returned node will be the beginning part of the loop.
            cout << "Loop present at : " << slow -> data << endl;
            return slow;
        }
    }

    return NULL;
}



// for constant space, otherwise use cycle detection via map which uses O(n)
Node* getStartingNode(Node* head) {

    if(head == NULL) {
        return NULL;
    }

    Node* intersection = floyd_detection(head);
    if(intersection == NULL) {
        return NULL;
    }

    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;
}





// removing the loop
void removeLoop(Node* head) {

    if(head == NULL) {
        return;
    }

    Node* start_of_loop = getStartingNode(head);
    if(start_of_loop == NULL) {
        return;
    }

    Node* temp = start_of_loop;

    while(temp -> next != start_of_loop) {
        temp = temp -> next;
    }

    temp -> next = NULL;

}




int main() {

    Node* node1 = new Node(5);

    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 4);
    insertAtTail(tail, 3);
    insertAtTail(tail, 7);
    insertAtTail(tail, 9);
    insertAtTail(tail, 2);

    print(head);

    // generating a loop
    tail -> next = head -> next;

    if(floyd_detection(head) != NULL) {
        cout << "Loop is present." << endl << endl;
    } else {
        cout << "Loop is not present" << endl << endl;
    }

    cout << "The starting node of the loop is : " << getStartingNode(head) -> data << endl << endl;

    // removing the loop
    removeLoop(head);
    print(head);

    return 0;
}

// T.C. = O(n)
// S.C. = O(1)