#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    int length = 0;
    int i = strlen(s) - 1;  // Start from the end of the string
    
    // Skip any trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    
    // Count the characters of the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }
    
    return length;
}

// Main function for testing
int main() {
    char s[] = "Hello World  ";
    int result = lengthOfLastWord(s);
    printf("Length of last word: %d\n", result);  // Expected output: 5
    
    char s2[] = "   ";
    result = lengthOfLastWord(s2);
    printf("Length of last word: %d\n", result);  // Expected output: 0
    
    char s3[] = "   fly me to the moon   ";
    result = lengthOfLastWord(s3);
    printf("Length of last word: %d\n", result);  // Expected output: 4
    
    return 0;
}
