#include <iostream>
using namespace std;

int factorial(int n) {

    if(n == 0) {        // Base case, if it is not there, there would be segmentation fault and ultimately stack overflow.
        return 1;
    }
    
    // recursive relation
    return (n * factorial(n-1));   
    
}

int main() {

    int n;
    cout << "Enter the value of N : ";
    cin >> n;

    int ans = factorial(n);

    cout << ans << endl;

    return 0;
}

// When a function calls itself directly or indirectly is called recursion.
// Recursion = base case and recursive relation and procession.
// base case and the recursive relation is the mandatory conditions where as the processing part is the optional parameter.

// Tail recursion, if the recursive relation is below the processing part.
// Head recursion, if the recursive relation is above the processing part.
// return is mandatory in base case.
// Recursion tree