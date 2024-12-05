#include <stdio.h>
#include <stdlib.h>

#define MAX 1000  // Maximum stack size

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot element
    int i = low - 1;        // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort using a stack (non-recursive)
void quickSortIterative(int arr[], int low, int high) {
    // Create an auxiliary stack
    int stack[MAX];

    // Initialize the top of the stack
    int top = -1;

    // Push initial values of low and high onto the stack
    stack[++top] = low;
    stack[++top] = high;

    // Keep popping from the stack while it is not empty
    while (top >= 0) {
        // Pop high and low
        high = stack[top--];
        low = stack[top--];

        // Partition the array
        int p = partition(arr, low, high);

        // If there are elements on the left side of the pivot, push left side to stack
        if (p - 1 > low) {
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        // If there are elements on the right side of the pivot, push right side to stack
        if (p + 1 < high) {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to run the program
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSortIterative(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
