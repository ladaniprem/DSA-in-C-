/*
Selection Sort (Striver's Implementation):
----------------------------------------
Time Complexity: O(n²)
Space Complexity: O(1)

Key Concept:
- Select minimum element and place at beginning
- Maintain sorted and unsorted regions
- Each pass expands sorted region by 1
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void selectionSort(vector<int>& arr, int n) {
    for(int i = 0; i <= n-2; i++) {
        int mini = i;
        for(int j = i; j <= n-1; j++) {
            if(arr[j] < arr[mini]) {
                mini = j;
            }
        }
        // Swap only if minimum element is different
        if(mini != i) {
            int temp = arr[mini];
            arr[mini] = arr[i];
            arr[i] = temp;
        }
        
        // Print current state
        cout << "After iteration " << i+1 << ": ";
        for(int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "\nOriginal array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
    selectionSort(arr, n);
    
    cout << "\nSorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}