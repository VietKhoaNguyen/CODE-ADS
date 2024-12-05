#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to check if the array contains any duplicates
bool containsDuplicate(int* nums, int numsSize) {
    // Create a hash set to store the elements we've seen
    int* seen = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        seen[i] = -1;  // Initialize all elements as -1 (indicating not seen)
    }

    // Iterate through the array and check for duplicates
    for (int i = 0; i < numsSize; i++) {
        int value = nums[i];
        if (seen[value % numsSize] != -1) {  // Use modulo to map values to the array
            free(seen);  // Free the allocated memory
            return true; // Duplicate found
        }
        seen[value % numsSize] = value;  // Store the value
    }

    free(seen);  // Free the allocated memory
    return false; // No duplicates found
}

// Example usage
int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    if (containsDuplicate(nums, numsSize)) {
        printf("The array contains duplicates.\n");
    } else {
        printf("The array does not contain duplicates.\n");
    }

    return 0;
}
