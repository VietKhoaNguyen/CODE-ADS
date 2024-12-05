#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    // If the lengths of the two strings are not the same, they can't be anagrams
    if (strlen(s) != strlen(t)) {
        return false;
    }

    // Create an array to store the frequency of characters
    int charCount[26] = {0};

    // Traverse both strings and update the count of characters
    for (int i = 0; s[i] != '\0'; i++) {
        charCount[s[i] - 'a']++;  // Increment the count for character in s
        charCount[t[i] - 'a']--;  // Decrement the count for character in t
    }

    // If all counts are zero, then the strings are anagrams
    for (int i = 0; i < 26; i++) {
        if (charCount[i] != 0) {
            return false;
        }
    }

    return true;
}
