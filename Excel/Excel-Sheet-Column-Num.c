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
