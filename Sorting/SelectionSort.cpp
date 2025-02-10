/*
Selection Sort Explanation:
--------------------------
Time Complexity: O(n²)
- Worst & Average Case: O(n²) [Always takes same time]
- Best Case: O(n²) [Even if array is sorted]
Why? Because:
- Outer loop runs 'n' times
- Inner loop runs 'n' times for each outer loop
- Always needs to find minimum element
- So, n × n = n² operations

Space Complexity: O(1)
- Only uses a single extra variable for swapping
- Doesn't need extra space as input grows
- "In-Place" sorting algorithm
- Uses less memory writes than bubble sort

How it works:
- Divides array into sorted and unsorted parts
- Finds minimum element from unsorted part
- Puts it at the beginning of unsorted part
- Like picking smallest card and placing in order!
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n-1; i++) {
       
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        

        if (min_idx != i) {
            swap(arr[min_idx], arr[i]);
        }
        
      
        cout << "Pass " << i+1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << setw(4) << arr[k];
        }
        cout << endl;
    }
}

int main() {
    int n;

    cout << "\n=== Selection Sort Implementation ===\n";
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    

    cout << "\nEnter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    cout << "\n";
    cout << "\nOriginal Array: ";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << arr[i];
    }
    cout << "\n\nSorting Steps:\n";
    selectionSort(arr);
    cout << "\n";
    cout << "\nFinal Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << arr[i];
    }
    cout << "\n-----------------------------\n";
    
    return 0;
}

