#include <iostream>
using namespace std;

/*
Symbol Table is an important data structure created and maintained by 
the compiler in order to keep track of semantics of variables i.e. it 
stores information about the scope and binding information about names, 
information about instances of various entities such as variable and 
function names, classes, objects, etc.
*/

int main() {
    int num = 5;
    cout << num << endl;
    
    // Address of operator is (&)
    cout << "The address of num is : " << &num << endl << endl;

    // Pointer stores the address.      
    // (*) = dereference operator.
    int *ptr = &num; 
    cout << "Value is : " << *ptr << endl;
    cout << "address is : " << ptr << endl << endl;

    // The pointer stores the address, so it's size value is always gonna be 8 or, either 4 depending on the system.
    // so, then why my pointer size is coming as 4 ?

    cout << "Size of integer is : " << sizeof(num) << endl;
    cout << "Size of pointer is : " << sizeof(ptr) << endl << endl;

    // Pointer to int is created and pointing to some garbage value 
    // int *p;      // bad practice , risky one 
    // cout << *p << endl;

    // instead do this
    // int *p = 0;     // Null pointer, Should be segmentation fault

    
    int i = 5;

    int *r = &i; 
    cout << "Vale of r is : " << *r << endl;
    cout << "address is : " << r << endl << endl;


    // Pointer (q) to int is created and pointing to some garbage value 
    int *q = 0;    
    q = &i;
    cout << "Value of q is : " << *q << endl;
    cout << "address is : " << q << endl << endl;

    
    int value = 10;
    int *pointer = &value;
    (*pointer)++;
    cout << value << endl;
    cout << *pointer << endl << endl;


    // Copying a pointer in another pointer
    int *copy_ptr = pointer;
    cout << *copy_ptr << " -> " << *pointer << endl;
    cout << copy_ptr << " -> " << pointer << endl << endl;


    return 0;
}