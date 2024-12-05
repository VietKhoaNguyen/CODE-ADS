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
/*recur O(n)
#include <stdio.h>
#include <stdlib.h>

// Helper function to recursively count unique candy types
int countUniqueCandies(int* candyType, int candyTypeSize, int* hashTable, int index, int uniqueCount) {
    if (index == candyTypeSize) {
        // Base case: If we've processed all candies, return the count of unique types
        return uniqueCount;
    }

    int candy = candyType[index];
    int hashIndex = candy + 100000; // Adjusting range to [0, 200000]

    if (hashTable[hashIndex] == 0) {
        hashTable[hashIndex] = 1; // Mark this candy type as seen
        uniqueCount++; // Increment unique count
    }

    // Recursive call to process the next candy
    return countUniqueCandies(candyType, candyTypeSize, hashTable, index + 1, uniqueCount);
}

// Main function to find the maximum number of unique candies one person can eat
int distributeCandies(int* candyType, int candyTypeSize) {
    // Allocate memory for the hash table
    int* hashTable = (int*)calloc(200001, sizeof(int)); // Size to cover range [-100000, 100000]
    
    // Start the recursion from index 0 with an initial uniqueCount of 0
    int uniqueCount = countUniqueCandies(candyType, candyTypeSize, hashTable, 0, 0);

    // Free the hash table memory
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
 */