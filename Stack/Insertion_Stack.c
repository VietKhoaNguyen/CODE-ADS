#include <stdio.h>
#include <stdlib.h>

#define MAX 1000  // Maximum stack size

// Stack structure to hold elements to be sorted
struct Stack {
    int data[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (stack->top < MAX - 1) {
        stack->data[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

// Function to perform insertion sort using a stack
void insertionSortStack(int arr[], int n) {
    struct Stack stack;
    initStack(&stack);

    // Push all the elements of the array onto the stack
    for (int i = 0; i < n; i++) {
        push(&stack, arr[i]);
    }

    // Process each element from the stack and insert it into its correct position
    int sorted[MAX];  // To store the sorted elements
    int sortedSize = 0;

    while (stack.top >= 0) {
        int value = pop(&stack);

        // Insert value into the sorted array in the correct position
        int j = sortedSize - 1;
        while (j >= 0 && sorted[j] > value) {
            sorted[j + 1] = sorted[j];
            j--;
        }
        sorted[j + 1] = value;
        sortedSize++;
    }

    // Copy the sorted array back into the original array
    for (int i = 0; i < sortedSize; i++) {
        arr[i] = sorted[i];
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
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSortStack(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
