#include <stdio.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n == 0) {
        return "";
    }

    // Variables to store the start and end indices of the longest palindrome
    int start = 0, end = 0;

    // Helper function to expand around the center
    // Left and right are the starting points of the palindrome center
    void expandAroundCenter(int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        // Update the start and end indices if we found a longer palindrome
        if (right - left - 1 > end - start) {
            start = left + 1;
            end = right - 1;
        }
    }

    // Loop through each character in the string
    for (int i = 0; i < n; i++) {
        // Odd-length palindromes (single character center)
        expandAroundCenter(i, i);
        // Even-length palindromes (two character center)
        expandAroundCenter(i, i + 1);
    }

    // Create the substring for the longest palindrome
    int len = end - start + 1;
    char* result = (char*)malloc((len + 1) * sizeof(char));
    strncpy(result, s + start, len);
    result[len] = '\0'; // Null-terminate the string

    return result;
}
int main() {
    char s[] = "babad";
    char* result = longestPalindrome(s);
    printf("Longest Palindrome: %s\n", result); // Output: "bab" or "aba"

    char s2[] = "cbbd";
    result = longestPalindrome(s2);
    printf("Longest Palindrome: %s\n", result); // Output: "bb"

    return 0;
}