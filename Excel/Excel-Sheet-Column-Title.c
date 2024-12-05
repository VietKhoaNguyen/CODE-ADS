#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convertToTitle(int columnNumber) {
    // Allocate a string large enough to hold the maximum possible result
    char* result = (char*)malloc(20 * sizeof(char)); // Safe size for large column numbers
    int index = 0;

    // Convert the column number to a string representation
    while (columnNumber > 0) {
        columnNumber--; // Adjust for 1-based indexing
        result[index++] = 'A' + (columnNumber % 26); // Get the current character
        columnNumber /= 26; // Move to the next digit
    }

    result[index] = '\0'; // Null-terminate the string

    // Reverse the string since we calculated it backward
    int start = 0, end = index - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }

    return result;
}

// Example usage
int main() {
    int columnNumber = 701; // Example: column number for "ZY"
    char* columnTitle = convertToTitle(columnNumber);
    printf("Column Number: %d, Column Title: %s\n", columnNumber, columnTitle);

    free(columnTitle); // Free the allocated memory
    return 0;
}
