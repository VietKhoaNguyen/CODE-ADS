#include <stdio.h>
#include <stdlib.h>

// Helper function to check if a number contains a zero digit
int hasZero(int num) {
    while (num > 0) {
        if (num % 10 == 0) {
            return 1; // Contains zero
        }
        num /= 10;
    }
    return 0; // Does not contain zero
}

int* getNoZeroIntegers(int n, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));  // Array to store the two integers
    *returnSize = 2; // We are always returning two integers
    
    for (int x = 1; x < n; x++) {
        if (!hasZero(x) && !hasZero(n - x)) {
            result[0] = x;
            result[1] = n - x;
            return result;
        }
    }
    
    // In case there's no solution (although we expect to always find one)
    *returnSize = 0;
    return NULL;
}

// Example usage
int main() {
    int n = 11;
    int returnSize;
    
    int* result = getNoZeroIntegers(n, &returnSize);
    
    if (result != NULL) {
        printf("The two numbers are: %d and %d\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }
    
    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <stdlib.h>

// Helper function to check if a number contains a zero digit
int hasZero(int num) {
    while (num > 0) {
        if (num % 10 == 0) {
            return 1; // Contains zero
        }
        num /= 10;
    }
    return 0; // Does not contain zero
}

// Recursive function to find two numbers that sum up to n and do not contain zeros
int* getNoZeroIntegersHelper(int n, int x, int* returnSize) {
    if (x >= n) {
        return NULL; // If we've tried all possibilities, return NULL
    }
    
    int other = n - x;
    // Check if both x and n - x do not contain zero
    if (!hasZero(x) && !hasZero(other)) {
        int* result = (int*)malloc(2 * sizeof(int)); // Allocate memory for the result
        result[0] = x;
        result[1] = other;
        *returnSize = 2; // We found a valid pair
        return result;
    }
    
    // Recursively check the next x value
    return getNoZeroIntegersHelper(n, x + 1, returnSize);
}

int* getNoZeroIntegers(int n, int* returnSize) {
    return getNoZeroIntegersHelper(n, 1, returnSize); // Start from x = 1
}

// Example usage
int main() {
    int n = 11;
    int returnSize;
    
    int* result = getNoZeroIntegers(n, &returnSize);
    
    if (result != NULL) {
        printf("The two numbers are: %d and %d\n", result[0], result[1]);
        free(result); // Free the allocated memory
    } else {
        printf("No solution found.\n");
    }
    
    return 0;
}
*/