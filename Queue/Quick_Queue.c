#include <stdio.h>
#include <stdlib.h>

// Structure for storing ranges (subarrays) in the queue
typedef struct {
    int low, high;
} Range;

// Queue structure
typedef struct {
    Range queue[1000];
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

// Enqueue a range
void enqueue(Queue* q, Range r) {
    q->queue[++q->rear] = r;
}

// Dequeue a range
Range dequeue(Queue* q) {
    return q->queue[q->front++];
}

// Check if queue is empty
int isEmpty(Queue* q) {
    return q->front > q->rear;
}

// Swap function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function used in Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as pivot
    int i = low - 1;        // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;  // Return the partition index
}

// Iterative Quick Sort using queue
void quickSortQueue(int arr[], int n) {
    Queue q;
    initQueue(&q);

    // Enqueue the initial range of the entire array
    enqueue(&q, (Range){0, n - 1});

    // Process the queue while it is not empty
    while (!isEmpty(&q)) {
        Range r = dequeue(&q);
        int low = r.low;
        int high = r.high;

        // If the subarray has more than one element, partition it
        if (low < high) {
            int pi = partition(arr, low, high);

            // Enqueue the left subarray
            if (pi - 1 > low) {
                enqueue(&q, (Range){low, pi - 1});
            }

            // Enqueue the right subarray
            if (pi + 1 < high) {
                enqueue(&q, (Range){pi + 1, high});
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to test Quick Sort
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array: \n");
    printArray(arr, n);

    quickSortQueue(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
