#include <stdlib.h>

/**
 * Helper function to construct a beautiful array recursively.
 * @param n - The size of the array to generate.
 * @param returnSize - Pointer to store the size of the returned array.
 * @return The generated beautiful array.
 */
int* constructBeautifulArray(int n, int* returnSize) {
    if (n == 1) {
        // Base case: a single-element array is always beautiful
        int* base = (int*)malloc(sizeof(int));
        base[0] = 1;
        *returnSize = 1;
        return base;
    }

    // Divide step: recursively construct arrays for even and odd positions
    int leftSize = 0, rightSize = 0;
    int* left = constructBeautifulArray((n + 1) / 2, &leftSize); // Odd indices
    int* right = constructBeautifulArray(n / 2, &rightSize);     // Even indices

    // Combine step: merge the arrays while scaling appropriately
    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < leftSize; i++) {
        result[i] = 2 * left[i] - 1; // Odd elements
    }
    for (int i = 0; i < rightSize; i++) {
        result[leftSize + i] = 2 * right[i]; // Even elements
    }

    *returnSize = n;

    // Free memory used for left and right subarrays
    free(left);
    free(right);

    return result;
}

/**
 * Main function to generate a beautiful array.
 * @param n - The size of the beautiful array.
 * @param returnSize - Pointer to store the size of the returned array.
 * @return The generated beautiful array.
 */
int* beautifulArray(int n, int* returnSize) {
    return constructBeautifulArray(n, returnSize);
}

// Example usage

#include <stdio.h>

int main() {
    int n = 5;
    int returnSize;
    int* result = beautifulArray(n, &returnSize);

    printf("Beautiful Array: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
/* recur O(n logn)
#include <stdlib.h>

/**
 * Recursive helper function to construct a beautiful array.
 * @param start - Starting value of the range.
 * @param end - Ending value of the range.
 * @param returnSize - Pointer to store the size of the returned array.
 * @return The generated beautiful array.
 
int* constructBeautifulArrayRecursive(int start, int end, int* returnSize) {
    if (start > end) {
        *returnSize = 0;
        return NULL;
    }

    if (start == end) {
        // Base case: single-element array
        int* result = (int*)malloc(sizeof(int));
        result[0] = start;
        *returnSize = 1;
        return result;
    }

    // Split into odd and even indices
    int leftSize = 0, rightSize = 0;
    int* left = constructBeautifulArrayRecursive(start, (start + end) / 2, &leftSize); // Odd indices
    int* right = constructBeautifulArrayRecursive((start + end) / 2 + 1, end, &rightSize); // Even indices

    // Combine the results
    int* result = (int*)malloc((leftSize + rightSize) * sizeof(int));
    for (int i = 0; i < leftSize; i++) {
        result[i] = left[i] * 2 - 1; // Odd elements
    }
    for (int i = 0; i < rightSize; i++) {
        result[leftSize + i] = right[i] * 2; // Even elements
    }

    *returnSize = leftSize + rightSize;

    // Free the intermediate arrays
    free(left);
    free(right);

    return result;
}

/**
 * Main function to generate a beautiful array.
 * @param n - The size of the beautiful array.
 * @param returnSize - Pointer to store the size of the returned array.
 * @return The generated beautiful array.
 
int* beautifulArray(int n, int* returnSize) {
    return constructBeautifulArrayRecursive(1, n, returnSize);
}

// Example usage

#include <stdio.h>

int main() {
    int n = 5;
    int returnSize;
    int* result = beautifulArray(n, &returnSize);

    printf("Beautiful Array: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
*/

