#include <stdio.h>
#include <limits.h>

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

// Find the minimum element in the queue and requeue elements except the min
int findMinAndRequeue(Queue* q, int size) {
    int minVal = INT_MAX;
    int minIndex = -1;
    int currentQueue[1000];
    int currentIndex = 0;

    // Traverse the queue to find the minimum value
    for (int i = 0; i < size; i++) {
        int element = dequeue(q);
        if (element < minVal) {
            minVal = element;
            minIndex = i;
        }
        currentQueue[currentIndex++] = element;
    }

    // Requeue all elements except the minimum element
    for (int i = 0; i < size; i++) {
        if (i != minIndex) {
            enqueue(q, currentQueue[i]);
        }
    }

    return minVal;  // Return the minimum value
}

// Selection Sort using queue
void selectionSortQueue(int arr[], int n) {
    Queue q;
    initQueue(&q);

    // Insert all array elements into the queue
    for (int i = 0; i < n; i++) {
        enqueue(&q, arr[i]);
    }

    // Sort the array using selection sort logic
    for (int i = 0; i < n; i++) {
        // Find the minimum element in the queue and place it in the sorted portion of the array
        int minVal = findMinAndRequeue(&q, n - i);
        arr[i] = minVal;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to test Selection Sort
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array: \n");
    printArray(arr, n);

    selectionSortQueue(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
