#include <stdio.h>

void insertion_sort_recursive(int arr[], int n, int i) {
    if (i >= n) {
        return; // Base case: end of array
    }

    int j, key;
    int swapped = 0;

    // Forward pass: Inserting elements in their correct position
    for (j = 1; j < n; j++) {
        key = arr[j];
        int k = j - 1;
        while (k >= 0 && arr[k] > key) {
            arr[k + 1] = arr[k];
            swapped = 1;
            k--;
        }
        arr[k + 1] = key;
    }

    // Backward pass: Inserting elements in their correct position
    for (j = n - 2; j >= 0; j--) {
        key = arr[j];
        int k = j + 1;
        while (k < n && arr[k] < key) {
            arr[k - 1] = arr[k];
            swapped = 1;
            k++;
        }
        arr[k - 1] = key;
    }

    // If no swaps occurred, the array is sorted
    if (swapped == 0) {
        return;
    }

    // Recursive call for the next iteration
    insertion_sort_recursive(arr, n, ++i);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertion_sort_recursive(arr, n, 0);

    // Print the sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
/*
function swap(x, y) {
    temp = x
    x = y
    y = temp
}

function Bubble_lvlup(arr, n, i) {
    j = 0
    swapped = 0
    if i < n-1 {
        while j < n-1 {
            if arr[j] > arr[j+1] {
                swap(arr[j], arr[j+1])
                swapped = 1
            }
            j++
        }
    }
    if i < n-1 {
        j = n - 1
        while j > 0 {
            if arr[j] < arr[j-1] {
                swap(arr[j], arr[j-1])
                swapped = 1
            }
            j--
        }
    }
    if swapped == 0 {
        return
    }

    Bubble_lvlup(arr, n, i+1)
}

arr = [64, 34, 25, 12, 22, 11, 90]
n = size of arr / size of arr[0]

Bubble_lvlup(arr, n, 0)

print "Sorted array: "
for i = 0 to n-1 {
    print arr[i], " "
}
print "\n"
*/