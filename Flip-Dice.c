#include <stdio.h>
#include <stdlib.h>

int countCompleteSets(int* rolls, int rollsSize) {
    // Array to count the frequency of each number (1 through 6)
    int count[6] = {0};
    
    // Count the occurrences of each number in the dice rolls
    for (int i = 0; i < rollsSize; i++) {
        if (rolls[i] >= 1 && rolls[i] <= 6) {
            count[rolls[i] - 1]++;  // Increment the count for the rolled number
        }
    }
    
    // Find the minimum count among all numbers (1 to 6)
    int minCount = count[0];
    for (int i = 1; i < 6; i++) {
        if (count[i] < minCount) {
            minCount = count[i];
        }
    }

    return minCount;
}

int main() {
    int rolls[] = {1, 2, 2, 3, 4, 5, 6, 6, 6};
    int rollsSize = sizeof(rolls) / sizeof(rolls[0]);

    int result = countCompleteSets(rolls, rollsSize);
    printf("The number of complete sets that can be formed: %d\n", result);

    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <stdlib.h>

// Helper function to count occurrences of numbers (1 to 6) recursively
void countOccurrences(int* rolls, int rollsSize, int index, int* count) {
    if (index >= rollsSize) {
        return; // Base case: stop when we reach the end of the array
    }

    if (rolls[index] >= 1 && rolls[index] <= 6) {
        count[rolls[index] - 1]++; // Increment the count for the rolled number
    }

    countOccurrences(rolls, rollsSize, index + 1, count); // Recursive call for the next index
}

// Helper function to find the minimum count recursively
int findMin(int* count, int index, int minCount) {
    if (index >= 6) {
        return minCount; // Base case: return the minimum count when all numbers are checked
    }

    if (count[index] < minCount) {
        minCount = count[index]; // Update minCount if the current count is smaller
    }

    return findMin(count, index + 1, minCount); // Recursive call for the next index
}

// Function to count the complete sets recursively
int countCompleteSets(int* rolls, int rollsSize) {
    // Array to count the frequency of each number (1 through 6)
    int count[6] = {0};

    // Start the recursive counting
    countOccurrences(rolls, rollsSize, 0, count);

    // Find the minimum count recursively
    return findMin(count, 0, count[0]);
}

int main() {
    int rolls[] = {1, 2, 2, 3, 4, 5, 6, 6, 6};
    int rollsSize = sizeof(rolls) / sizeof(rolls[0]);

    int result = countCompleteSets(rolls, rollsSize);
    printf("The number of complete sets that can be formed: %d\n", result);

    return 0;
}
*/