#include <stdio.h>

int main() {
    char* words[] = {"Hello", "Alaska", "Dad", "Peace"};
    int wordsSize = 4;
    int returnSize;
    
    char** result = findWords(words, wordsSize, &returnSize);

    // Print the result
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
    }
    
    free(result); // Free the allocated memory for the result
    return 0;
}
int main() {
    char* words[] = {"Hello", "Alaska", "Dad", "Peace"};
    int wordsSize = 4;
    int returnSize;
    
    char** result = findWords(words, wordsSize, &returnSize);

    // Print the result
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
    }
    
    free(result); // Free the allocated memory for the result
    return 0;
}
/*recur O(n*m)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool canBeTypedFromOneRow(char* word) {
    // Define the three rows of the keyboard
    char row1[] = "qwertyuiop";
    char row2[] = "asdfghjkl";
    char row3[] = "zxcvbnm";
    
    // Convert the word to lowercase to handle case insensitivity
    for (int i = 0; word[i] != '\0'; i++) {
        word[i] = tolower(word[i]);
    }

    // Check if all characters in word belong to the same row
    bool inRow1 = false, inRow2 = false, inRow3 = false;

    // Check the first character and mark which row it belongs to
    for (int i = 0; row1[i] != '\0'; i++) {
        if (word[0] == row1[i]) inRow1 = true;
    }
    for (int i = 0; row2[i] != '\0'; i++) {
        if (word[0] == row2[i]) inRow2 = true;
    }
    for (int i = 0; row3[i] != '\0'; i++) {
        if (word[0] == row3[i]) inRow3 = true;
    }

    // Check if all other characters are in the same row
    for (int i = 1; word[i] != '\0'; i++) {
        bool found = false;
        if (inRow1) {
            for (int j = 0; row1[j] != '\0'; j++) {
                if (word[i] == row1[j]) {
                    found = true;
                    break;
                }
            }
        }
        if (inRow2) {
            for (int j = 0; row2[j] != '\0'; j++) {
                if (word[i] == row2[j]) {
                    found = true;
                    break;
                }
            }
        }
        if (inRow3) {
            for (int j = 0; row3[j] != '\0'; j++) {
                if (word[i] == row3[j]) {
                    found = true;
                    break;
                }
            }
        }
        if (!found) return false;
    }
    return true;
}

// Recursive function to process each word
void findWordsRecursive(char** words, int wordsSize, int index, char** result, int* returnSize) {
    if (index == wordsSize) return; // Base case: If we've checked all words

    if (canBeTypedFromOneRow(words[index])) {
        result[*returnSize] = words[index]; // Add valid word to the result
        (*returnSize)++;
    }

    findWordsRecursive(words, wordsSize, index + 1, result, returnSize); // Recursive call for the next word
}

// Wrapper function for the recursive approach
char** findWords(char** words, int wordsSize, int* returnSize) {
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;

    // Start recursion from the first word
    findWordsRecursive(words, wordsSize, 0, result, returnSize);

    return result;
}

// Example usage
int main() {
    char* words[] = {"Hello", "Alaska", "Dad", "Peace"};
    int wordsSize = 4;
    int returnSize;

    char** result = findWords(words, wordsSize, &returnSize);

    // Print the result
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
    }

    free(result); // Free the allocated memory for the result
    return 0;
}
*/