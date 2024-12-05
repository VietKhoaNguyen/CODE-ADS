#include <stdio.h>
#include <stdlib.h>

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    // dp[i] stores the size of the largest divisible subset ending at nums[i]
    int* dp = (int*)malloc(numsSize * sizeof(int));
    int* prev = (int*)malloc(numsSize * sizeof(int));  // To backtrack the subset
    int maxSize = 1, maxIndex = 0;

    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;  // Each number is a subset of size 1
        prev[i] = -1;  // Initialize with -1 to indicate no previous number in the subset

        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }

        // Track the largest subset
        if (dp[i] > maxSize) {
            maxSize = dp[i];
            maxIndex = i;
        }
    }

    // Backtrack to find the actual subset
    int* result = (int*)malloc(maxSize * sizeof(int));
    int index = maxSize - 1;
    while (maxIndex != -1) {
        result[index--] = nums[maxIndex];
        maxIndex = prev[maxIndex];
    }

    *returnSize = maxSize;
    free(dp);
    free(prev);
    return result;
}

// Helper function to compare integers for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Helper function to print the array (for testing purposes)
void printArray(int* nums, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {1, 2, 4, 8};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = largestDivisibleSubset(nums, numsSize, &returnSize);

    printf("Largest Divisible Subset: ");
    printArray(result, returnSize);

    free(result);  // Free the allocated memory
    return 0;
}
/*recur O(n^2)
#include <stdio.h>
#include <stdlib.h>

// Helper function to compare integers for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Recursive function to find the largest divisible subset
void findLargestSubset(int* nums, int numsSize, int* dp, int* prev, int index, int* maxSize, int* maxIndex) {
    // Base case: If we have processed all elements, return
    if (index == numsSize) return;

    // Start the DP value at 1 for this index (smallest subset is the number itself)
    dp[index] = 1;
    prev[index] = -1;

    for (int i = 0; i < index; i++) {
        // Check if nums[index] can be part of the subset with nums[i]
        if (nums[index] % nums[i] == 0 && dp[index] < dp[i] + 1) {
            dp[index] = dp[i] + 1;
            prev[index] = i;
        }
    }

    // Update the maximum size and index of the largest subset
    if (dp[index] > *maxSize) {
        *maxSize = dp[index];
        *maxIndex = index;
    }

    // Recursive call to process the next index
    findLargestSubset(nums, numsSize, dp, prev, index + 1, maxSize, maxIndex);
}

// Function to reconstruct the subset based on dp and prev arrays
int* reconstructSubset(int* nums, int* prev, int maxIndex, int maxSize) {
    int* result = (int*)malloc(maxSize * sizeof(int));
    int index = maxSize - 1;
    while (maxIndex != -1) {
        result[index--] = nums[maxIndex];
        maxIndex = prev[maxIndex];
    }
    return result;
}

// Main function to find the largest divisible subset
int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Sort the array for the subset divisibility check
    qsort(nums, numsSize, sizeof(int), compare);

    // Initialize dp and prev arrays
    int* dp = (int*)malloc(numsSize * sizeof(int));
    int* prev = (int*)malloc(numsSize * sizeof(int));
    int maxSize = 1, maxIndex = 0;

    // Start the recursive process from index 0
    findLargestSubset(nums, numsSize, dp, prev, 0, &maxSize, &maxIndex);

    // Reconstruct the result based on dp and prev arrays
    int* result = reconstructSubset(nums, prev, maxIndex, maxSize);

    *returnSize = maxSize;
    free(dp);
    free(prev);
    return result;
}

// Helper function to print the array (for testing purposes)
void printArray(int* nums, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {1, 2, 4, 8};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = largestDivisibleSubset(nums, numsSize, &returnSize);

    printf("Largest Divisible Subset: ");
    printArray(result, returnSize);

    free(result);  // Free the allocated memory
    return 0;
}
*/