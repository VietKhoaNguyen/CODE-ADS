#include <stdio.h>
#include <string.h>

// Helper function to find the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

char* gcdOfStrings(char* str1, char* str2) {
    // Check if str1 + str2 == str2 + str1, which is a necessary condition
    if (strcmp(str1, str2) == 0) {
        return str1; 
    }
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // If str1 + str2 is not equal to str2 + str1, return an empty string
    if (strcmp(str1, str2) != 0) {
        return "";
    }

    int commonLength = gcd(len1, len2); // Compute the GCD of the lengths of the two strings

    // Return the prefix of str1 that has the length of the GCD of the two string lengths
    char* result = (char*)malloc((commonLength + 1) * sizeof(char)); // Allocate memory for the result
    strncpy(result, str1, commonLength); // Copy the substring of length commonLength
    result[commonLength] = '\0'; // Null-terminate the string
    
    return result;
}

int main() {
    char str1[] = "ABABAB";
    char str2[] = "ABAB";

    char* result = gcdOfStrings(str1, str2);
    printf("GCD of strings: %s\n", result);  // Output should be "AB"
    free(result);  // Free allocated memory
    return 0;
}
/*reur O(len1 + len2)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Recursive function to find the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

char* gcdOfStrings(char* str1, char* str2) {
    // If concatenating str1 + str2 is not equal to str2 + str1, return an empty string
    if (strlen(str1) < strlen(str2)) {
        return gcdOfStrings(str2, str1);  // Ensure str1 is always the longer one
    }
    
    // Base case: if str1 is a prefix of str2
    if (strcmp(str1, str2) == 0)
        return str1;
    
    // Recursive case: get the GCD of the lengths of str1 and str2
    int commonLength = gcd(strlen(str1), strlen(str2));

    // If str1 and str2 have a common substring, return that substring
    if (strncmp(str1, str2, commonLength) == 0) {
        char* result = (char*)malloc((commonLength + 1) * sizeof(char));
        strncpy(result, str1, commonLength);  // Get the common prefix of length commonLength
        result[commonLength] = '\0';  // Null-terminate the result
        return result;
    }

    return "";  // If no common divisor found, return an empty string
}

int main() {
    char str1[] = "ABABAB";
    char str2[] = "ABAB";

    char* result = gcdOfStrings(str1, str2);
    printf("GCD of strings: %s\n", result);  // Output should be "AB"
    free(result);  // Free the allocated memory
    return 0;
}
*/