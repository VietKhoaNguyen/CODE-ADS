#include <stdio.h>
#include <stdlib.h>

int* sumZero(int n, int* returnSize) {
    *returnSize = n;  // Set the size of the returned array
    
    // Allocate memory for the array
    int* result = (int*)malloc(n * sizeof(int));
    
    // Fill the array with the appropriate values
    int index = 0;
    for (int i = 1; i <= n / 2; i++) {
        result[index++] = i;
        result[index++] = -i;
    }
    
    // If n is odd, add 0 at the end
    if (n % 2 != 0) {
        result[index] = 0;
    }
    
    return result;
}

// Example usage
int main() {
    int n = 5;
    int returnSize;
    int* result = sumZero(n, &returnSize);
    
    // Print the array
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    // Free the allocated memory
    free(result);
    
    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <stdlib.h>

void helper(int* result, int n, int* index) {
    if (n == 0) {
        return;
    }
    
    // Add the positive and negative number pair
    result[(*index)++] = n / 2 + 1;
    result[(*index)++] = -(n / 2 + 1);
    
    // Recursively call for the smaller problem
    helper(result, n - 2, index);
}

int* sumZero(int n, int* returnSize) {
    *returnSize = n;
    int* result = (int*)malloc(n * sizeof(int));
    
    int index = 0;
    
    // Start the recursion for an even number of elements
    helper(result, n, &index);
    
    // If the number is odd, add 0 at the end
    if (n % 2 != 0) {
        result[index] = 0;
    }
    
    return result;
}

// Example usage
int main() {
    int n = 5;
    int returnSize;
    int* result = sumZero(n, &returnSize);
    
    // Print the array
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    // Free the allocated memory
    free(result);
    
    return 0;
}
*/