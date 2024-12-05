#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s); // Length of the input string
    if (n == 0) return 0;

    int maxLength = 0; // To store the maximum length of the substring
    int start = 0; // Start index of the current substring
    int charIndex[128]; // Array to store the last index of each character

    // Initialize all characters' indices to -1
    for (int i = 0; i < 128; i++) {
        charIndex[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        char currentChar = s[i];

        // If the character is already in the substring, move the start index
        if (charIndex[currentChar] >= start) {
            start = charIndex[currentChar] + 1;
        }

        // Update the last seen index of the current character
        charIndex[currentChar] = i;

        // Calculate the maximum length of the substring
        int currentLength = i - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}
int main() {
    char s[] = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    printf("Length of the longest substring: %d\n", result); // Output: 3

    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <string.h>

int helper(char* s, int start, int i, int* charIndex) {
    if (s[i] == '\0') {  // Base case: end of string
        return 0;
    }

    char currentChar = s[i];
    int currentLength = i - start + 1;

    // If the character has appeared before in the substring, move the start index
    if (charIndex[currentChar] >= start) {
        start = charIndex[currentChar] + 1;
    }

    // Update the last seen index of the current character
    charIndex[currentChar] = i;

    // Recurse to the next character and return the maximum length found so far
    int lengthFromNextChar = helper(s, start, i + 1, charIndex);

    // Return the maximum of the current substring length and the result from the recursion
    return currentLength > lengthFromNextChar ? currentLength : lengthFromNextChar;
}

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;

    int charIndex[128] = {0}; // To store the last index of each character
    for (int i = 0; i < 128; i++) {
        charIndex[i] = -1;  // Initialize all indices to -1
    }

    return helper(s, 0, 0, charIndex);
}

int main() {
    char s[] = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    printf("Length of the longest substring: %d\n", result); // Output: 3

    return 0;
}
*/