#include <stdio.h>
#include <stdlib.h>

#define MAX 1000  // Maximum stack size

// Stack structure to hold indices of elements to be swapped
struct Stack {
    int data[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to push an index onto the stack
void push(struct Stack* stack, int value) {
    if (stack->top < MAX - 1) {
        stack->data[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an index from the stack
int pop(struct Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort using stack
void bubbleSortStack(int arr[], int n) {
    struct Stack stack;
    initStack(&stack);

    // Perform bubble sort
    for (int i = 0; i < n - 1; i++) {
        // Push pairs of adjacent indices onto the stack if they need to be swapped
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                push(&stack, j);  // Push index j to swap with j+1
            }
        }

        // Pop pairs of indices from the stack and swap the elements
        while (stack.top >= 0) {
            int index = pop(&stack);
            swap(&arr[index], &arr[index + 1]);
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSortStack(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
