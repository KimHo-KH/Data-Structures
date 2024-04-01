#include "InsertionSort.h"

// Function to perform insertion sort on an array
// Time complexity: O(n^2) (worst and average case), O(n) (best case for already sorted array)
// Space complexity: O(1) (in-place sorting algorithm)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) { // O(n)
        int key = arr[i]; // O(1)
        int j = i - 1; // O(1)

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        // Time complexity: O(n) (worst and average case), O(1) (best case when array is already sorted)
        // Space complexity: O(1)
        while (j >= 0 && arr[j] > key) { // O(n)
            arr[j + 1] = arr[j]; // O(1)
            --j; // O(1)
        }
        arr[j + 1] = key; // O(1)
    }
}
