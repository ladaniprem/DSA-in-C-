/*
Bubble Sort Explanation:
------------------------
Time Complexity: O(n²) 
- Worst & Average Case: O(n²) [When array is reverse sorted]
- Best Case: O(n) [When array is already sorted]
Why? Because:
- Outer loop runs 'n' times
- Inner loop runs 'n' times for each outer loop
- So, n × n = n² operations

Space Complexity: O(1)
- Only uses a single extra variable for swapping
- Doesn't need any extra space that grows with input size
- Called "In-Place" sorting algorithm

How it works:
- Repeatedly steps through the list
- Compares adjacent elements
- Swaps them if they are in wrong order
- Like bubbles floating up to surface!
*/

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Early termination if array is already sorted
        if (!swapped) break;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    cout << "\nOriginal array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    bubbleSort(arr);
    
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
