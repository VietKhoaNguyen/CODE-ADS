#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to find the intersection of two arrays
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // Allocate memory for the result array
    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    *returnSize = 0;

    // Create a hash map (or a frequency array) for nums1
    // Here, assuming the elements in nums1 and nums2 are within the range of [-1000, 1000].
    // Otherwise, we could use a hash table for larger ranges.
    int hashMap[2001] = {0};  // Map for the range [-1000, 1000], so we use an offset of 1000

    // Count the frequency of each element in nums1
    for (int i = 0; i < nums1Size; i++) {
        hashMap[nums1[i] + 1000]++;  // Store counts in the hash map
    }

    // Iterate through nums2 to find common elements
    for (int i = 0; i < nums2Size; i++) {
        if (hashMap[nums2[i] + 1000] > 0) {  // Check if the element is in nums1 and not used yet
            result[*returnSize] = nums2[i];  // Add the element to the result
            (*returnSize)++;  // Increment the result size
            hashMap[nums2[i] + 1000]--;  // Decrease the count to avoid duplicate intersections
        }
    }

    return result;
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
