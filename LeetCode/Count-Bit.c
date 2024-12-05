#include <stdlib.h>

// Function to count the number of set bits (1's) in the binary representation of numbers from 0 to n
int* countBits(int n, int* returnSize) {
    // Allocate memory for the result array of size n + 1
    int* result = (int*)malloc((n + 1) * sizeof(int));

    // Initialize returnSize to n + 1 (size of the result array)
    *returnSize = n + 1;

    // Base case: 0 has 0 set bits
    result[0] = 0;

    // Fill the result array using dynamic programming
    for (int i = 1; i <= n; i++) {
        // Use the formula: result[i] = result[i >> 1] + (i & 1)
        // i >> 1 is i divided by 2, and i & 1 checks if the last bit is 1
        result[i] = result[i >> 1] + (i & 1);
    }

    return result;
}

// Example usage
#include <stdio.h>

int main() {
    int n = 5;
    int returnSize;
    
    // Get the array with the count of set bits from 0 to n
    int* result = countBits(n, &returnSize);

    // Print the result array
    printf("Set bits count for numbers from 0 to %d: [", n);
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Free the allocated memory
    free(result);

    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <stdlib.h>

// Recursive helper function to count set bits from 0 to n
void countBitsRecursive(int* result, int i, int n) {
    if (i > n) {
        return;  // Base case: stop recursion when i exceeds n
    }

    // Recursively calculate the set bits count for the current number
    result[i] = result[i >> 1] + (i & 1);

    // Recursive call for the next number
    countBitsRecursive(result, i + 1, n);
}


int* countBits(int n, int* returnSize) {
    // Allocate memory for the result array of size n + 1
    int* result = (int*)malloc((n + 1) * sizeof(int));

    // Initialize returnSize to n + 1 (size of the result array)
    *returnSize = n + 1;

    // Base case: 0 has 0 set bits
    result[0] = 0;

    // Start the recursion to fill the result array
    countBitsRecursive(result, 1, n);

    return result;
}

int main() {
    int n = 5;
    int returnSize;
    
    // Get the array with the count of set bits from 0 to n
    int* result = countBits(n, &returnSize);

    // Print the result array
    printf("Set bits count for numbers from 0 to %d: [", n);
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Free the allocated memory
    free(result);

    return 0;
}
*/