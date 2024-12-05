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
/*recur O(n^2)
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Recursive helper function to check if a substring can form the entire string
bool checkRepeatedPattern(char* s, int start, int len) {
    int n = strlen(s);
    for (int i = start; i < n; i++) {
        if (s[i] != s[i % len]) {
            return false;  // If characters do not match, it's not a valid pattern
        }
    }
    return true;  // All characters matched
}

// Function to check if a string can be constructed by repeating a substring
bool repeatedSubstringPattern(char* s) {
    int len = strlen(s);
    
    // Try all possible lengths for the repeating substring
    for (int i = 1; i <= len / 2; i++) {  // Only need to check up to half the length
        if (len % i == 0 && checkRepeatedPattern(s, i, i)) {
            return true;  // If a valid substring is found, return true
        }
    }

    return false;  // No valid substring found
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
*/