#include <iostream>
using namespace std;

// Differences in int arr and char ch 

int main() {

    int arr[5] = {1,2,3,4,5};
    char ch[7] = "khushi";      // size should be 7 as null character would also get inserted in the end.


    cout << "1st case = " << endl;
    cout << arr << endl;    // Address got printed for the first index
    cout << ch << endl << endl;     // content gets printed

    // cout behaviour is different here in both the cases for int arr and char ch.
    // different implementation for both of them.



    cout << "2nd case = " << endl;

    int *ptr = &arr[0];     // arr, &arr
    cout << ptr << endl;     // int array will print the address of the pointer for the first index in this case

    char *c = &ch[0];
    cout << c << endl << endl;      // char array will print the content of the array.




    cout << "3rd case = " << endl;
    char temp = 'l';
    char *p = &temp;
   
    cout << p << endl;        //  here the values get stored and printed until null character doesn't appear to the cout.



    char character[6] = "pqrst"; 
    char *pointer = "pqrst";        // Not to be done, as it is a risky process.
    cout << pointer << endl;

    return 0;
}