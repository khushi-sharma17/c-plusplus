
/*

There are two approaches to implement a queue using stacks :
1️⃣ Costly enqueue (push) – make enqueue() costly, dequeue() fast.
2️⃣ Costly dequeue (pop) – make dequeue() costly, enqueue() fast.


🌸 Approach 1: Costly Enqueue (Push)
In this approach:
- We use two stacks (s1 and s2).
- When we enqueue, we reverse elements from s1 to s2, push new element in s1, then put everything back from s2 to s1.
- This way, the front of the queue is always on top of s1.

*/


#include <iostream>
#include <stack>
using namespace std;


// class Queue {
//     stack<int> s1, s2;
    
// public :
//     void enqueue(int element) {
//         if(!s1.empty() && !s2.empty()) {
//             cout << "The queue is full." << endl;
//             return;
//         }

//         // Moving all the elements from s1 to s2
//         while(!s1.empty()) {
//             s2.push(s1.top());
//             s1.pop();
//         }

//         s1.push(element);   // pushing the element onto the first stack

//         // reversing back all the elements again into the stack one
//         while(!s2.empty()) {
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }


//     void dequeue() {
//         if(s1.empty() && s2.empty()) {
//             cout << "The queue is empty or Queue underflow" << endl;
//         }
//         s1.pop();
//     }


//     int front() {
//         if (s1.empty()) {
//             cout << "Queue is empty\n";
//             return -1;
//         }
//         return s1.top();
//     }


//     bool empty() {
//         return s1.empty();
//     }
// };


// int main() {

//     Queue q;
//     q.enqueue(10);
//     q.enqueue(20);
//     q.enqueue(30);

//     cout << "Front element: " << q.front() << endl; // 10

//     q.dequeue();
//     cout << "Front element after dequeue: " << q.front() << endl; // 20

//     q.dequeue();
//     q.dequeue();
//     q.dequeue(); // Queue underflow

//     return 0;
// }



// Time Complexity :=
// enqueue() = O(n)
// dequeue() = O(1)












/*
🌸 Approach 2: Costly Dequeue (Pop)
In this approach:
- We use two stacks: s1 for enqueue, s2 for dequeue.
- For enqueue, we simply push to s1.
- For dequeue, if s2 is empty, we move all elements from s1 to s2 (reversing them). Then pop from s2.
*/


#include <iostream>
#include <stack>
using namespace std;


class Queue {
    stack<int> s1, s2;

public :
    void enqueue(int x) {
        s1.push(x);
    }


    void dequeue() {

        if (s1.empty() && s2.empty()) {
            cout << "Queue underflow\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }


    int front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }


    bool empty() {
        return s1.empty() && s2.empty();
    }
};


int main() {

    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl; // 10

    q.dequeue();
    cout << "Front element after dequeue: " << q.front() << endl; // 20

    q.dequeue();
    q.dequeue();
    q.dequeue(); // Queue underflow

    return 0;
}

/*
Time Complexity :
- enqueue() = O(1)
- dequeue() = Amortized O(1) (worst case O(n) only when s2 is empty)


Ques.) 🌸 Which one is better?
- ✅ Costly Dequeue is more efficient for most cases because enqueue is always O(1), and dequeue is O(1) amortized.



Ques.) 🌸 What does "amortized" mean?
Amortized means that the average time per operation is small, even though some individual operations may take longer.
In simple words:
- Sometimes, an operation may take longer (like O(n)).
- But overall, when we look at a series of operations, the average time per operation is much smaller (like O(1)).
*/