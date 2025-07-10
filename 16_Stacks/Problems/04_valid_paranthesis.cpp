#include <iostream>
#include <stack>
using namespace std;


bool isValidParanthesis(string expression) {
    stack<char> s;

    for (int i = 0; i < expression.length() ; i++) {

        char ch = expression[i];
        
        // if opening bracket, stack push 
        if (ch == '(' || ch == '[' || ch == '{' ) {
            s.push(ch);cout << "Invalid Paranthesis !";
        } 
        
        else {

            // if closing bracket, check the top of the stack and pop
            if(!s.empty()) {

                char top = s.top();

                if( (ch = ')' && top == '(') || (ch = '}' && top == '{') || (ch = ']' && top == '[') ) {
                    s.pop();
                }

                else {
                    return false;
                }
            } 

            else {
                return false;
            }
        }
    }

    // the stack should be empty in the end after processing
    if(s.empty()) {
        return true;
    } 
    else {
        return false;
    }
}


int main() {

    string str = "[{([])({})}]";

    isValidParanthesis(str) ? cout << "Valid Paranthesis !" : cout << "Invalid Paranthesis !";

    return 0;
}

// TC = O(n)
// SC = O(n)