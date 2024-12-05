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
/*recur O(n)
#include <stdio.h>
#include <string.h>

// Recursive function to count the frequency of characters in the string
void countCharFrequency(char* s, int index, int* charCount) {
    if (s[index] == '\0') {
        return;  // Base case: end of the string
    }

    // Increment the frequency of the current character
    charCount[s[index]]++;

    // Recursive call to the next character
    countCharFrequency(s, index + 1, charCount);
}

// Recursive function to calculate the length of the longest palindrome
int calculatePalindromeLength(int* charCount, int index, int length, int oddFound) {
    if (index == 128) {
        // If we have processed all characters
        if (oddFound) {
            length += 1;  // Add 1 for the center of the palindrome
        }
        return length;
    }

    if (charCount[index] % 2 == 0) {
        length += charCount[index];  // Add even frequencies fully
    } else {
        length += charCount[index] - 1;  // Add the largest even part of odd frequencies
        oddFound = 1;  // At least one character has an odd count
    }

    // Recursive call to the next character
    return calculatePalindromeLength(charCount, index + 1, length, oddFound);
}

int longestPalindrome(char* s) {
    int charCount[128] = {0};  // Assuming ASCII characters, we need 128 slots for all characters

    // Start the recursive character counting
    countCharFrequency(s, 0, charCount);

    // Start the recursive palindrome length calculation
    return calculatePalindromeLength(charCount, 0, 0, 0);
}

int main() {
    char s[] = "abccccdd";
    int result = longestPalindrome(s);
    printf("The length of the longest palindrome that can be formed is: %d\n", result);

    return 0;
}
*/