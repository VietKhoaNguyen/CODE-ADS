#include <stdio.h>
#include <stdlib.h>

// Function to find the intersection of two arrays
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // Sort both arrays
    qsort(nums1, nums1Size, sizeof(int), (int (*)(const void*, const void*))compare);
    qsort(nums2, nums2Size, sizeof(int), (int (*)(const void*, const void*))compare);

    // Allocate a dynamic array to store the intersection
    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    *returnSize = 0;  // Initialize return size to 0
    
    // Use two pointers to find common elements
    int i = 0, j = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            // If the current elements are the same, add it to the result
            if (*returnSize == 0 || result[*returnSize - 1] != nums1[i]) {
                result[*returnSize] = nums1[i];
                (*returnSize)++;
            }
            // Move both pointers
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            // If nums1[i] is smaller, move pointer i
            i++;
        } else {
            // If nums2[j] is smaller, move pointer j
            j++;
        }
    }

    // Return the result array
    return result;
}

// Comparator function for qsort
int compare(const int* a, const int* b) {
    return (*a - *b);
}

// Function to print the result (for testing purposes)
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Test case 1
    int nums1[] = {1, 2, 2, 1};
    int nums2[] = {2, 2};
    int returnSize;
    int* result = intersection(nums1, 4, nums2, 2, &returnSize);
    printf("Intersection of nums1 and nums2: ");
    printArray(result, returnSize);
    free(result);

    // Test case 2
    int nums3[] = {4, 9, 5};
    int nums4[] = {9, 4, 9, 8, 4};
    result = intersection(nums3, 3, nums4, 5, &returnSize);
    printf("Intersection of nums3 and nums4: ");
    printArray(result, returnSize);
    free(result);

    return 0;
}
