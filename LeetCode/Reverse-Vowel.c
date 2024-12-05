#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Function to check if a character is a vowel
bool isVowel(char c) {
    char lower = tolower(c);  // Convert to lowercase to handle both cases
    return (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u');
}

// Function to reverse the vowels in the string
char* reverseVowels(char* s) {
    int left = 0;
    int right = 0;

    // Find the length of the string
    while (s[right] != '\0') {
        right++;
    }
    right--;  // right now points to the last character of the string

    // Swap vowels using two pointers
    while (left < right) {
        // Move left pointer until we find a vowel
        if (!isVowel(s[left])) {
            left++;
            continue;
        }
        
        // Move right pointer until we find a vowel
        if (!isVowel(s[right])) {
            right--;
            continue;
        }

        // Swap the vowels
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        // Move both pointers inward
        left++;
        right--;
    }

    return s;
}

// Function to print the string (for testing)
void printString(char* s) {
    printf("%s\n", s);
}

int main() {
    // Test case 1: Reverse vowels in a string
    char str1[] = "hello";
    printf("Before: ");
    printString(str1);
    
    reverseVowels(str1);
    
    printf("After: ");
    printString(str1);

    // Test case 2: Reverse vowels in another string
    char str2[] = "leetcode";
    printf("Before: ");
    printString(str2);
    
    reverseVowels(str2);
    
    printf("After: ");
    printString(str2);
    
    return 0;
}
