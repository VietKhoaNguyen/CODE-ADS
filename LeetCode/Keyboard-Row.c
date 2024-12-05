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