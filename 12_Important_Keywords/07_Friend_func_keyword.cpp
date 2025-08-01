// friend class example
#include <iostream>
using namespace std;

class B; // Forward declaration

class A {
private:
    int data;

public:
    A() : data(5) {}
    friend class B; // B can access private members of A
};

class B {
public:
    void show(A& a) {
        cout << "Data from A: " << a.data << endl;
    }
};

int main() {
    A obj;
    B objB;
    objB.show(obj); // Accessing A's private data!
}


// Friend functions are global functions and Gives access to private/protected members to functions or classes





// friend in a method example
// #include <iostream>
// using namespace std;

// class Box {
// private:
//     int width;

// public:
//     Box() : width(0) {}

//     // Declare friend function
//     friend void setWidth(Box& b, int w);
// };

// // Friend function definition
// void setWidth(Box& b, int w) {
//     b.width = w; // can access private member of the box class
// }

// int main() {
//     Box b;
//     setWidth(b, 10);
//     // Can't print width directly without making another method, just know it's set here for right now. If you wanna print the value, make a getter for it
//     return 0;
// }