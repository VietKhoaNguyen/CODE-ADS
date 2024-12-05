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
}

// Example usage
int main() {
    char columnTitle[] = "ZY"; // Example: Column "ZY"
    int columnNumber = titleToNumber(columnTitle);
    printf("Column Title: %s, Column Number: %d\n", columnTitle, columnNumber);
    return 0;
}
*/
