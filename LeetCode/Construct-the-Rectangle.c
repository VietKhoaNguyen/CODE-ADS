#include <stdlib.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    // Allocate memory for the result array
    int* result = (int*)malloc(2 * sizeof(int));
    if (!result) return NULL; // Handle memory allocation failure

    // Start with the square root of the area
    int W = (int)sqrt(area);

    // Find the largest W such that area % W == 0
    while (area % W != 0) {
        W--;
    }

    // Calculate L using W
    int L = area / W;

    // Assign values to the result array
    result[0] = L;
    result[1] = W;

    // Set the return size
    *returnSize = 2;

    return result;
}
int main() {
    int area = 37;
    int returnSize;
    int* result = constructRectangle(area, &returnSize);

    printf("L: %d, W: %d\n", result[0], result[1]); // Output: L: 37, W: 1

    free(result); // Free the allocated memory
    return 0;
}
/*recur O(sqrt(n))
#include <stdlib.h>
#include <math.h>

/**
 * Recursive helper function to find the largest divisor of the area starting from sqrt(area).
 */
int findWidth(int area, int W) {
    if (area % W == 0) {
        return W;  // Found the largest divisor
    }
    return findWidth(area, W - 1);  // Recursively check smaller values of W
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    // Allocate memory for the result array
    int* result = (int*)malloc(2 * sizeof(int));
    if (!result) return NULL; // Handle memory allocation failure

    // Start with the square root of the area
    int W = (int)sqrt(area);

    // Use the recursive function to find the largest width such that area % W == 0
    W = findWidth(area, W);

    // Calculate L using W
    int L = area / W;

    // Assign values to the result array
    result[0] = L;
    result[1] = W;

    // Set the return size
    *returnSize = 2;

    return result;
}

int main() {
    int area = 37;
    int returnSize;
    int* result = constructRectangle(area, &returnSize);

    printf("L: %d, W: %d\n", result[0], result[1]); // Output: L: 37, W: 1

    free(result); // Free the allocated memory
    return 0;
}
*/