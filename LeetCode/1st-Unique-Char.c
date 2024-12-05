#include <stdio.h>
#include <string.h>

int firstUniqChar(char* s) {
    int charCount[26] = {0}; // Array to store counts of each character
    int length = strlen(s);

    // Count the occurrences of each character in the string
    for (int i = 0; i < length; i++) {
        charCount[s[i] - 'a']++;
    }

    // Find the first character with a count of 1
    for (int i = 0; i < length; i++) {
        if (charCount[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1; // Return -1 if no unique character is found
}

int main() {
    char s[] = "loveleetcode";
    int index = firstUniqChar(s);

    if (index != -1) {
        printf("The first unique character is '%c' at index %d.\n", s[index], index);
    } else {
        printf("There is no unique character in the string.\n");
    }

    return 0;
}
/* Recursive approach                                   O(n)
#include <stdio.h>
#include <string.h>

// Function to recursively count character frequencies
void countCharacters(char* s, int* charCount, int index) {
    if (s[index] == '\0') {
        return;  // Base case: end of the string
    }
    charCount[s[index] - 'a']++;  // Increment the count for the current character
    countCharacters(s, charCount, index + 1);  // Recur for the next character
}

// Function to find the first unique character recursively
int findFirstUnique(char* s, int* charCount, int index) {
    if (s[index] == '\0') {
        return -1;  // Base case: end of the string
    }
    if (charCount[s[index] - 'a'] == 1) {
        return index;  // Return the index if the character is unique
    }
    return findFirstUnique(s, charCount, index + 1);  // Recur for the next character
}

// Wrapper function for finding the first unique character
int firstUniqChar(char* s) {
    int charCount[26] = {0};  // Array to store counts of each character

    // Step 1: Count characters recursively
    countCharacters(s, charCount, 0);

    // Step 2: Find the first unique character recursively
    return findFirstUnique(s, charCount, 0);
}

// Main function to test the implementation
int main() {
    char s[] = "loveleetcode";
    int index = firstUniqChar(s);

    if (index != -1) {
        printf("The first unique character is '%c' at index %d.\n", s[index], index);
    } else {
        printf("There is no unique character in the string.\n");
    }

    return 0;
}
*/