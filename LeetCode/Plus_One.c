#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Allocate memory for the result array. It could need one extra digit in case of carry.
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    if (!result) 
        return NULL;  // Return NULL if memory allocation fails
    
    int carry = 1;  // Initialize carry to 1 because we are adding 1
    // Traverse the digits array from right to left
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;  // Add the current digit and carry
        result[i + 1] = sum % 10;  // Store the current digit in the result
        carry = sum / 10;  // Update carry for the next iteration
    }

    // If carry is still greater than 0 after processing all digits
    if (carry > 0) {
        result[0] = carry;  // Store carry in the most significant position
        *returnSize = digitsSize + 1;  // Set return size to digitsSize + 1
    } else {
        // If no carry, shift the result array and update the size
        for (int i = 0; i < digitsSize; i++) {
            result[i] = result[i + 1];  // Shift elements to the left
        }
        *returnSize = digitsSize;  // Set return size to the original digitsSize
    }

    return result;  // Return the result array
}

// Function to free the allocated memory (caller should free the memory)
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the plusOne function
int main() {
    int digits[] = {9, 9, 9};
    int digitsSize = 3;
    int returnSize;
    
    // Call the plusOne function
    int* result = plusOne(digits, digitsSize, &returnSize);
    
    // Print the result array
    printArray(result, returnSize);  // Expected output: 1 0 0 0
    
    // Free the allocated memory
    free(result);
    
    return 0;
}
