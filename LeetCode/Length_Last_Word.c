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
/*recur O(n)
#include <stdio.h>
#include <string.h>

int lengthOfLastWordRecursive(char* s, int length) {
    // Base case: if the string is empty or we have reached the beginning
    if (length == 0) {
        return 0;
    }

    // Skip trailing spaces
    if (s[length - 1] == ' ') {
        return lengthOfLastWordRecursive(s, length - 1);  // Recursive call to skip the space
    }

    // Check if it's part of the last word
    int count = 0;
    // Count the characters until we hit a space or reach the beginning of the string
    while (length > 0 && s[length - 1] != ' ') {
        count++;
        length--;
    }

    return count;
}

int lengthOfLastWord(char* s) {
    int length = strlen(s);
    return lengthOfLastWordRecursive(s, length);
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
*/