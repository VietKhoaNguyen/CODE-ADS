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
/*recur O(n)
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAnagramRecursive(char* s, char* t, int index, int* charCount) {
    // Base case: if we have processed all characters, check if the counts are all zero
    if (s[index] == '\0') {
        for (int i = 0; i < 26; i++) {
            if (charCount[i] != 0) {
                return false;
            }
        }
        return true;
    }

    // Update the character counts for the current character at index
    charCount[s[index] - 'a']++;
    charCount[t[index] - 'a']--;

    // Recur for the next index
    return isAnagramRecursive(s, t, index + 1, charCount);
}

bool isAnagram(char* s, char* t) {
    // If the lengths of the two strings are not the same, they can't be anagrams
    if (strlen(s) != strlen(t)) {
        return false;
    }

    // Create an array to store the frequency of characters
    int charCount[26] = {0};

    // Start the recursion from index 0
    return isAnagramRecursive(s, t, 0, charCount);
}

// Example usage
int main() {
    char s[] = "anagram";
    char t[] = "nagaram";
    
    if (isAnagram(s, t)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", s, t);
    } else {
        printf("\"%s\" and \"%s\" are not anagrams.\n", s, t);
    }

    return 0;
}
*/