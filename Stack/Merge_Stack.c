#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct {                //Complexity:O(n log(n))
    int left;
    int mid;
    int right;
} Subarray;

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

void mergeSort(int arr[], int n) {
    Subarray stack[MAX];
    int top = -1;

    stack[++top] = (Subarray){0, (n - 1) / 2, n - 1};

    Subarray mergeStack[MAX];
    int mergeTop = -1;

    while (top >= 0) {
        Subarray current = stack[top--];

        if (current.left < current.right) {
            int mid = (current.left + current.right) / 2;

            stack[++top] = (Subarray){current.left, (current.left + mid) / 2, mid};
            stack[++top] = (Subarray){mid + 1, (mid + 1 + current.right) / 2, current.right};

            mergeStack[++mergeTop] = (Subarray){current.left, mid, current.right};
        }
    }

    while (mergeTop >= 0) {
        Subarray current = mergeStack[mergeTop--];
        merge(arr, current.left, current.mid, current.right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Given array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
/*
function merge(arr, left, mid, right) {
    n1 = mid - left + 1;
    n2 = right - mid;
    L = new Array(n1);
    R = new Array(n2);

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }
    i = 0;
    j = 0;
    k = left;
    
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

function mergeSort(arr, n) {
    MAX = 1000;
    stack = new Array(MAX);
    top = -1;

    stack[++top] = { left: 0, mid: Math.floor((n - 1) / 2), right: n - 1 };

    mergeStack = new Array(MAX);
    mergeTop = -1;

    while (top >= 0) {
        current = stack[top--];

        if (current.left < current.right) {
            mid = Math.floor((current.left + current.right) / 2);

            stack[++top] = { left: current.left, mid: Math.floor((current.left + mid) / 2), right: mid };
            stack[++top] = { left: mid + 1, mid: Math.floor((mid + 1 + current.right) / 2), right: current.right };

            mergeStack[++mergeTop] = { left: current.left, mid: mid, right: current.right };
        }
    }

    while (mergeTop >= 0) {
        current = mergeStack[mergeTop--];
        merge(arr, current.left, current.mid, current.right);
    }
}
*/