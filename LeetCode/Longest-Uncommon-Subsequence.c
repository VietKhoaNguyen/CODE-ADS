#include <stdio.h>
#include <string.h>

int findLUSlength(char* a, char* b) {
    // If the strings are equal, no uncommon subsequence exists
    if (strcmp(a, b) == 0) {
        return -1;
    }
    
    // If the strings are different, return the maximum length of either string
    return strlen(a) > strlen(b) ? strlen(a) : strlen(b);
}

int main() {
    // Test cases
    char* a = "abc";
    char* b = "def";
    printf("LUS length for \"%s\" and \"%s\": %d\n", a, b, findLUSlength(a, b));

    char* c = "abc";
    char* d = "abc";
    printf("LUS length for \"%s\" and \"%s\": %d\n", c, d, findLUSlength(c, d));

    char* e = "abcd";
    char* f = "xyz";
    printf("LUS length for \"%s\" and \"%s\": %d\n", e, f, findLUSlength(e, f));

    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <string.h>

int compareStringsRecursive(char* a, char* b, int index) {
    // Base case: If both strings have been compared fully and are equal, return 0
    if (a[index] == '\0' && b[index] == '\0') {
        return 0;
    }
    
    // If one string ends and the other does not, or if characters differ, return -1
    if (a[index] != b[index]) {
        return 1;
    }
    
    // Recurse for the next character
    return compareStringsRecursive(a, b, index + 1);
}

int findLUSlength(char* a, char* b) {
    // If strings are equal, return -1
    if (compareStringsRecursive(a, b, 0) == 0) {
        return -1;
    }

    // If strings are different, return the maximum length of either string
    int lengthA = strlen(a);
    int lengthB = strlen(b);
    
    return lengthA > lengthB ? lengthA : lengthB;
}

int main() {
    // Test cases
    char* a = "abc";
    char* b = "def";
    printf("LUS length for \"%s\" and \"%s\": %d\n", a, b, findLUSlength(a, b));

    char* c = "abc";
    char* d = "abc";
    printf("LUS length for \"%s\" and \"%s\": %d\n", c, d, findLUSlength(c, d));

    char* e = "abcd";
    char* f = "xyz";
    printf("LUS length for \"%s\" and \"%s\": %d\n", e, f, findLUSlength(e, f));

    return 0;
}
*/