#include <iostream>
using namespace std;

int main () {

    int x;
    cout << "Enter the value of n : ";
    cin >> x;

    int result = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Check for overflow before it happens
            if (result > INT32_MAX / 10 || (result == INT32_MAX / 10 && digit > 7)) {
                return 0;
            }
            if (result < INT32_MIN / 10 || (result == INT32_MIN / 10 && digit < -8)) {
                return 0;
            }

            result = result * 10 + digit;
        }

    cout << "the answer is : "<< result << endl;
    
    return 0;
}