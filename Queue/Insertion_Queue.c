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

// Check if queue is empty
int isEmpty(Queue* q) {
    return q->front > q->rear;
}

// Peek at the front element without dequeueing
int front(Queue* q) {
    return q->queue[q->front];
}

// Function for insertion sort using a queue
void insertionSortQueue(int arr[], int n) {
    Queue q;
    initQueue(&q);

    // Insert the first element into the queue
    enqueue(&q, arr[0]);

    // Process the rest of the array
    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int tempQueue[1000];
        int tempIndex = 0;

        // Dequeue elements until we find the right spot to insert 'current'
        while (!isEmpty(&q) && front(&q) < current) {
            tempQueue[tempIndex++] = dequeue(&q);
        }

        // Insert the current element in its correct position
        tempQueue[tempIndex++] = current;

        // Enqueue the remaining elements
        while (!isEmpty(&q)) {
            tempQueue[tempIndex++] = dequeue(&q);
        }

        // Enqueue everything back into the main queue
        for (int j = 0; j < tempIndex; j++) {
            enqueue(&q, tempQueue[j]);
        }
    }

    // Copy the sorted elements from the queue back to the array
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

// Main function to test the insertion sort
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array: \n");
    printArray(arr, n);

    insertionSortQueue(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
