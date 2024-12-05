#include <stdbool.h>
#include <ctype.h>

bool detectCapitalUse(char* word) {
    int n = 0;  // Variable to count the number of uppercase letters
    int length = 0;  // Variable to store the length of the word
    
    // Loop to count the number of uppercase letters and calculate the length of the word
    while (word[length]) {
        if (isupper(word[length])) {
            n++;  // Increment the count if the character is uppercase
        }
        length++;  // Increment the length
    }

    // Case 1: All letters are uppercase
    if (n == length) {
        return true;
    }

    // Case 2: All letters are lowercase
    if (n == 0) {
        return true;
    }

    // Case 3: Only the first letter is uppercase, rest are lowercase
    if (n == 1 && isupper(word[0])) {
        return true;
    }

    // If none of the above cases hold, return false
    return false;
}

int main() {
    // Example usage
    char* word = "Google";
    if (detectCapitalUse(word)) {
        printf("The word \"%s\" has a valid capitalization.\n", word);
    } else {
        printf("The word \"%s\" does not have a valid capitalization.\n", word);
    }

    return 0;
}
/*recur O(n)
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

// Recursive helper function to check the capital use in a word
bool detectCapitalUseRecursive(char* word, int length, int n) {
    if (word[length] == '\0') {
        // Base case: if we reach the end of the string, check the conditions
        if (n == length) { // All letters are uppercase
            return true;
        }
        if (n == 0) { // All letters are lowercase
            return true;
        }
        if (n == 1 && isupper(word[0])) { // Only the first letter is uppercase
            return true;
        }
        return false;
    }

    // If the current letter is uppercase, increment the count
    if (isupper(word[length])) {
        n++;
    }

    // Recursive call to check the next character
    return detectCapitalUseRecursive(word, length + 1, n);
}

bool detectCapitalUse(char* word) {
    return detectCapitalUseRecursive(word, 0, 0);
}

int main() {
    // Example usage
    char* word = "Google";
    if (detectCapitalUse(word)) {
        printf("The word \"%s\" has a valid capitalization.\n", word);
    } else {
        printf("The word \"%s\" does not have a valid capitalization.\n", word);
    }

    return 0;
}
*/