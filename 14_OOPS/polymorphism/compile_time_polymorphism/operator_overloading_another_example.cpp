#include <iostream>
using namespace std;

class Complex {

    public :
    int real;
    int imag;

    // default 
    Complex() { 
        this -> real = 0;
        this -> imag = 0;   
    }

    // parameterized
    Complex(int real, int imag) {
        this -> real = real;
        this -> imag = imag; 
    }


    void print_number() {
        cout << this -> real << " + " << this -> imag << "i\n" << endl;
    }

    
    // Complex sum(Complex &obj) {

    // }



    

    Complex operator+(Complex &c) {

        // Complex temp(this -> real + c.real, this -> imag + c.imag);

        // temp.real = this -> real + c.real;
        // temp.imag = this -> imag + c.imag;

        return Complex(this -> real + c.real, this -> imag + c.imag);
    }





    Complex operator+ (int increment) {

        // Complex temp(this -> real + increment, this -> imag + increment);

        // temp.real = this -> real + increment;
        // temp.imag = this -> imag + increment;

        return Complex(this -> real + increment, this -> imag + increment);

    }



    Complex add(int i) {
        return Complex(this -> real + i, this -> imag + i);
    }


    // prefix
    Complex operator ++() {
        // Complex temp;
        // temp.real = ++this -> real;
        // temp.imag = ++this -> imag;
        // return temp;

        return Complex(++this -> real, ++this -> imag);
    }


    // postfix
    Complex operator ++(int) {
        return Complex(this -> real++, this -> imag++);
    }

};


void playing_with_complex_numbers() {

    Complex c1(2, 4);
    Complex c2(3, 2);
    Complex c3 = c1 + 5;        // c1.sum(c2)

    cout << "The sum is : ";
    c3.print_number();


    Complex c6(5, 4);

    Complex c4 = c1 + c6 + c2;
    c4.print_number();

    c1.print_number();
    c2.print_number();

   

    int i=2;
    Complex c5 = c3.add(i);

    

    Complex c7 = ++c6;
    Complex c8 = c7++;

    c7.print_number();
    c8.print_number();

    // int ans = ++obj;
    // cout << ans << endl;
    
    
}


int main() {

    playing_with_complex_numbers();

    return 0;
}


// 127 parameters allowed in C++


// ternary, scope resolution, sizeof and dot operator cannot be operator overloaded.