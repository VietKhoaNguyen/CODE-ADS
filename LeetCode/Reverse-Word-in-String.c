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
/*recur O(n)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse(char* s, int start, int end) {
    if (start >= end) {
        return;  // Base case: stop when pointers cross
    }
    // Swap characters at start and end
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    // Recurse by moving the pointers inward
    reverse(s, start + 1, end - 1);
}

// Helper function to reverse each word in the string
void reverseWordsRecursive(char* s, int start, int len) {
    if (start >= len) {
        return;  // Base case: end recursion when we reach the end of the string
    }

    // Find the next space or end of string
    int end = start;
    while (end < len && s[end] != ' ') {
        end++;
    }

    // Reverse the word between start and end-1
    reverse(s, start, end - 1);

    // Skip the space and recurse to the next word
    reverseWordsRecursive(s, end + 1, len);
}

char* reverseWords(char* s) {
    int len = strlen(s);

    // Step 1: Reverse the entire string
    reverse(s, 0, len - 1);

    // Step 2: Reverse each word in the string
    reverseWordsRecursive(s, 0, len);

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
*/