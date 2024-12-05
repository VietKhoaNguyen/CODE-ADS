#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse(char* s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

char* reverseWords(char* s) {
    int len = strlen(s);

    // Step 1: Reverse the entire string
    reverse(s, 0, len - 1);

    // Step 2: Reverse each word in the string
    int start = 0;
    for (int i = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            // Reverse the word between start and i-1
            reverse(s, start, i - 1);
            start = i + 1;
        }
    }

    // Step 3: Remove leading/trailing spaces (optional, as per problem definition)
    int left = 0, right = len - 1;

    // Remove leading spaces
    while (s[left] == ' ') {
        left++;
    }

    // Remove trailing spaces
    while (s[right] == ' ') {
        right--;
    }

    // Shift the string to remove spaces and null terminate
    memmove(s, s + left, right - left + 1);
    s[right - left + 1] = '\0';

    return s;
}

int main() {
    char str[] = "  the sky is blue  ";  // Test case with leading/trailing spaces
    printf("Reversed words: '%s'\n", reverseWords(str));  // Expected output: "blue is sky the"
    return 0;
}
