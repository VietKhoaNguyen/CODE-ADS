#include <stdio.h>
#include <stdlib.h>

int maximumProduct(int* nums, int numsSize) {
    // Sort the array first
    qsort(nums, numsSize, sizeof(int), compare); // qsort sorts in ascending order

    // The maximum product can either be the product of the three largest numbers
    // or the product of the two smallest (most negative) numbers and the largest number
    int product1 = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
    int product2 = nums[0] * nums[1] * nums[numsSize - 1];
    
    // Return the maximum product of the two possibilities
    return product1 > product2 ? product1 : product2;
}

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = maximumProduct(nums, numsSize);
    printf("Maximum product of three numbers: %d\n", result);

    return 0;
}
/*recur O(n log n)
#include <stdio.h>
#include <stdlib.h>

// Helper function to recursively sort the array (using merge sort for recursion)
void mergeSort(int* nums, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
}

// Merge function to merge two halves of the array
void merge(int* nums, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArr = (int*)malloc(n1 * sizeof(int));
    int* rightArr = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        leftArr[i] = nums[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = nums[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            nums[k] = leftArr[i];
            i++;
        } else {
            nums[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        nums[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        nums[k] = rightArr[j];
        j++;
        k++;
    }

    free(leftArr);
    free(rightArr);
}

// Recursive function to calculate the maximum product
int maximumProductRecursive(int* nums, int left, int right) {
    if (right - left + 1 <= 3) {
        // Base case: only 3 elements left, calculate their product directly
        return nums[left] * nums[left + 1] * nums[left + 2];
    }

    // Recursive case: find the maximum product of three elements in the subarray
    int product1 = nums[right] * nums[right - 1] * nums[right - 2];
    int product2 = nums[left] * nums[left + 1] * nums[right];
    return product1 > product2 ? product1 : product2;
}

int maximumProduct(int* nums, int numsSize) {
    // Sort the array recursively
    mergeSort(nums, 0, numsSize - 1);

    // Now find the maximum product
    return maximumProductRecursive(nums, 0, numsSize - 1);
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = maximumProduct(nums, numsSize);
    printf("Maximum product of three numbers: %d\n", result);

    return 0;
}
*/