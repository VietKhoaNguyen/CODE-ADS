/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    
}
/*recur O(2^n)
#include <stdio.h>
#include <stdlib.h>

// Helper function to generate Gray Code sequence recursively
void generateGrayCode(int n, int* result, int* index) {
    // Base case: if n == 0, return
    if (n == 0) {
        return;
    }

    // Recursively generate the Gray Code for n-1 bits
    generateGrayCode(n - 1, result, index);

    // Create the current Gray Code number by adding 0 and 1
    int leadingBit = 1 << (n - 1); // The leading bit for current Gray Code
    
    // The second half: add 1 (prefix 1 to the reversed sequence)
    for (int i = *index - 1; i >= 0; i--) {
        result[*index] = result[i] | leadingBit;
        (*index)++;
    }
}

// Main function to generate the Gray Code sequence
int* grayCode(int n, int* returnSize) {
    int totalSize = 1 << n;  // Total number of Gray codes: 2^n
    int* result = (int*)malloc(totalSize * sizeof(int));  // Allocate memory for the sequence
    
    // Base Gray Code value
    result[0] = 0;
    
    int index = 1;  // To keep track of the current index in the result array
    
    // Recursively generate the Gray Code sequence
    generateGrayCode(n, result, &index);
    
    *returnSize = totalSize;  // Set the return size to 2^n
    return result;
}

// Helper function to print the Gray Code sequence
void printGrayCode(int* grayCode, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", grayCode[i]);
    }
    printf("\n");
}

int main() {
    int n = 3;  // Example: number of bits
    int returnSize;
    
    // Get the Gray Code sequence
    int* grayCodeSeq = grayCode(n, &returnSize);
    
    // Print the Gray Code sequence
    printGrayCode(grayCodeSeq, returnSize);
    
    // Free the allocated memory
    free(grayCodeSeq);
    
    return 0;
}
*/