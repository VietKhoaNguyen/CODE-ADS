#include <stdlib.h>

int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    // Result array with a max size of numSize + 1 to handle carry overflow
    int* result = (int*)malloc((numSize + 10) * sizeof(int));
    int resultIndex = 0; // Result index starts at 0
    int carry = 0;

    // Iterate from the least significant digit (end of num array)
    for (int i = numSize - 1; i >= 0 || k > 0; i--) {
        // Extract the last digit of k
        int kDigit = k % 10;
        k /= 10;

        // Current digit of num or 0 if index is out of bounds
        int numDigit = (i >= 0) ? num[i] : 0;

        // Compute the sum of digits with carry
        int sum = numDigit + kDigit + carry;
        result[resultIndex++] = sum % 10; // Store the single digit
        carry = sum / 10;                // Update the carry
    }

    // Add the remaining carry, if any
    if (carry > 0) {
        result[resultIndex++] = carry;
    }

    // Reverse the result array to get the correct order
    for (int i = 0; i < resultIndex / 2; i++) {
        int temp = result[i];
        result[i] = result[resultIndex - 1 - i];
        result[resultIndex - 1 - i] = temp;
    }

    // Set the return size
    *returnSize = resultIndex;
    return result;
}

// Example usage:

#include <stdio.h>
int main() {
    int num[] = {1, 2, 0, 0};
    int numSize = 4;
    int k = 34;
    int returnSize;
    int* result = addToArrayForm(num, numSize, k, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
    }
    printf("\n"); // Expected Output: 1234

    free(result);
    return 0;
}

/*recursive O(max(numSize, log k))
#include <stdlib.h>

void addToArrayFormRecursive(int* num, int numSize, int k, int* result, int* index, int* carry) {
    if (numSize == 0 && k == 0 && *carry == 0) {
        return; // Base case: No more digits to process
    }

    // Extract current digit of num and k
    int numDigit = (numSize > 0) ? num[numSize - 1] : 0;
    int kDigit = k % 10;
    k /= 10;

    // Calculate sum of digits and carry
    int sum = numDigit + kDigit + *carry;
    result[(*index)++] = sum % 10;
    *carry = sum / 10; // Update carry

    // Recur for the next digit (move left)
    addToArrayFormRecursive(num, numSize - 1, k, result, index, carry);
}

int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    int* result = (int*)malloc((numSize + 10) * sizeof(int)); // Max size to handle overflow
    int index = 0;
    int carry = 0;

    // Perform recursive addition
    addToArrayFormRecursive(num, numSize, k, result, &index, &carry);

    // If there's any carry left, add it
    if (carry > 0) {
        result[index++] = carry;
    }

    // Reverse the result array to get the correct order
    for (int i = 0; i < index / 2; i++) {
        int temp = result[i];
        result[i] = result[index - 1 - i];
        result[index - 1 - i] = temp;
    }

    // Set the return size
    *returnSize = index;
    return result;
}

// Example usage:
/*
#include <stdio.h>
int main() {
    int num[] = {1, 2, 0, 0};
    int numSize = 4;
    int k = 34;
    int returnSize;
    int* result = addToArrayForm(num, numSize, k, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
    }
    printf("\n"); // Expected Output: 1234

    free(result);
    return 0;
}
*/
