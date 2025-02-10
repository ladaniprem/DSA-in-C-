/*
Merge Sort Explanation:
----------------------
Time Complexity: O(n log n)
- Worst Case: O(n log n)
- Average Case: O(n log n)
- Best Case: O(n log n)
Why? Because:
- Dividing array takes log n steps
- Merging at each step takes n operations
- So, n × log n = n log n operations
- Always same complexity as it always divides in half!

Space Complexity: O(n)
- Needs extra array of size n for merging
- Not an in-place sorting algorithm
- Uses recursive stack space O(log n)
- Total space = O(n) + O(log n) = O(n)

How it works:
- Like shuffling two sorted decks of cards
- Divide deck into two halves
- Sort each half separately (recursively)
- Merge sorted halves back together
- Like tournament brackets in reverse!

Divide & Conquer Strategy:
1. Divide: Split array into two halves
2. Conquer: Recursively sort the two halves
3. Combine: Merge the sorted halves
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void merge(vector<int>& arr, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> left(n1), right(n2);

    for (int i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void printArray(const vector<int>& arr, const string& message) {
    cout << message;
    for (int num : arr) {
        cout << setw(4) << num;
    }
    cout << endl;
}

int main() {
    int n;  
    cout << "\n=== Merge Sort Implementation ===\n";
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
 
    cout << "\nEnter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    cout << "\n";
    printArray(arr, "\nOriginal Array:  ");
    
    mergeSort(arr, 0, n - 1);
    
    printArray(arr, "Sorted Array:   ");
    cout << "\n";
    
    return 0;
}