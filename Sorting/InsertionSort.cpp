/*
Insertion Sort (Striver's Implementation):
----------------------------------------
Time Complexity: 
- Worst & Average: O(n²)
- Best Case: O(n) when array is sorted
Space Complexity: O(1)

Key Concept:
- Takes elements one by one
- Places them in their correct position
- Like arranging playing cards in hand
*/

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr, int n) {
    for(int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        
        while(j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        
        // Print array after each iteration
        cout << "After iteration " << i << ": ";
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
    
    insertionSort(arr, n);
    
    cout << "\nSorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}