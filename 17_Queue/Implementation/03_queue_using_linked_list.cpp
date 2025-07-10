#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Node {

public :
    int data;
    Node* next;
    
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    // ~Node() {
    //     int value = this -> data;
    //     cout << "Memory deleted for the node : " << value << endl;
    // }
};


class Queue {

public :

    Node* head;
    Node* tail;
    int size;
    int qfront;
    int rear;    

    Queue(int size) {
        qfront = rear = -1;
        this -> size = size;
        head = NULL;
        tail = NULL;
    }


    // Push operation
    void enqueue(int element) {

        // if the queue is full
        if (rear == size - 1) {
            cout << "Queue is full" << endl;
            return;
        } 

        // if the queue is empty
        if (rear == -1) {
            // adding a node
            Node* firstNode = new Node(element);
            head = firstNode;
            tail = firstNode;
            qfront = 0;
        }

        else {
            Node* newNode = new Node(element);
            tail -> next = newNode;
            tail = newNode;
        }

        rear++;
        return;
    }


    // Pop Operation
    int dequeue() {

        // if the queue is empty
        if(rear == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int element = head -> data;

        // if the queue contains only one value
        if (rear == 0) {
            Node* temp = tail;
            delete tail;
            delete head;
        }  

        else {
            Node* temp = head;
            head = head -> next;
            delete temp;
            qfront++;
        }
        return element;
    }


    bool isEmpty() {
        return (rear == -1);
    }

    
    int front() {
        return head -> data;
    }

};


int main() {

    Queue q(10);

    q.enqueue(17);
    q.enqueue(56);
    q.enqueue(39);
    q.enqueue(20);
    q.enqueue(40);

    cout << "Front of queue is : " << q.front() << endl;

    int poppedVal = q.dequeue();
    cout << "The popped value is : " << poppedVal << endl;


    if(q.isEmpty()) {
        cout << "Queue is empty !" << endl;
    } else {
        cout << "Queue is not empty !" << endl;
    }


    cout << "The queue values are : ";
    while(!q.isEmpty()) {
        cout << q.front() << " ";
        q.dequeue();
    }

    return 0;
}