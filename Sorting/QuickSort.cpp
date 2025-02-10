/*
Quick Sort Explanation:
----------------------
Time Complexity: 
- Average Case: O(n log n)
- Worst Case: O(n²) [When array is already sorted]
- Best Case: O(n log n)

Space Complexity: O(log n)
- Uses recursive stack space
- In-place sorting algorithm
- No extra array needed

How it works:
- Choose a pivot element
- Put smaller elements before pivot
- Put larger elements after pivot
- Recursively sort both parts
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void printArray(vector<int>& arr, string message) {
    cout << message;
    for (int num : arr) {
        cout << setw(4) << num;
    }
    cout << endl;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    
    
    cout << "Partition step - Pivot " << pivot << ": ";
    for (int k = low; k <= high; k++) {
        cout << setw(4) << arr[k];
    }
    cout << endl;
    
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "\n=== Quick Sort Implementation ===\n";
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    
    cout << "\nEnter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    cout << "\n-----------------------------";
    printArray(arr, "\nOriginal Array: ");
    
    cout << "\nSorting Steps:\n";
    quickSort(arr, 0, n - 1);
    
    cout << "\n-----------------------------";
    printArray(arr, "\nSorted Array:  ");
    cout << "-----------------------------\n";
    
    return 0;
}