#include <iostream>
using namespace std;


class A {

};


class B {

    public:
    int a;
    int b;

    int add() {
        return a + b;
    }

    // Operator overloaded
    void operator+ (B &obj) {

        int value1 = this -> a;     // Current object
        int value2 = obj.b;     // Input object

        cout << "The Output of the operator overloading is : ((minus) for add): " << value2 - value1 << endl;
        cout << value2 << " --> " << value1 << endl;
    }

    // bracket overloading
    void operator() () {
        cout << endl << "I am a bracket. " << this -> a << endl;
        cout << "I am a bracket. " << this -> b << endl;
    }
};

int main() {
    
    B obj;
    obj.a = 1;
    obj.b = 2;

    cout << "Normal addition : " << obj.add() << endl << endl;


    B obj1, obj2;
    obj1.a = 10;
    obj2.b = 19;

    obj1 + obj2;

    obj1();
    obj2();

    return 0;
}