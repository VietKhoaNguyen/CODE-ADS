#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Helper function to check if a number exists in the array
bool exists(int* result, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (result[i] == value) {
            return true;
        }
    }
    return false;
}

// Main function
int* powerfulIntegers(int x, int y, int bound, int* returnSize) {
    // Allocate space for the result array
    int* result = (int*)malloc(1000 * sizeof(int)); // Arbitrary large size
    *returnSize = 0;

    // Iterate over powers of x
    for (int i = 0; i < 21; i++) { // 21 is sufficient because 2^20 > 10^6
        int powerX = (int)pow(x, i);
        if (powerX > bound) break;

        // Iterate over powers of y
        for (int j = 0; j < 21; j++) {
            int powerY = (int)pow(y, j);
            if (powerX + powerY > bound) break;

            int sum = powerX + powerY;

            // Add to the result if it doesn't already exist
            if (!exists(result, *returnSize, sum)) {
                result[*returnSize] = sum;
                (*returnSize)++;
            }

            // If y == 1, stop iterating over j
            if (y == 1) break;
        }

        // If x == 1, stop iterating over i
        if (x == 1) break;
    }

    return result;
}
// Example usage
#include <stdio.h>
int main() {
    int returnSize;
    int* result = powerfulIntegers(2, 3, 10, &returnSize);
    printf("Powerful integers: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}
/*recur O(logx(bound) * logy(bound))
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Helper function to check if a number exists in the array
bool exists(int* result, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (result[i] == value) {
            return true;
        }
    }
    return false;
}

// Recursive function to compute powerful integers
void findPowerfulIntegers(int x, int y, int bound, int powerX, int powerY, int* result, int* returnSize) {
    int sum = powerX + powerY;

    // If the sum exceeds the bound, return
    if (sum > bound) return;

    // Add the sum if it's not already present
    if (!exists(result, *returnSize, sum)) {
        result[*returnSize] = sum;
        (*returnSize)++;
    }

    // Recur for the next powers of x and y
    if (x > 1) findPowerfulIntegers(x, y, bound, powerX * x, powerY, result, returnSize);
    if (y > 1) findPowerfulIntegers(x, y, bound, powerX, powerY * y, result, returnSize);
}

// Main function
int* powerfulIntegers(int x, int y, int bound, int* returnSize) {
    // Allocate space for the result array
    int* result = (int*)malloc(1000 * sizeof(int)); // Arbitrary large size
    *returnSize = 0;

    // Start recursion with initial powers as 1
    findPowerfulIntegers(x, y, bound, 1, 1, result, returnSize);

    return result;
}

// Example usage
/*
#include <stdio.h>
int main() {
    int returnSize;
    int* result = powerfulIntegers(2, 3, 10, &returnSize);
    printf("Powerful integers: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}
*/

