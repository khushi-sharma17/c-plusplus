#include <iostream>
using namespace std;

// Pass by refernce 
void reverseString(string &str, int i, int j) {

    // Base case
    if(i>j) {
        return;
    }

    swap(str[i++], str[j--]);
    
    // Recursive function
    reverseString(str, i, j);
}


// Optimising this code using one pointer approach
void reverseString(string &str, int i) {
    int n = str.length();

    // Base case
    if(i >= n / 2) {
        return;
    }

    swap(str[i], str[n - i - 1]);

    // Recursive call
    reverseString(str, i + 1);
}


int main() {

    string name;
    getline(cin, name);
    
    reverseString ( name, 0, name.length()-1 );
    cout << name << endl;

    return 0;
}