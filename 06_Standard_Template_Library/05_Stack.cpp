// last in = first out (concept)

#include <iostream>
#include <stack>
using namespace std;

int main() { 

    stack <string> s;
    s.push("khushi");
    s.push("kumari");
    s.push("gupta");
    s.push("singh");
    s.push("raizada");

    cout << "Top element : " << s.top() << endl;
    s.pop();
    cout << "Top element : " << s.top() << endl;
    
    cout << "Size of stack : " << s.size() << endl;
    cout << "Empty or not = " << s.empty() << endl << endl;
    


    stack <string> t;
    t.push("Arnav");
    t.push("singh");
    
    s.swap(t);
    cout << "Top element : " << s.top() << endl << endl;


    return 0;
}