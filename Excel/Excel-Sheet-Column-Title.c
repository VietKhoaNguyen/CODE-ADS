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
<<<<<<< HEAD
/*recur O(log n)
=======
/*recursive O(log n)
>>>>>>> 5527a31819c76f85ec241af65a5c546360320eae
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
=======
// Helper function to build the title recursively
void convertToTitleHelper(int columnNumber, char* result, int* index) {
    // Base case: when the column number is zero, stop recursion
    if (columnNumber == 0) {
        return;
    }

    columnNumber--;  // Adjust for 1-based indexing
    result[*index] = 'A' + (columnNumber % 26); // Get the current character
    (*index)++; // Move to the next index
    
    // Recur on the quotient of the column number
    convertToTitleHelper(columnNumber / 26, result, index);
}

// Wrapper function to initialize the result string and start the recursion
>>>>>>> 5527a31819c76f85ec241af65a5c546360320eae
char* convertToTitle(int columnNumber) {
    // Allocate a string large enough to hold the maximum possible result
    char* result = (char*)malloc(20 * sizeof(char)); // Safe size for large column numbers
    int index = 0;

<<<<<<< HEAD
    // Convert the column number to a string representation
    while (columnNumber > 0) {
        columnNumber--; // Adjust for 1-based indexing
        result[index++] = 'A' + (columnNumber % 26); // Get the current character
        columnNumber /= 26; // Move to the next digit
    }

    result[index] = '\0'; // Null-terminate the string
=======
    // Call the helper function to fill the result string
    convertToTitleHelper(columnNumber, result, &index);

    // Null-terminate the string
    result[index] = '\0';
>>>>>>> 5527a31819c76f85ec241af65a5c546360320eae

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
<<<<<<< HEAD
*/
=======
*/
>>>>>>> 5527a31819c76f85ec241af65a5c546360320eae
