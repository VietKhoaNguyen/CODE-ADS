#include <stdio.h>
#include <stdlib.h>

char* toHex(int num) {
    if (num == 0) {
        // Special case for zero
        char* result = (char*)malloc(2 * sizeof(char));  // Space for "0" and null terminator
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    // Array to store the hexadecimal characters
    char hexDigits[] = "0123456789abcdef";
    char* result = (char*)malloc(9 * sizeof(char));  // Space for 8 characters + null terminator
    int index = 0;

    // Iterate to process the number
    while (num != 0) {
        result[index++] = hexDigits[num & 0xF];  // Get the last hex digit
        num >>= 4;  // Right shift by 4 bits to process the next hex digit
    }

    // Null-terminate the string
    result[index] = '\0';

    // Reverse the string to get the correct order
    for (int i = 0; i < index / 2; i++) {
        char temp = result[i];
        result[i] = result[index - 1 - i];
        result[index - 1 - i] = temp;
    }

    return result;
}

int main() {
    int num = 26;  // Example input
    char* hexStr = toHex(num);
    printf("Hexadecimal representation of %d is %s\n", num, hexStr);

    free(hexStr);  // Free allocated memory
    return 0;
}
/*recur O(log n)
#include <stdio.h>
#include <stdlib.h>

// Helper function to convert the number to hex recursively
void toHexRecursive(int num, char* result, int* index) {
    if (num == 0) {
        return;  // Base case: stop recursion when num becomes 0
    }

    // Recursively call for the next 4 bits
    toHexRecursive(num >> 4, result, index);

    // Get the last 4 bits and store the corresponding hex digit
    char hexDigits[] = "0123456789abcdef";
    result[*index] = hexDigits[num & 0xF];
    (*index)++;  // Increment the index for the next digit
}

char* toHex(int num) {
    if (num == 0) {
        // Special case for zero
        char* result = (char*)malloc(2 * sizeof(char));  // Space for "0" and null terminator
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    // Allocate memory for the result (max 8 hex digits + null terminator)
    char* result = (char*)malloc(9 * sizeof(char));
    int index = 0;

    // Start the recursion to fill in the result
    toHexRecursive(num, result, &index);

    // Null-terminate the string
    result[index] = '\0';

    return result;
}

int main() {
    int num = 26;  // Example input
    char* hexStr = toHex(num);
    printf("Hexadecimal representation of %d is %s\n", num, hexStr);

    free(hexStr);  // Free allocated memory
    return 0;
}
*/