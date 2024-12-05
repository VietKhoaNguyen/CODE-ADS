#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char* licenseKeyFormatting(char* s, int k) {
    // Count valid characters and ignore existing dashes
    int validCount = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '-') {
            validCount++;
        }
    }
    
    // Calculate the length of the reformatted string
    int newLength = validCount + (validCount - 1) / k;
    char* result = (char*)malloc((newLength + 1) * sizeof(char));
    if (!result) return NULL; // Handle memory allocation failure

    int index = newLength - 1; // Index for the result array
    int count = 0; // Track characters in the current group

    // Iterate through the input string in reverse
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] != '-') {
            // Add the character to the result (convert to uppercase)
            result[index--] = toupper(s[i]);
            count++;
            if (count == k && index >= 0) {
                // Insert a dash after every group of k characters
                result[index--] = '-';
                count = 0;
            }
        }
    }

    // Handle potential leading dash
    if (index == -1) {
        // Move the string forward to remove the leading dash
        memmove(result, result + 1, newLength);
        newLength--;
    }

    result[newLength] = '\0'; // Null-terminate the string
    return result;
}

int main() {
    char s[] = "2-5g-3-J";
    int k = 2;
    char* formatted = licenseKeyFormatting(s, k);
    printf("%s\n", formatted); // Output: "2-5G-3J"
    free(formatted); // Free the allocated memory
    return 0;
}