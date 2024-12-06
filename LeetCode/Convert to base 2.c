#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* baseNeg2(int n) {
    // Special case: if n is 0, return "0"
    if (n == 0) {
        return "0";
    }

    // Allocate enough space for the result, considering at most log2(n) digits
    char* result = (char*)malloc(33 * sizeof(char));  // Max length for base -2
    int idx = 0;

    // Loop to convert n to base -2
    while (n != 0) {
        // Get remainder when dividing by -2
        int remainder = n % (-2);
        
        // If remainder is negative, adjust it by adding 2
        if (remainder < 0) {
            remainder += 2;
            n = n / (-2) + 1;  // Adjust quotient to handle the negative remainder
        } else {
            n = n / (-2);
        }
        
        // Store the current digit (either '0' or '1')
        result[idx++] = remainder + '0';
    }

    // Reverse the result string since we built it backwards
    result[idx] = '\0';
    for (int i = 0; i < idx / 2; i++) {
        char temp = result[i];
        result[i] = result[idx - 1 - i];
        result[idx - 1 - i] = temp;
    }

    return result;
}

int main() {
    int n = 6;  // Example input
    char* result = baseNeg2(n);
    printf("Base -2 representation of %d: %s\n", n, result);
    free(result);  // Don't forget to free the allocated memory
    return 0;
}
/*recur O(log n)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function for the recursive part of the base -2 conversion
char* convertBaseNeg2(int n) {
    // Base case: if n is 0, return an empty string
    if (n == 0) {
        return "";
    }
    
    // Compute remainder and adjust it if negative
    int remainder = n % (-2);
    if (remainder < 0) {
        remainder += 2; // Adjust remainder to be non-negative (either 0 or 1)
        n = n / (-2) + 1; // Adjust quotient to account for the negative remainder
    } else {
        n = n / (-2);
    }
    
    // Recursively call the function to process the next digit
    char* smallerResult = convertBaseNeg2(n);
    
    // Convert remainder to character ('0' or '1') and concatenate
    char* result = (char*)malloc(strlen(smallerResult) + 2); // +1 for the digit, +1 for '\0'
    strcpy(result, smallerResult); // Copy the smaller result
    result[strlen(smallerResult)] = remainder + '0'; // Append the current digit
    result[strlen(smallerResult) + 1] = '\0'; // Null-terminate the string
    
    return result;
}

char* baseNeg2(int n) {
    // Special case for n = 0
    if (n == 0) {
        char* result = (char*)malloc(2 * sizeof(char)); // "0" + '\0'
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    
    // Call the recursive function
    char* result = convertBaseNeg2(n);
    
    // Reverse the string to get the correct order
    int length = strlen(result);
    for (int i = 0; i < length / 2; i++) {
        char temp = result[i];
        result[i] = result[length - 1 - i];
        result[length - 1 - i] = temp;
    }
    
    return result;
}

int main() {
    int n = 6;  // Example input
    char* result = baseNeg2(n);
    printf("Base -2 representation of %d: %s\n", n, result);
    free(result);  // Free the allocated memory
    return 0;
}
*/