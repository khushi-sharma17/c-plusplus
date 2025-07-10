#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Node {
    public : 
    int data;
    Node* next;
    Node* random_ptr;

    Node (int data) {
        this -> data = data;
        this -> next = NULL;
        this -> random_ptr = NULL;
    }
};


Node* insertAtTail(Node* &head, Node* &tail, int data) {

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

    return tail;
}




void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}




// Approach 1 --> unordered_map

// TC = O(n) and SC = O(n)
// Node *copyList(Node *head) {

//     // 1.) Creating a clone linked list
//     Node* cloneHead = NULL;
//     Node* cloneTail = NULL;

//     Node* temp = head;

//     while (temp != NULL) {
//         insertAtTail(cloneHead, cloneTail, temp -> data);
//         temp = temp -> next;
//     }


//     // 2.) Creating an unordered map
//     unordered_map<Node*, Node*> oldToNewNode_Mapping;

//     Node* originalNode = head;
//     Node* cloneNode = cloneHead;


//     while (originalNode != NULL && cloneNode != NULL) {
//         oldToNewNode_Mapping[originalNode] = cloneNode;
//         originalNode = originalNode -> next;
//         cloneNode = cloneNode -> next;
//     }


//     originalNode = head;
//     cloneNode = cloneHead;

//     // 3.) Copying the random pointers in the cloned linked list 
//     while(originalNode != NULL) {
//         cloneNode -> random_ptr = oldToNewNode_Mapping[originalNode -> random_ptr];
//         originalNode = originalNode -> next;
//         cloneNode = cloneNode -> next;
//     }

//     return cloneHead;
// }






// Approach 2 --> changing the links

// TC = O(n) and SC = O(1)
Node *copyList(Node *head) {

    // 1.) Creating a clone linked list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while (temp != NULL) {
        insertAtTail(cloneHead, cloneTail, temp -> data);
        temp = temp -> next;
    }


    // 2.) Adding cloneNodes in between Original List
    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL) {
        // for original Node
        Node* next = originalNode -> next;
        originalNode -> next = cloneNode;
        originalNode = next;

        // for clone Node
        next = cloneNode -> next;
        cloneNode -> next = originalNode;
        cloneNode = next;
    }


    // 3.) Copy Random Pointer
    temp = head;

    while(temp != NULL) {

        if (temp -> next != NULL) {
            temp -> next -> random_ptr = temp -> random_ptr ?  temp -> random_ptr -> next : temp -> random_ptr;

            // if ( temp -> random_ptr != NULL) {
            //     temp -> next -> random_ptr = temp -> random_ptr -> next;
            // } else {
            //     temp -> next = temp -> random_ptr;
            // }
        }

        temp = temp -> next -> next;
    }


    // 4.) revert changes done in step 2.
    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL) {
        // for original Node
        originalNode -> next = cloneNode -> next;
        originalNode = originalNode -> next;

        // for clone Node
        if (originalNode != NULL) {
            cloneNode -> next = originalNode -> next;
        }
        cloneNode = cloneNode -> next;
    }


    // 5.) return answer
    return cloneHead;

}



int main() {


    Node* head = NULL;
    Node* tail = NULL;

    Node* node1 = insertAtTail(head, tail, 1);
    Node* node2 = insertAtTail(head, tail, 2);
    Node* node3 = insertAtTail(head, tail, 3);
    Node* node4 = insertAtTail(head, tail, 4);
    Node* node5 = insertAtTail(head, tail, 5);


    node1 -> random_ptr = node3;
    node3 -> random_ptr = node5;
    node2 -> random_ptr = node1;
    node4 -> random_ptr = node3;
    node5 -> random_ptr = node2;

    print(head);


    Node* cloneList = copyList(head);
    print(cloneList);
    
    // cout << cloneList -> random_ptr -> data;    


    return 0;
}