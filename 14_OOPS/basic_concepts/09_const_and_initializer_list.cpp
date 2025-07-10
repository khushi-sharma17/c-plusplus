#include <iostream>
using namespace std;

class MyClass {
    public : 
    int value;

    const int x;

    MyClass(int v, int newx): value(v), x(newx) {}
    

    /*
        What is a Constructor Initializer List?
        It's a way to initialize data members of a class before the constructor body runs.


        - MyClass(int v) is the constructor.
        - : value(v) is the member initializer list → it initializes "value" with v.
        - This happens before the constructor body {} is executed.

        
        Why Use Initializer List?
        - More Efficient: For built-in types like int, both initializer list and assignment work similarly.
        But for objects or constants, initializer list is required or preferred.
        - Mandatory for const and reference members:

        Test(int val) : x(val) {}  // ✅ OK
        // Test(int val) { x = val; } ❌ Error: const can't be assigned
    */

    int getValue() const {      // const function
        return value;
    }

    /*
    getValue() is a const function → it does not change the object’s state.
    You can call it on both const and non-const objects.
    */

    void setValue(int v) {
        value = v;
    }
};

int main() {

    const MyClass obj(10, 90);  // const object
    // obj.setValue(20);       // Error!, Cannot call non const function on const object.
    obj.getValue();

    return 0;
}


/*
const MyClass obj(10); → This creates a constant object, so you can only call const member functions on it.
You cannot modify its data members (unless they are marked mutable).
*/



/*
1. const in Object Creation
When creating an object, you can declare it as const to make sure that it cannot be modified after it's created.


2. const in Member Functions
If a function does not modify any member variables of the object, it should be declared as const for safety and clarity.



3. const with Pointers and Parameters

🔹 Pointer to const:
const int* ptr = &x;  // You can't modify *ptr, i.e the value

🔹 const Pointer:
int* const ptr = &x;  // You can't change ptr, but can modify *ptr, i.e. the value

🔹 const parameter:

void display(const string& name) {
    // name cannot be modified inside the function
}





Summary Table:

Usage	                            Meaning

const int x = 5;	                x is a constant integer
const MyClass obj;	                obj is a constant object
int getValue() const;	            Function doesn't modify object’s data
void func(const T& t);	            Function can't modify the parameter t
const int* ptr;	                    Pointer to constant integer
int* const ptr;	                    Constant pointer to an integer

*/






/*

Syntax	                Action

: value(v)	            Initializes value with v before constructor body
value = v;	            Assigns v to value after default initialization
Required for	        const, reference members
Recommended for	        Efficiency and clarity

*/