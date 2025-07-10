#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void insertionSort(int arr[], int n) {
    // Base case
    if (n <= 1) return;

    insertionSort(arr, n - 1);

    int temp = arr[n-1];

    int j = n - 2;

    for( ; j >= 0; j--) {
        if (arr[j] > temp) {
            arr[j+1] = arr[j];
        } else {
            break;
        }
    }

    arr[j+1] = temp;
}


int main() {

    int arr[7] = {2 , 3 , 7 , 1 , 4 , 9 , 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, n);

    cout << "the sorted array is : ";
    for(int i=0; i<n ; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;


    return 0;
}