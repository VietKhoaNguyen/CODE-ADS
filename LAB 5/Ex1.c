#include <stdio.h>
void recursiveInsertionSort(int arr[], int n) {             //Complexity: O(n^2)
    if (n <= 1)
        return;
    recursiveInsertionSort(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    recursiveInsertionSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
/*
function recursiveInsertionSort(arr, n) {
    if (n <= 1) {
        return;
    }
    
    recursiveInsertionSort(arr, n - 1);

    last = arr[n - 1];
    j = n - 2;

    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j = j - 1;
    }
    arr[j + 1] = last;
}

function printArray(arr, n) {
    for (i = 0; i < n; i++) {
        print(arr[i] + " ");
    }
    print("
");
}

arr = [12, 11, 13, 5, 6];
n = arr.length;

print("Original array: 
");
printArray(arr, n);

recursiveInsertionSort(arr, n);

print("Sorted array: 
");
printArray(arr, n);
*/