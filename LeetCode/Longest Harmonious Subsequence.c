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
/*recur O(n)
#include <stdio.h>
#include <stdlib.h>

// Recursive helper function to count frequencies of numbers
void countFrequencies(int* nums, int numsSize, int* hashTable, int offset, int index) {
    if (index == numsSize) {
        return; // Base case: when we've processed all numbers
    }
    hashTable[nums[index] + offset]++; // Increment the count for the current number
    countFrequencies(nums, numsSize, hashTable, offset, index + 1); // Recurse for the next index
}

// Recursive helper function to find the longest harmonious subsequence
int findMaxLength(int* hashTable, int maxIndex, int currentIndex, int maxLength) {
    if (currentIndex >= maxIndex) {
        return maxLength; // Base case: when we've checked all possible pairs
    }

    // Check if the current index and the next index form a valid subsequence
    if (hashTable[currentIndex] > 0 && hashTable[currentIndex + 1] > 0) {
        int length = hashTable[currentIndex] + hashTable[currentIndex + 1];
        maxLength = (length > maxLength) ? length : maxLength;
    }

    // Recurse to check the next pair of adjacent indices
    return findMaxLength(hashTable, maxIndex, currentIndex + 1, maxLength);
}

int findLHS(int* nums, int numsSize) {
    int hashTable[200001] = {0}; // Hash table to count occurrences of numbers
    int offset = 100000; // Offset to handle negative indices

    // Count frequencies of numbers using recursion
    countFrequencies(nums, numsSize, hashTable, offset, 0);

    // Find the longest harmonious subsequence using recursion
    return findMaxLength(hashTable, 200001 - 1, 0, 0);
}

// Example usage
int main() {
    int nums[] = {1, 3, 2, 2, 5, 2, 3, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = findLHS(nums, numsSize);
    printf("Length of Longest Harmonious Subsequence: %d\n", result);

    return 0;
}
*/