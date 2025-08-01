// Example of abstraction using abstract class

#include <iostream>
using namespace std;


class Shape {
public :
    // Pure virtual function
    virtual void draw() = 0;

    // Normal function (can have implementation)
    void sayHello() {
        cout << "Hello from Shape!" << endl;
    }
};


// Derived class
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle..." << endl;
    }
};


// Another Derived class
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle..." << endl;
    }
};
    


int main() {

    Shape *s1 = new Circle();
    Shape *s2 = new Rectangle();

    s1 -> draw();        // Output: Drawing Circle...
    s2 -> draw();        // Output: Drawing Rectangle...

    s1 -> sayHello();    // Output: Hello from Shape!

    delete s1;
    delete s2;

    return 0;
}



/*
- You cannot create an object of an abstract class.
- You must override all pure virtual functions in the derived class to make it concrete.
- Abstract classes enable runtime polymorphism and hide complexity from the user.
- At runtime, check the actual type of object and call the correct function.
*/


/*
- So, what does virtual do?
- It enables runtime polymorphism — meaning:
- Even if you're using a pointer/reference to a base class, C++ will dynamically choose the correct function of the derived class at runtime.


In one sentence:
- We use virtual functions when we want different derived classes to have their own versions of a function, and still call them through a common base class pointer or reference.

*/




/*

In C++, an abstract class is a class that cannot be instantiated on its own and is intended to be used as a base class. It typically serves as an interface or a common base for derived classes.
Key Characteristics of Abstract Classes:

--> Contains at least one pure virtual function.
--> Cannot be instantiated directly.
--> Must be inherited and the pure virtual functions must be implemented by derived classes (unless the derived class is also abstract).


*/




/*
In C++: All interfaces are abstract classes, but not all abstract classes are interfaces.
- Interface = abstract class with only pure virtual functions (no implementation).
- Abstract class = can mix pure virtual + normal functions (partial implementation possible).

*/