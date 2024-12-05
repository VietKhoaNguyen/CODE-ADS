#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate summary ranges
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Allocate a maximum possible size for the ranges array
    char** ranges = (char**)malloc(numsSize * sizeof(char*));
    *returnSize = 0;
    
    int start = 0;
    
    for (int i = 1; i <= numsSize; i++) {
        // Check if we're at the end or the current number is not consecutive
        if (i == numsSize || nums[i] != nums[i - 1] + 1) {
            // Create a range string for the current range
            char* range = (char*)malloc(50 * sizeof(char));  // Allocate memory for range string
            
            // If the range is a single number
            if (i - start == 1) {
                sprintf(range, "%d", nums[start]);
            } 
            // If the range has more than one number
            else {
                sprintf(range, "%d->%d", nums[start], nums[i - 1]);
            }
            
            // Add the range to the result array
            ranges[*returnSize] = range;
            (*returnSize)++;
            
            // Move the start to the next number
            start = i;
        }
    }

    return ranges;
}

// Function to free the allocated memory
void freeSummaryRanges(char** ranges, int returnSize) {
    for (int i = 0; i < returnSize; i++) {
        free(ranges[i]);
    }
    free(ranges);
}

// Example usage
int main() {
    int nums[] = {0, 1, 2, 4, 5, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    // Get the summary ranges
    char** result = summaryRanges(nums, numsSize, &returnSize);

    // Print the result
    for (int i = 0; i < returnSize; i++) {
        printf("%s ", result[i]);
    }
    printf("\n");

    // Free the allocated memory
    freeSummaryRanges(result, returnSize);

    return 0;
}