#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    // Edge case: If needle is an empty string, return 0
    if (*needle == '\0') {
        return 0;
    }

    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    // If the needle is longer than the haystack, return -1
    if (needle_len > haystack_len) {
        return -1;
    }

    // Iterate over haystack
    for (int i = 0; i <= haystack_len - needle_len; i++) {
        // Compare substring of haystack with needle
        int j = 0;
        while (j < needle_len && haystack[i + j] == needle[j]) {
            j++;
        }
        
        // If we have found a match
        if (j == needle_len) {
            return i;
        }
    }
    
    // Return -1 if no match is found
    return -1;
}

// Main function for testing
int main() {
    char haystack[] = "hello";
    char needle[] = "ll";
    
    int index = strStr(haystack, needle);
    printf("The first occurrence of '%s' in '%s' is at index %d.\n", needle, haystack, index);
    
    return 0;
}
