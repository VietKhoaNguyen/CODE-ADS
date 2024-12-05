#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool repeatedSubstringPattern(char* s) {
    int len = strlen(s);

    // Create a new string that is s + s
    char doubled[2 * len + 1];
    strcpy(doubled, s);
    strcat(doubled, s);

    // Check if the original string appears as a substring in doubled, starting from index 1
    for (int i = 1; i < len; i++) {
        if (strncmp(doubled + i, s, len) == 0) {
            return true;
        }
    }
    
    return false;
}

int main() {
    char* s = "abab";
    if (repeatedSubstringPattern(s)) {
        printf("The string can be constructed by repeating a substring.\n");
    } else {
        printf("The string cannot be constructed by repeating a substring.\n");
    }
    return 0;
}
