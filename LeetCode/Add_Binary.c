#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    
    // The maximum length of the result could be the longer of the two strings + 1 (for carry)
    int maxLen = (lenA > lenB) ? lenA : lenB;
    char* result = (char*)malloc((maxLen + 2) * sizeof(char));  // +2 for potential carry and null terminator
    if (!result) {
        return NULL;  // If memory allocation fails
    }
    
    int i = lenA - 1, j = lenB - 1, k = 0;
    int carry = 0;
    
    // Add corresponding bits from both strings
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        
        // Add bit from string a if available
        if (i >= 0) {
            sum += a[i] - '0';  // Convert char to int
            i--;
        }
        
        // Add bit from string b if available
        if (j >= 0) {
            sum += b[j] - '0';  // Convert char to int
            j--;
        }
        
        // The current bit in the result is sum % 2 (0 or 1)
        result[k] = (sum % 2) + '0';
        k++;
        
        // The carry for the next step is sum / 2 (either 0 or 1)
        carry = sum / 2;
    }
    
    // Reverse the result string
    result[k] = '\0';  // Null terminate the string
    // Reverse the result string because we constructed it from right to left
    for (int start = 0, end = k - 1; start < end; start++, end--) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
    }
    
    return result;
}

// Main function to test the addBinary function
int main() {
    char a[] = "1010";
    char b[] = "1011";
    
    char* result = addBinary(a, b);
    printf("Sum of binary numbers: %s\n", result);  // Expected output: "10101"
    
    // Free the result string allocated by malloc
    free(result);
    
    return 0;
}
/*Recusive                  O(n)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive helper function
char* addBinaryRecursive(char* a, char* b, int carry, int i, int j) {
    // Base case: if both strings are exhausted and no carry
    if (i < 0 && j < 0 && carry == 0) {
        char* result = (char*)malloc(1 * sizeof(char));
        result[0] = '\0';  // Empty string
        return result;
    }

    // Add current bits and carry
    int bitA = (i >= 0) ? (a[i] - '0') : 0;
    int bitB = (j >= 0) ? (b[j] - '0') : 0;
    int sum = bitA + bitB + carry;

    // Current bit and new carry
    int currentBit = sum % 2;
    int newCarry = sum / 2;

    // Recursive call for the next significant bit
    char* partialResult = addBinaryRecursive(a, b, newCarry, i - 1, j - 1);

    // Append the current bit to the result
    size_t len = strlen(partialResult);
    char* result = (char*)malloc((len + 2) * sizeof(char));  // +2 for current bit and null terminator
    sprintf(result, "%s%c", partialResult, currentBit + '0');  // Append current bit
    free(partialResult);  // Free memory from the previous recursive call

    return result;
}

// Wrapper function for the recursive implementation
char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);

    // Call the recursive helper
    return addBinaryRecursive(a, b, 0, lenA - 1, lenB - 1);
}

// Main function to test the addBinary function
int main() {
    char a[] = "1010";
    char b[] = "1011";

    char* result = addBinary(a, b);
    printf("Sum of binary numbers: %s\n", result);  // Expected output: "10101"

    // Free the result string allocated by malloc
    free(result);

    return 0;
}
*/