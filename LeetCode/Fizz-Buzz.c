#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fizzBuzz(int n, int* returnSize) {
    // Allocate memory for the array of strings
    char** result = (char**)malloc(n * sizeof(char*));

    // Loop through numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        // Allocate memory for the string
        result[i - 1] = (char*)malloc(9 * sizeof(char)); // "FizzBuzz" has 8 characters + null terminator
        
        if (i % 3 == 0 && i % 5 == 0) {
            strcpy(result[i - 1], "FizzBuzz");
        } else if (i % 3 == 0) {
            strcpy(result[i - 1], "Fizz");
        } else if (i % 5 == 0) {
            strcpy(result[i - 1], "Buzz");
        } else {
            // Convert the number to a string and copy it to the result
            sprintf(result[i - 1], "%d", i);
        }
    }

    *returnSize = n;  // Set the return size to n
    return result;
}

void freeFizzBuzz(char** result, int n) {
    // Free the allocated memory for the array and its strings
    for (int i = 0; i < n; i++) {
        free(result[i]);
    }
    free(result);
}

int main() {
    int n = 15;
    int returnSize;
    char** result = fizzBuzz(n, &returnSize);

    // Print the result
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
    }

    // Free the allocated memory
    freeFizzBuzz(result, returnSize);

    return 0;
}