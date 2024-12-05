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
