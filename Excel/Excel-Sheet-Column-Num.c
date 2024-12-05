#include <stdio.h>
#include <string.h>

int titleToNumber(char* columnTitle) {
    int result = 0;

    // Traverse each character in the column title
    for (int i = 0; columnTitle[i] != '\0'; i++) {
        result = result * 26 + (columnTitle[i] - 'A' + 1);
    }

    return result;
}

// Example usage
int main() {
    char columnTitle[] = "ZY"; // Example: Column "ZY"
    int columnNumber = titleToNumber(columnTitle);
    printf("Column Title: %s, Column Number: %d\n", columnTitle, columnNumber);
    return 0;
}
<<<<<<< HEAD
/*recur O(n)
#include <stdio.h>
#include <string.h>

// Recursive helper function to process each character
int titleToNumberRecursive(char* columnTitle, int length) {
    // Base case: if we have processed all characters, return 0
    if (length == 0) {
        return 0;
    }

    // Recursive case: process the current character and add to the result
    int currentValue = columnTitle[0] - 'A' + 1;
    return currentValue * (1 << (length - 1) * 5) + titleToNumberRecursive(columnTitle + 1, length - 1); 
}

// Wrapper function for easier interface
int titleToNumber(char* columnTitle) {
    int length = strlen(columnTitle);
    return titleToNumberRecursive(columnTitle, length);
=======
/*Rcursive O(n)
#include <stdio.h>
#include <string.h>

int titleToNumberHelper(char* columnTitle, int index, int length) {
    // Base case: when we've processed all characters
    if (index == length) {
        return 0;
    }

    // Recursive step: Get the value of the current character
    int currentValue = columnTitle[index] - 'A' + 1;
    
    // Process the rest of the string
    return currentValue * (1 << (26 * (length - index - 1))) + titleToNumberHelper(columnTitle, index + 1, length);
}

int titleToNumber(char* columnTitle) {
    int length = strlen(columnTitle);
    return titleToNumberHelper(columnTitle, 0, length);
>>>>>>> 5527a31819c76f85ec241af65a5c546360320eae
}

// Example usage
int main() {
    char columnTitle[] = "ZY"; // Example: Column "ZY"
    int columnNumber = titleToNumber(columnTitle);
    printf("Column Title: %s, Column Number: %d\n", columnTitle, columnNumber);
    return 0;
}
<<<<<<< HEAD
*/
=======
*/
>>>>>>> 5527a31819c76f85ec241af65a5c546360320eae
