#include <stdio.h>
#include <string.h>

int longestPalindrome(char* s) {
    int charCount[128] = {0};  // Assuming ASCII characters, we need 128 slots for all characters.
    int length = 0;
    int oddFound = 0;

    // Count the frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        charCount[s[i]]++;
    }

    // Calculate the length of the longest palindrome
    for (int i = 0; i < 128; i++) {
        if (charCount[i] % 2 == 0) {
            length += charCount[i];  // Add even frequencies fully
        } else {
            length += charCount[i] - 1;  // Add the largest even part of odd frequencies
            oddFound = 1;  // At least one character has an odd count
        }
    }

    // If there is any character with an odd count, we can place one in the middle of the palindrome
    if (oddFound) {
        length += 1;
    }

    return length;
}

int main() {
    char s[] = "abccccdd";
    int result = longestPalindrome(s);
    printf("The length of the longest palindrome that can be formed is: %d\n", result);

    return 0;
}
