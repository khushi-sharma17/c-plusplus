#include <iostream>
using namespace std;


class A;

class B {
    public : 
    void showA(A& obj);
};


class A {
    private : 
    int x = 5;

    public : 
    friend void B :: showA(A& obj);
};


void B :: showA(A& obj) {
    cout << " Value of x : " << obj.x << endl; 
}



int main() {



    return 0;
}