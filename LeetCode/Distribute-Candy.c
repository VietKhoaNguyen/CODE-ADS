#include <stdio.h>
#include <stdlib.h>

int distributeCandies(int* candyType, int candyTypeSize) {
    // Use a hash table to track unique candy types
    int* hashTable = (int*)calloc(200001, sizeof(int)); // Hash table size for range [-100000, 100000]
    int uniqueCount = 0;

    for (int i = 0; i < candyTypeSize; i++) {
        int index = candyType[i] + 100000; // Shift range to [0, 200000]
        if (hashTable[index] == 0) {
            uniqueCount++;
            hashTable[index] = 1; // Mark as seen
        }
    }

    // Free allocated memory for hash table
    free(hashTable);

    // Return the minimum of uniqueCount or candyTypeSize / 2
    return uniqueCount < (candyTypeSize / 2) ? uniqueCount : (candyTypeSize / 2);
}

// Example usage
int main() {
    int candyType[] = {1, 1, 2, 2, 3, 3};
    int candyTypeSize = sizeof(candyType) / sizeof(candyType[0]);

    int result = distributeCandies(candyType, candyTypeSize);
    printf("Maximum number of unique candies one person can eat: %d\n", result);

    return 0;
}
