#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    vector <int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(6);
    v.push_back(6);
    v.push_back(7);


    for (int i : v) {
        cout << i << " ";
    } cout << endl;

    cout << "the no. is present or not : " << binary_search(v.begin(), v.end(), 6) << endl << endl;

    // lower bound = the index of the first occurrence in 0-indexing.
    cout << "Lower bound : " << lower_bound(v.begin(), v.end(), 6)-v.begin() << endl;
    // upper bound = the index of the last occurrence in the 1 based indexing.
    cout << "Upper bound : " << upper_bound(v.begin(), v.end(), 6)-v.begin() << endl << endl;



    rotate(v.begin(), v.begin()+2, v.end());
    cout << "After rotate : ";
    for(int i:v) {
        cout << i << " ";
    } cout << endl;


    // introsort = deep sort + insertion sort + quick sort  == Behind the scenes of sort here 
    cout << "After sorting : ";
    sort(v.begin(), v.end());
    for(int i:v) {
        cout << i << " ";
    } cout << endl << endl;



    int a = 3, b = 5;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << endl;

    cout << "Max = " << max(a,b) << endl;
    cout << "Min = " << min(a,b) << endl << endl;

    swap(a,b);
    cout << "After swapping : " << "a = " << a << endl;

    cout << endl;
    string abcd = "abcd";
    reverse(abcd.begin(), abcd.end());
    cout << "reversed string = " << abcd << endl << endl;

    return 0;
}