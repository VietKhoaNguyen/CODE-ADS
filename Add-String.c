#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addStrings(char* num1, char* num2) {
    // Determine the lengths of both strings
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    
    // Allocate memory for the result (maximum length + 1 for carry + null terminator)
    int maxLen = len1 > len2 ? len1 : len2;
    char* result = (char*)malloc((maxLen + 2) * sizeof(char));
    
    int carry = 0;
    int i = len1 - 1;
    int j = len2 - 1;
    int k = 0;  // Index for the result string
    
    // Add digits starting from the least significant (rightmost)
    while (i >= 0 || j >= 0 || carry != 0) {
        int digit1 = i >= 0 ? num1[i] - '0' : 0;
        int digit2 = j >= 0 ? num2[j] - '0' : 0;
        
        int sum = digit1 + digit2 + carry;
        result[k++] = (sum % 10) + '0';  // Store the current digit in the result
        carry = sum / 10;  // Update the carry for the next iteration
        
        i--;
        j--;
    }
    
    // The result string is built in reverse, so reverse it
    result[k] = '\0';  // Null-terminate the result string
    for (int start = 0, end = k - 1; start < end; start++, end--) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
    }
    
    return result;
}

int main() {
    char num1[] = "123";
    char num2[] = "456";
    
    char* result = addStrings(num1, num2);
    printf("The sum is: %s\n", result);
    
    // Free allocated memory
    free(result);
    
    return 0;
}
/*recursive O(n)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to recursively add the digits
void addStringsHelper(char* num1, char* num2, int i, int j, int carry, char* result, int* k) {
    // Base case: if both strings are processed and no carry is left
    if (i < 0 && j < 0 && carry == 0) {
        result[*k] = '\0';  // Null-terminate the string
        return;
    }

    // Get the current digits
    int digit1 = (i >= 0) ? num1[i] - '0' : 0;
    int digit2 = (j >= 0) ? num2[j] - '0' : 0;

    // Calculate the sum of the digits plus carry
    int sum = digit1 + digit2 + carry;

    // Store the current digit in the result
    result[*k] = (sum % 10) + '0';
    (*k)++;  // Move to the next position in the result

    // Update the carry for the next iteration
    carry = sum / 10;

    // Recursively call the function for the next digits
    addStringsHelper(num1, num2, i - 1, j - 1, carry, result, k);
}

// Wrapper function to initialize and start recursion
char* addStrings(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    
    // Allocate memory for the result (maximum length + 1 for carry + null terminator)
    int maxLen = len1 > len2 ? len1 : len2;
    char* result = (char*)malloc((maxLen + 2) * sizeof(char));
    
    int k = 0;  // Index for the result string
    
    // Start the recursion from the last characters of both strings
    addStringsHelper(num1, num2, len1 - 1, len2 - 1, 0, result, &k);
    
    // Reverse the result string (since we built it backwards)
    int start = 0, end = k - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }

    return result;
}

int main() {
    char num1[] = "123";
    char num2[] = "456";
    
    char* result = addStrings(num1, num2);
    printf("The sum is: %s\n", result);
    
    // Free allocated memory
    free(result);
    
    return 0;
}
<<<<<<< HEAD
*/
=======
*/
>>>>>>> 5527a31819c76f85ec241af65a5c546360320eae
