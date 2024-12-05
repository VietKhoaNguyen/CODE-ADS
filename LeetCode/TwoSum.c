#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Create a hash table to store numbers and their indices
    // Assume numsSize is not larger than 10^4, and use a simple array as the hash table.
    // Adjust the size of the hash table as per your needs, here we use 10^6 for simplicity.
    int* hashTable = (int*)calloc(1000000, sizeof(int));
    
    // Initialize return size to 2 (as we are always looking for two numbers)
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    // Loop through the numbers in the array
    for (int i = 0; i < numsSize; i++) {
        // Calculate the complement of the current number
        int complement = target - nums[i];
        
        // Check if the complement is in the hash table
        if (hashTable[complement + 500000] != 0) {
            // If found, return the indices (we store them as 1-based index in hashTable)
            result[0] = hashTable[complement + 500000] - 1;
            result[1] = i;
            free(hashTable);
            return result;
        }
        
        // Store the current number's index in the hash table (mark it with a positive value)
        hashTable[nums[i] + 500000] = i + 1; // Adding 500000 to handle negative numbers
    }
    
    // If no solution found (though the problem assumes there is one), return NULL
    free(hashTable);
    return NULL;
}

int main() {
    int nums[] = {3,2,4};
    int target = 6;
    int returnSize;
    int* result = twoSum(nums, 4, target, &returnSize);
    
    if (result != NULL) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }
    
    return 0;
}
