/*
Bubble Sort (Striver's Implementation):
-------------------------------------
Time Complexity: 
- Worst & Average: O(n²)
- Best Case: O(n) when array is sorted
Space Complexity: O(1)

Key Concept:
- Push maximum element to end by adjacent swaps
- Each iteration fixes last element
- Early termination if no swaps needed
*/

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr, int n) {
    for(int i = n-1; i >= 0; i--) {
        bool didSwap = false;
        for(int j = 0; j <= i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                didSwap = true;
            }
        }
        
        // Print array after each iteration
        cout << "After iteration " << n-i << ": ";
        for(int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
        
        // If no swapping occurred, array is sorted
        if(!didSwap) break;
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
    
    bubbleSort(arr, n);
    
    cout << "\nSorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}