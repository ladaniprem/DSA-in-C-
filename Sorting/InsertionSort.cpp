/*
Insertion Sort Explanation:
--------------------------
Time Complexity: O(n²)
- Worst & Average Case: O(n²) [When array is reverse sorted]
- Best Case: O(n) [When array is already sorted]
Why? Because:
- Outer loop runs 'n' times
- Inner loop can run up to 'n' times
- So, n × n = n² operations in worst case

Space Complexity: O(1)
- Only uses a single extra variable (key)
- Doesn't need extra space as input grows
- "In-Place" sorting algorithm
- Very memory efficient!

How it works:
- Like sorting playing cards in your hand
- Pick one card at a time
- Insert it into its correct position
- Shift other cards to make space
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        cout << "\nPass " << i << " (inserting " << key << "): ";
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    
        for (int k = 0; k < n; k++) {
            cout << setw(4) << arr[k];
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "\n=== Insertion Sort Implementation ===\n";
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    
    cout << "\nEnter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    cout << "\n-----------------------------";
    cout << "\nOriginal Array: ";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << arr[i];
    }
    
    cout << "\n\nSorting Steps:";
    insertionSort(arr);
    
    cout << "-----------------------------";
    cout << "\nSorted Array:  ";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << arr[i];
    }
    cout << "\n-----------------------------\n";
    
    return 0;
}