
/*
There are two approaches to implement a stack using queues :
1️⃣ Costly push (make push() slow, pop() fast)
2️⃣ Costly pop (make pop() slow, push() fast)


🌸 Approach 1: Costly Push (Preferred for efficiency in pop)
In this approach:
- We use a single queue.
- When we push, we insert the new element and rotate the rest of the elements behind it.
- This ensures the top is always at the front.
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// class Stack {

//     queue<int> q;
//     int size;
//     int top = -1;

// public :

//     Stack(int size) {
//         this -> size = size;
//     }

//     void StackPush(int x) {

//         if (top == size - 1) {
//             cout << "Stack overflow";
//         }
        
//         q.push(x);
//         int n = q.size();
//         top++;

//         // rotating previous elements behind the new one
//         for (int i = 0; i < n-1 ; i++) {
//             q.push(q.front());
//             q.pop();
//         }
//     }


//     void StackPop() {
//         if(q.empty()) {
//             cout << "Stack underflow!" << endl;
//             return;
//         }
//         q.pop();
//         top--;
//     }


//     int StackTop() {
//         if (q.empty()) {
//             cout << "Stack is empty\n";
//             return -1;
//         }
//         return q.front();
//     }


//     bool isEmpty() {
//         return q.empty();
//     }
// };

// int main() {

//     Stack s(5);
//     s.StackPush(10);
//     s.StackPush(20);
//     s.StackPush(30);

//     cout << "Top element: " << s.StackTop() << endl; // 30

//     s.StackPop();
//     cout << "Top element after pop : " << s.StackTop() << endl; // 20

//     s.StackPop();
//     s.StackPop();
//     s.StackPop(); // Stack underflow

//     return 0;
// }


/*
Time Complexity:
-> push() = O(n)
-> pop() = O(1)
*/












/*

🌸 Approach 2: Costly Pop
In this approach:
- We use two queues (q1 and q2).
- When we pop, we move all elements except the last from q1 to q2.
- The last element in q1 is the top of the stack.

*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Stack {
    queue<int> q1, q2;

public :

    void push(int x) {
        q1.push(x);
    }


    void pop() {

        if (q1.empty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }

        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();       // removing the last element from the queue 1
        swap(q1, q2);       // q2 becomes the main queue
    }


    int top() {

        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topElement = q1.front();
        q1.pop();
        q2.push(topElement);      // putting the last element back

        swap(q1, q2);

        return topElement;
    }


    bool isEmpty() {
        return q1.empty();
    }
};


int main() {

    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl; // 30

    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // 20

    s.pop();
    s.pop();
    s.pop(); // Stack underflow

    return 0;
}


/*
Time Complexity:
-> push() = O(1)
-> pop() = O(n)

🔍 Which one to use?
✅ Costly Push is usually better because pop() is O(1), just like in a normal stack.
*/