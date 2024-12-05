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
}

// Example usage
int main() {
    char columnTitle[] = "ZY"; // Example: Column "ZY"
    int columnNumber = titleToNumber(columnTitle);
    printf("Column Title: %s, Column Number: %d\n", columnTitle, columnNumber);
    return 0;
}
*/