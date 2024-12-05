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
/*recur O((n-m+1)*m)
#include <stdio.h>
#include <string.h>

// Helper function to perform recursive string search
int recursiveStrStr(char* haystack, char* needle, int haystack_index) {
    // Base case: if the needle is empty, return the current index
    if (*needle == '\0') {
        return haystack_index;
    }

    // If we reached the end of the haystack, no match found
    if (*haystack == '\0') {
        return -1;
    }

    // If the first character of haystack matches the first of needle
    if (*haystack == *needle) {
        // Check the rest of the needle recursively
        int result = recursiveStrStr(haystack + 1, needle + 1, haystack_index);
        // If result is -1, continue searching in the haystack
        if (result != -1) {
            return result;
        }
    }

    // If no match at the current index, move to the next character in haystack
    return recursiveStrStr(haystack + 1, needle, haystack_index + 1);
}

// Main strStr function to initiate recursion
int strStr(char* haystack, char* needle) {
    // Edge case: If needle is an empty string, return 0
    if (*needle == '\0') {
        return 0;
    }

    return recursiveStrStr(haystack, needle, 0);
}

// Main function for testing
int main() {
    char haystack[] = "hello";
    char needle[] = "ll";

    int index = strStr(haystack, needle);
    printf("The first occurrence of '%s' in '%s' is at index %d.\n", needle, haystack, index);

    return 0;
}
*/