#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool canConstruct(char* ransomNote, char* magazine) {
    int charCount[26] = {0}; // Array to store counts of each character in the magazine

    // Count the occurrences of each character in the magazine
    for (int i = 0; magazine[i] != '\0'; i++) {
        charCount[magazine[i] - 'a']++;
    }

    // Check if ransomNote can be constructed
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        if (charCount[ransomNote[i] - 'a'] == 0) {
            return false; // Not enough of the required character
        }
        charCount[ransomNote[i] - 'a']--; // Use one occurrence of the character
    }

    return true; // All characters in ransomNote are available in magazine
}

int main() {
    char ransomNote[] = "aa";
    char magazine[] = "aab";

    if (canConstruct(ransomNote, magazine)) {
        printf("The ransom note can be constructed from the magazine.\n");
    } else {
        printf("The ransom note cannot be constructed from the magazine.\n");
    }

    return 0;
}
