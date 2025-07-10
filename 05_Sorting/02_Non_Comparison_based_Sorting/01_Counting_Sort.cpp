#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr) {
    
    if (arr.empty()) return;

    // Step 1: Find the maximum and minimum elements
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());

    // Step 2: Create a count array to store the count of each unique element
    int range = maxVal - minVal + 1;
    vector<int> count(range, 0);

    // Step 3: Store the count of each element
    for (int num : arr)
        count[num - minVal]++;

    // Step 4: Modify the count array by adding previous counts (cumulative)
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // Step 5: Build the output array
    vector<int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        int index = arr[i] - minVal;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // Step 6: Copy sorted elements back to original array
    arr = output;
}

// Helper function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    cout << "Original array:\n";
    printArray(arr);

    countingSort(arr);

    cout << "\nSorted array:\n";
    printArray(arr);

    return 0;
}
