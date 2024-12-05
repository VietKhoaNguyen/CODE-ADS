#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* prefixSum; // The prefix sum array
    int size; // The size of the nums array
} NumArray;

// Function to create the NumArray and calculate the prefix sum
NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    obj->prefixSum = (int*)malloc((numsSize + 1) * sizeof(int)); // prefix[0] = 0
    obj->size = numsSize;

    // Calculate the prefix sum
    obj->prefixSum[0] = 0; // prefixSum[0] = 0 for easier calculation
    for (int i = 0; i < numsSize; i++) {
        obj->prefixSum[i + 1] = obj->prefixSum[i] + nums[i];
    }

    return obj;
}

// Function to calculate the sum from index left to right (inclusive)
int numArraySumRange(NumArray* obj, int left, int right) {
    // Using the prefix sum array to compute the range sum
    return obj->prefixSum[right + 1] - obj->prefixSum[left];
}

// Function to free the allocated memory
void numArrayFree(NumArray* obj) {
    free(obj->prefixSum);
    free(obj);
}

// Example usage
int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int numsSize = 5;
    NumArray* obj = numArrayCreate(nums, numsSize);

    // Get the sum of elements between indices 1 and 3 (inclusive)
    int sum = numArraySumRange(obj, 1, 3);
    printf("Sum between 1 and 3: %d\n", sum); // Output: 9 (2 + 3 + 4)

    // Free the memory
    numArrayFree(obj);
    
    return 0;
}
