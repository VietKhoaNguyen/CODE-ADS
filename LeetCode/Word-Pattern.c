#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Helper function to split the string into words
char** splitString(char* str, int* returnSize) {
    char** result = malloc(100 * sizeof(char*));  // Allocate memory for words array
    char* word = strtok(str, " ");
    int size = 0;
    
    while (word != NULL) {
        result[size++] = word;
        word = strtok(NULL, " ");
    }
    
    *returnSize = size;
    return result;
}

bool wordPattern(char* pattern, char* s) {
    int sSize;
    char** words = splitString(s, &sSize);
    
    // If the number of words does not match the length of the pattern, return false
    if (strlen(pattern) != sSize) {
        return false;
    }
    
    // Create two hash maps (using arrays for simplicity)
    char patternMap[256] = {0}; // Maps characters in pattern to words
    char wordMap[256] = {0};    // Maps words to characters

    // Iterate through the pattern and words
    for (int i = 0; i < sSize; i++) {
        char pChar = pattern[i];
        char* word = words[i];
        
        // Check if pattern character has been mapped
        if (patternMap[pChar] != 0) {
            // If already mapped, it should match the current word
            if (patternMap[pChar] != word[0]) {
                return false;
            }
        } else {
            patternMap[pChar] = word[0];  // Map pattern character to first char of the word
        }
        
        // Check if word has been mapped to a pattern character
        if (wordMap[word[0]] != 0) {
            // If already mapped, it should match the current pattern character
            if (wordMap[word[0]] != pChar) {
                return false;
            }
        } else {
            wordMap[word[0]] = pChar;  // Map word's first character to the pattern character
        }
    }
    
    return true;
}

// Helper function to test the solution
int main() {
    char pattern[] = "abba";
    char s[] = "dog cat cat dog";
    
    if (wordPattern(pattern, s)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
