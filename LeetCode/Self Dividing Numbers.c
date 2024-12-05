#include <stdio.h>
#include <stdlib.h>

// Helper function to check if a number is self-dividing
int isSelfDividing(int num) {
    int original = num;
    while (num > 0) {
        int digit = num % 10;
        if (digit == 0 || original % digit != 0) {
            return 0; // Not self-dividing if there's a zero or a remainder
        }
        num /= 10; // Remove the last digit
    }
    return 1; // It's self-dividing
}

int* selfDividingNumbers(int left, int right, int* returnSize) {
    int* result = (int*)malloc((right - left + 1) * sizeof(int)); // Allocate memory for the result array
    int index = 0;

    // Iterate through the range [left, right]
    for (int num = left; num <= right; num++) {
        if (isSelfDividing(num)) {
            result[index++] = num; // Add the self-dividing number to the result
        }
    }

    *returnSize = index; // Set the size of the result array
    return result;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int left = 1, right = 22;
    int returnSize;
    int* result = selfDividingNumbers(left, right, &returnSize);

    printf("Self-dividing numbers between %d and %d are:\n", left, right);
    printArray(result, returnSize);

    free(result); // Don't forget to free the allocated memory
    return 0;
}
/*recur O(n*d)
#include <stdio.h>
#include <stdlib.h>

// Helper function to check if a number is self-dividing
int isSelfDividing(int num) {
    int original = num;
    while (num > 0) {
        int digit = num % 10;
        if (digit == 0 || original % digit != 0) {
            return 0; // Not self-dividing if there's a zero or a remainder
        }
        num /= 10; // Remove the last digit
    }
    return 1; // It's self-dividing
}

// Recursive function to find self-dividing numbers in the range [left, right]
void findSelfDividingNumbers(int left, int right, int* result, int* index) {
    if (left > right) {
        return; // Base case: if the left pointer exceeds right, stop recursion
    }
    
    if (isSelfDividing(left)) {
        result[*index] = left; // Add the self-dividing number to the result
        (*index)++; // Increment the index
    }

    // Recurse for the next number
    findSelfDividingNumbers(left + 1, right, result, index);
}

int* selfDividingNumbers(int left, int right, int* returnSize) {
    int* result = (int*)malloc((right - left + 1) * sizeof(int)); // Allocate memory for result array
    int index = 0;

    // Start recursion to find self-dividing numbers
    findSelfDividingNumbers(left, right, result, &index);

    *returnSize = index; // Set the size of the result array
    return result;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int left = 1, right = 22;
    int returnSize;
    int* result = selfDividingNumbers(left, right, &returnSize);

    printf("Self-dividing numbers between %d and %d are:\n", left, right);
    printArray(result, returnSize);

    free(result); // Don't forget to free the allocated memory
    return 0;
}
*/