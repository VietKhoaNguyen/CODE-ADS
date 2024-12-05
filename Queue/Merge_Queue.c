#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

typedef struct {
    int left, right;
} Range;

typedef struct {
    Range queue[1000];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queue* q, Range r) {
    q->queue[++q->rear] = r;
}

Range dequeue(Queue* q) {
    return q->queue[q->front++];
}

int isEmpty(Queue* q) {
    return q->front > q->rear;
}

void mergeSortQueue(int arr[], int n) {
    Queue q;
    initQueue(&q);
    for (int i = 0; i < n; i++) {
        enqueue(&q, (Range){i, i});
    }

    while (q.rear - q.front + 1 > 1) {  
        Range first = dequeue(&q);
        Range second = dequeue(&q);

        merge(arr, first.left, first.right, second.right);

        enqueue(&q, (Range){first.left, second.right});
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array: \n");
    printArray(arr, arr_size);

    mergeSortQueue(arr, arr_size);

    printf("Sorted array: \n");
    printArray(arr, arr_size);

    return 0;
}
