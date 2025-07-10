#include <iostream>
#include <queue>
using namespace std;

class CircularQueue{
    private :
    int *arr;
    int front;
    int rear;
    int size;

    public :
    CircularQueue(int size){
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value) {

        // to check whether queue is full
        if ( (front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)) ) {
            cout << "Queue is full ! " << endl;
            return false;
        } 

        // first element needs to be pushed
        else if (front == -1 && rear == -1) {
            front = rear = 0;
        }

        else if (rear == size - 1 && front != 0) {
            rear = 0;   // to maintain the cyclic nature of the queue.
        } 
        
        else {
            // normal flow
            rear++;
        }

        arr[rear] = value;
        return true;
    }


    // Dequeues top element from queue. Returns -1, if the stack is empty, otherwise returns the popped element.
    int dequeue() {

        // to check if the queue is empty!
        if(front == -1) {
            cout << "Queue is empty !" << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        // single element is present
        if (front == rear) {
            front = rear = -1;
        }

        else if (front == size - 1) {
            front = 0;       // to maintain the cyclic nature of the queue.
        } 

        else {
            front++;       // normal flow
        }

        return ans;
    }


    bool isEmpty() {
        return (front == -1);
    }
};

int main() {

    CircularQueue cq(10);

    cq.enqueue(12);
    cq.enqueue(46);
    cq.enqueue(38);
    cq.enqueue(73);
    cq.enqueue(29);
    cq.enqueue(84);

    while(!cq.isEmpty()) {
        int poppedValue = cq.dequeue();
        cout << "The popped value is : " << poppedValue << endl;
    }

    return 0;
}