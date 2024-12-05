#include <stdio.h>
void Bubble(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    int swapped;

    do {
        swapped = 0;
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break; 
        }

        swapped = 0;
        end--;

        for (int i = end; i > start; i--) {
            if (arr[i] < arr[i - 1]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swapped = 1;
            }
        }
        start++;

    } while (swapped);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 1, 4, 2, 8, 0, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);
    Bubble(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
