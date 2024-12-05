#include <stdio.h>
#include <stdlib.h>

int findLHS(int* nums, int numsSize) {
    // Use a hash table to count frequencies of numbers
    int hashTable[200001] = {0}; // Range to account for negative numbers
    int offset = 100000; // Offset to handle negative indices
    
    // Count occurrences of each number
    for (int i = 0; i < numsSize; i++) {
        hashTable[nums[i] + offset]++;
    }

    int maxLength = 0;

    // Iterate through hashTable and find the longest harmonious subsequence
    for (int i = 0; i < 200001 - 1; i++) {
        if (hashTable[i] > 0 && hashTable[i + 1] > 0) {
            int length = hashTable[i] + hashTable[i + 1];
            if (length > maxLength) {
                maxLength = length;
            }
        }
    }

    return maxLength;
}

// Example usage
int main() {
    int nums[] = {1, 3, 2, 2, 5, 2, 3, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = findLHS(nums, numsSize);
    printf("Length of Longest Harmonious Subsequence: %d\n", result);

    return 0;
}
