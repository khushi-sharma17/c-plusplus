#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to get the maximum value in an array
int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// A function to do counting sort of arr[] according to the digit represented by exp
void countingSort(vector<int>& arr, int exp) {
    
    int n = arr.size();
    vector<int> output(n); // output array
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that it contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array (stable sort)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to arr[], so that arr[] contains sorted numbers
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main function to implement radix sort
void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);

    // Do counting sort for every digit. Note that instead of passing digit number,
    // exp is passed. exp is 10^i where i is current digit number (1s, 10s, 100s, etc)
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

// Utility function to print an array
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// Example usage
int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "Original array:\n";
    printArray(arr);

    radixSort(arr);

    cout << "\nSorted array:\n";
    printArray(arr);
    return 0;
}


/*
--> Radix Sort is a non-comparative sorting algorithm.
--> It works efficiently for integers and performs best when the number of digits is small.
--> The time complexity is O(nk), where n is the number of elements and k is the number of digits in the maximum number.
*/