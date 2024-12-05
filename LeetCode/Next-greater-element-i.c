#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // Initialize a hash map to store the next greater element for each element in nums2
    int* nextGreater = (int*)malloc(nums2Size * sizeof(int));
    int* result = (int*)malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;
    
    // Map to store the next greater element for each number in nums2
    int map[10001]; // Assuming the numbers in nums2 are within a range [-10000, 10000]
    memset(map, -1, sizeof(map));
    
    // Monotonic stack to find the next greater element for each element in nums2
    int stack[nums2Size];
    int stackTop = -1;

    // Traverse nums2 from right to left
    for (int i = nums2Size - 1; i >= 0; i--) {
        // Pop smaller or equal elements from the stack
        while (stackTop >= 0 && nums2[stack[stackTop]] <= nums2[i]) {
            stackTop--;
        }
        
        // If the stack is not empty, the top of the stack is the next greater element
        if (stackTop >= 0) {
            map[nums2[i]] = nums2[stack[stackTop]];
        } else {
            map[nums2[i]] = -1;
        }
        
        // Push the current element to the stack
        stack[++stackTop] = i;
    }

    // Populate the result for nums1 based on the nextGreater map
    for (int i = 0; i < nums1Size; i++) {
        result[i] = map[nums1[i]];
    }

    return result;
}
int main() {
    int nums1[] = {4, 1, 2};
    int nums2[] = {1, 3, 4, 2};
    int returnSize;
    
    int* result = nextGreaterElement(nums1, 3, nums2, 4, &returnSize);
    
    // Print the result
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n"); // Expected output: 3 -1 -1
    
    free(result); // Free the dynamically allocated memory
    return 0;
}