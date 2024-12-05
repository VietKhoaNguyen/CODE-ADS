#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    // Set pointers for nums1 and nums2
    int i = m - 1;  // Pointer for the last element in nums1's valid part
    int j = n - 1;  // Pointer for the last element in nums2
    int k = nums1Size - 1;  // Pointer for the last position in nums1

    // Merge the arrays from the end
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // If there are remaining elements in nums2, copy them
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }

    // If there are remaining elements in nums1, no action is needed
    // because they are already in place in nums1
}

// Helper function to print the array (for testing)
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the merge function
int main() {
    int nums1[6] = {1, 2, 3, 0, 0, 0};  // nums1 has enough space for nums2
    int nums2[3] = {2, 5, 6};
    int m = 3;  // Number of valid elements in nums1
    int n = 3;  // Number of valid elements in nums2

    printf("Before merging:\n");
    printArray(nums1, 6);
    printArray(nums2, 3);

    merge(nums1, 6, m, nums2, 3, n);

    printf("After merging:\n");
    printArray(nums1, 6);

    return 0;
}
