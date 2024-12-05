#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {         // O(n log(n))
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the rightmost element as the pivot
    int i = low - 1;        // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }

    // Swap the pivot element with the element at i+1 (its correct position)
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);  // Return the partitioning index
}

// Recursive QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort the subarrays before and after the partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
/*
function swap(a, b) {
    temp = a
    a = b
    b = temp
}

function partition(arr, low, high) {
    pivot = arr[high]
    i = low - 1

    for j = low to high - 1 {
        if arr[j] <= pivot {
            i++
            swap(arr[i], arr[j])
        }
    }

    swap(arr[i + 1], arr[high])

    return i + 1
}

function quickSort(arr, low, high) {
    if low < high {
        pi = partition(arr, low, high)
        quickSort(arr, low, pi - 1)
        quickSort(arr, pi + 1, high)
    }
}

arr = [64, 34, 25, 12, 22, 11, 90]
n = length(arr)

quickSort(arr, 0, n - 1)

print("Sorted array:")
for i = 0 to n - 1 {
    print(arr[i])
}
*/