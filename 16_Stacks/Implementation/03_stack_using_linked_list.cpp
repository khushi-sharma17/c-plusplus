#include <iostream>
using namespace std;


class StackNode {
public:
    int data;
    StackNode* next;

    StackNode(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};


// Stack class managing the stack operations
class Stack {
public:
    StackNode* head;
    StackNode* tail;
    int size;
    int top;

    Stack(int size) {
        head = NULL;
        tail = NULL;
        top = -1;
        this -> size = size;
    }

    void push(int element) {
        if (size - top > 1) {
            StackNode* newNode = new StackNode(element);

            if (head == NULL) {  // empty stack
                head = newNode;
                tail = newNode;
            } else {
                tail -> next = newNode;
                tail = newNode;
            }

            top++;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return;
        }

        // If only one element
        if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
        } 
        
        else {
            // Traverse to second last node
            StackNode* temp = head;
            while (temp -> next != tail) {
                temp = temp -> next;
            }
            delete tail;
            tail = temp;
            tail -> next = NULL;
        }

        top--;
    }


    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        } else {
            return tail->data;
        }
    }


    bool isEmpty() {
        return (top == -1);
    }


    void print() {
        StackNode* temp = head;
        while (temp != NULL) {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};


// Main function
int main() {

    Stack s(10);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout << "Stack after pushing: ";
    s.print();

    s.pop();

    cout << "Stack after popping: ";
    s.print();


    cout << "Peek value: " << s.peek() << endl;

    cout << "Size of the stack is : " << s.size << endl;

    if (s.isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}
