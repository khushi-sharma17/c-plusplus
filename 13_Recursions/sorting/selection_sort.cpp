#include <iostream>
using namespace std;


void selectionSort(int arr[], int n) {

    if (n == 0 || n == 1) return;

    int minIndex = 0;

    for(int j = 1; j<n ; j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }
    swap(arr[minIndex], arr[0]);

    selectionSort(arr + 1, n - 1);

}


int main() {
    
    int arr[6] = {2 , 1 , 5 , 3 , 9 , 6};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);

    cout << "The sorted array is : " ;
    for(int i=0; i<n ; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;

    return 0;
}