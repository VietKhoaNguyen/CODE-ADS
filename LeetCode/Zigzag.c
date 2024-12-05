#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    // Edge case: if there is only one row or empty string, return the string as is
    if (numRows == 1 || strlen(s) <= numRows) {
        return s;
    }

    int len = strlen(s);
    // Create an array of strings to represent each row
    char* rows[numRows];
    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc((len + 1) * sizeof(char)); // Allocate space for each row
        memset(rows[i], '\0', len + 1); // Initialize each row with a null character
    }

    int currentRow = 0; // Start at the first row
    int goingDown = 0;  // Flag to indicate whether we're going down or up in the zigzag pattern

    // Traverse the string and place characters in the appropriate row
    for (int i = 0; i < len; i++) {
        rows[currentRow][strlen(rows[currentRow])] = s[i]; // Add character to the current row
        
        // Change direction if we reach the top or bottom row
        if (currentRow == 0 || currentRow == numRows - 1) {
            goingDown = !goingDown; // Toggle the direction
        }

        // Move up or down to the next row
        currentRow += goingDown ? 1 : -1;
    }

    // Concatenate all the rows to form the final result
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;
    for (int i = 0; i < numRows; i++) {
        int j = 0;
        while (rows[i][j] != '\0') {
            result[index++] = rows[i][j++];
        }
    }
    result[index] = '\0'; // Null terminate the result

    // Free the memory allocated for each row
    for (int i = 0; i < numRows; i++) {
        free(rows[i]);
    }

    return result;
}
int main() {
    char s[] = "PAYPALISHIRING";
    int numRows = 3;

    char* result = convert(s, numRows);
    printf("Converted String: %s\n", result);  // Output: "PAHNAPLSIIGYIR"

    free(result); // Free the dynamically allocated memory
    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    // Edge case: if there is only one row or empty string, return the string as is
    if (numRows == 1 || strlen(s) <= numRows) {
        return s;
    }

    int len = strlen(s);
    // Create an array of strings to represent each row
    char* rows[numRows];
    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc((len + 1) * sizeof(char)); // Allocate space for each row
        memset(rows[i], '\0', len + 1); // Initialize each row with a null character
    }

    int currentRow = 0; // Start at the first row
    int goingDown = 0;  // Flag to indicate whether we're going down or up in the zigzag pattern

    // Traverse the string and place characters in the appropriate row
    for (int i = 0; i < len; i++) {
        rows[currentRow][strlen(rows[currentRow])] = s[i]; // Add character to the current row
        
        // Change direction if we reach the top or bottom row
        if (currentRow == 0 || currentRow == numRows - 1) {
            goingDown = !goingDown; // Toggle the direction
        }

        // Move up or down to the next row
        currentRow += goingDown ? 1 : -1;
    }

    // Concatenate all the rows to form the final result
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;
    for (int i = 0; i < numRows; i++) {
        int j = 0;
        while (rows[i][j] != '\0') {
            result[index++] = rows[i][j++];
        }
    }
    result[index] = '\0'; // Null terminate the result

    // Free the memory allocated for each row
    for (int i = 0; i < numRows; i++) {
        free(rows[i]);
    }

    return result;
}

int main() {
    char s[] = "PAYPALISHIRING";
    int numRows = 3;

    char* result = convert(s, numRows);
    printf("Converted String: %s\n", result);  // Output: "PAHNAPLSIIGYIR"

    free(result); // Free the dynamically allocated memory
    return 0;
}
*/