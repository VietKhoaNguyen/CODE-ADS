#include <stdio.h>
#include <stdlib.h>
// Merging two halves into a sorted array
void merge(int arr[], int left, int mid, int right) {        // O(n log(n))
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // Copy data into temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0; // Initial index of the first subarray
    j = 0; // Initial index of the second subarray
    k = left; // Initial index of the merged array
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

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free dynamically allocated memory
    free(L);
    free(R);
}

// Recursive merge sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
/*
FUNCTION merge(arr, left, mid, right)
    DECLARE i, j, k
    DECLARE n1 = mid - left + 1
    DECLARE n2 = right - mid
    DECLARE L[n1]
    DECLARE R[n2]

    FOR i = 0 TO n1
        L[i] = arr[left + i]
    ENDFOR

    FOR j = 0 TO n2
        R[j] = arr[mid + 1 + j]
    ENDFOR

    i = 0
    j = 0
    k = left

    WHILE i < n1 AND j < n2
        IF L[i] <= R[j]
            arr[k] = L[i]
            i = i + 1
        ELSE
            arr[k] = R[j]
            j = j + 1
        ENDIF
        k = k + 1
    ENDWHILE

    WHILE i < n1
        arr[k] = L[i]
        i = i + 1
        k = k + 1
    ENDWHILE

    WHILE j < n2
        arr[k] = R[j]
        j = j + 1
        k = k + 1
    ENDWHILE
ENDFUNCTION

FUNCTION mergeSort(arr, left, right)
    IF left < right
        DECLARE mid = left + (right - left) / 2
        mergeSort(arr, left, mid)
        mergeSort(arr, mid + 1, right)
        merge(arr, left, mid, right)
    ENDIF
ENDFUNCTION

FUNCTION main()
    DECLARE arr[] = {64, 34, 25, 12, 22, 11, 90}
    DECLARE n = LENGTH(arr)

    mergeSort(arr, 0, n - 1)

    OUTPUT "Sorted array: "
    FOR i = 0 TO n
        OUTPUT arr[i] + " "
    ENDFOR
    OUTPUT ""
ENDFUNCTION
*/