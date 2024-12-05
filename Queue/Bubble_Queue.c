#include <stdio.h>
#include <stdlib.h>

// Queue structure
typedef struct {
    int queue[1000];
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

// Enqueue an element
void enqueue(Queue* q, int value) {
    q->queue[++q->rear] = value;
}

// Dequeue an element
int dequeue(Queue* q) {
    return q->queue[q->front++];
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front > q->rear;
}

// Function to perform bubble sort using a queue
void bubbleSortQueue(int arr[], int n) {
    Queue q;
    initQueue(&q);

    // Insert all array elements into the queue
    for (int i = 0; i < n; i++) {
        enqueue(&q, arr[i]);
    }

    // Perform bubble sort
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        int tempQueue[1000];
        int tempIndex = 0;
        int previous = dequeue(&q);

        // Compare adjacent elements
        for (int j = 1; j < n - i; j++) {
            int current = dequeue(&q);

            if (previous > current) {
                // Swap elements
                int temp = previous;
                previous = current;
                current = temp;
                swapped = 1;
            }

            // Enqueue the smaller (or equal) element first, followed by the larger one
            tempQueue[tempIndex++] = previous;
            previous = current;
        }
        // Enqueue the last element
        tempQueue[tempIndex++] = previous;

        // Refill the queue with the partially sorted elements
        for (int j = 0; j < tempIndex; j++) {
            enqueue(&q, tempQueue[j]);
        }

        // If no elements were swapped, the array is already sorted
        if (swapped == 0)
            break;
    }

    // Copy sorted elements back to the array
    for (int i = 0; i < n; i++) {
        arr[i] = dequeue(&q);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to test the bubble sort
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array: \n");
    printArray(arr, n);

    bubbleSortQueue(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
