#include <stdio.h>
#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    // Iterate through the array to mark visited elements
    for (int i = 0; i < numsSize; i++) {
        int num = abs(nums[i]) - 1; // Calculate the index corresponding to the number
        if (nums[num] > 0) {
            nums[num] = -nums[num]; // Mark as visited by making it negative
        }
    }

    // Collect all the indices that were not marked (i.e., corresponding to missing numbers)
    int* result = (int*)malloc(sizeof(int) * numsSize);
    int resultIndex = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            result[resultIndex++] = i + 1; // Add the missing number (index + 1)
        }
    }

    *returnSize = resultIndex; // Set the size of the result array
    return result;
}

int main() {
    int nums[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* missingNumbers = findDisappearedNumbers(nums, numsSize, &returnSize);

    // Print the result
    printf("Missing numbers: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", missingNumbers[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(missingNumbers);

    return 0;
}
