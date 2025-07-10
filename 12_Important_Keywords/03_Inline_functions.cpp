// Inline functions are used to reduce the function calls overhead.

#include <iostream>
using namespace std;

// In inline function, wherever there is a function call , it gets replaced with the function body.
// Inline function can only be executed for one line function body, for 2-3 lines the compiler may or may not work for it, for more than three lines, it will never work.
// It's a request to the compiler, not a command.

inline int getMax(int &x, int &y) {
    return (x > y) ? x : y;
}

void func(int a, int b) {
    a++;
    b++;
    cout << a << " " << b << endl << endl;
}



int main() {

    int a = 4, b = 5;
    func(a, b);


    int x = 1, y = 2;
    int ans = 0;
    ans = getMax(x , y);
    cout << ans << endl;


    x += 3;
    y += 1;
    ans = getMax(x , y);
    cout << ans << endl;

    return 0;
}

/*
Advantage of inline function :
--> no extra memory usage.
--> no function call overhead.
*/