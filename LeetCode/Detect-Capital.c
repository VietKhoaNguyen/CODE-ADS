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
