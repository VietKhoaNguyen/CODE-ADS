#include <stdio.h>
#include <stdlib.h>

#define MAX 1000  // Maximum stack size

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to perform selection sort using a stack
void selectionSortStack(int arr[], int n) {
    int stack[MAX];
    int top = -1;

    // Push all the starting indices onto the stack
    for (int i = 0; i < n; i++) {
        stack[++top] = i;
    }

    // Process the stack
    while (top >= 0) {
        int i = stack[top--];  // Pop index from stack

        // Find the minimum element in the remaining unsorted array
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) {
            swap(&arr[minIndex], &arr[i]);
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
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSortStack(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
