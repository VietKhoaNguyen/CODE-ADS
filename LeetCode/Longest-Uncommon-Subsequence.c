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
