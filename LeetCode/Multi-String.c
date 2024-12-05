#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* multiply(char* num1, char* num2) {
    // Edge case: If either num1 or num2 is "0", return "0"
    if (num1[0] == '0' || num2[0] == '0') {
        char* result = (char*)malloc(2 * sizeof(char));  // Only need "0"
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // Create an array to store the result of size len1 + len2
    int* result = (int*)calloc(len1 + len2, sizeof(int));

    // Multiply each digit and add to the appropriate position in the result
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';
            int product = digit1 * digit2;

            // Add the product to the result array, including any carry from the previous step
            int sum = product + result[i + j + 1];  // i + j + 1 is the correct index for the current product
            result[i + j + 1] = sum % 10;           // Store the ones place
            result[i + j] += sum / 10;              // Add the tens place to the next index
        }
    }

    // Convert the result array to a string
    int index = 0;
    // Skip leading zeros
    while (index < len1 + len2 && result[index] == 0) {
        index++;
    }

    // If index reaches len1 + len2, the result is "0"
    if (index == len1 + len2) {
        char* finalResult = (char*)malloc(2 * sizeof(char));  // "0"
        finalResult[0] = '0';
        finalResult[1] = '\0';
        free(result);
        return finalResult;
    }

    // Allocate memory for the result string
    char* finalResult = (char*)malloc((len1 + len2 - index + 1) * sizeof(char));
    int k = 0;
    // Convert the result array into a string
    while (index < len1 + len2) {
        finalResult[k++] = result[index++] + '0';
    }
    finalResult[k] = '\0';

    // Free the result array as it's no longer needed
    free(result);

    return finalResult;
}

// Example usage
int main() {
    char num1[] = "123";
    char num2[] = "456";

    char* result = multiply(num1, num2);
    printf("Multiplication result: %s\n", result);

    // Free the dynamically allocated memory
    free(result);

    return 0;
}
/*recur O(n*m)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to multiply single digit with the whole number (num2)
char* multiplySingleDigit(char* num1, char digit, int shift) {
    int carry = 0;
    int len1 = strlen(num1);
    int lenRes = len1 + shift + 1;  // Result length is original length + shift (for the place value)
    char* result = (char*)malloc(lenRes * sizeof(char)); 
    memset(result, '0', lenRes);  // Initialize the result with '0'

    for (int i = len1 - 1; i >= 0; i--) {
        int prod = (num1[i] - '0') * (digit - '0') + carry;
        result[i + shift] = (prod % 10) + '0';  // Store the digit at the appropriate place
        carry = prod / 10;  // Carry forward
    }

    if (carry) {
        result[shift] = carry + '0';
    }

    return result;
}

// Helper function to add two strings
char* addStrings(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int lenRes = (len1 > len2 ? len1 : len2) + 1;
    char* result = (char*)malloc(lenRes * sizeof(char));
    int carry = 0, i = len1 - 1, j = len2 - 1, k = lenRes - 1;

    // Add numbers from the end
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        result[k--] = (sum % 10) + '0';
        carry = sum / 10;
    }

    // Shift result to remove any leading zeros
    if (result[0] == '0') {
        memmove(result, result + 1, lenRes);
    }

    return result;
}

// Main recursive function to multiply two strings
char* multiply(char* num1, char* num2) {
    // Base case: if either string is "0", return "0"
    if (num1[0] == '0' || num2[0] == '0') {
        char* result = (char*)malloc(2 * sizeof(char));  // Just "0"
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    char* result = (char*)malloc((len1 + len2 + 1) * sizeof(char));  // Allocate memory for the result
    result[0] = '0';  // Initialize result to "0"

    // Iterate over each digit of num2, multiply by num1
    for (int i = len2 - 1; i >= 0; i--) {
        char digit = num2[i];
        char* partialResult = multiplySingleDigit(num1, digit, len2 - 1 - i);  // Multiply num1 by current digit of num2
        result = addStrings(result, partialResult);  // Add the partial result to the result
        free(partialResult);  // Free the partial result
    }

    return result;
}

// Example usage
int main() {
    char num1[] = "123";
    char num2[] = "456";

    char* result = multiply(num1, num2);
    printf("Multiplication result: %s\n", result);

    // Free the dynamically allocated memory
    free(result);

    return 0;
}
*/