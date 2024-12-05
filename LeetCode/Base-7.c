#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convertToBase7(int num) {
    // Special case: 0 should return "0"
    if (num == 0) {
        char* result = (char*)malloc(2 * sizeof(char)); // space for "0" and '\0'
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    
    // Determine if the number is negative
    int isNegative = num < 0;
    if (isNegative) {
        num = -num; // work with positive equivalent for ease
    }

    // Prepare a buffer to store the base-7 digits (max size for a 32-bit integer)
    char buffer[32];
    int index = 0;
    
    // Convert the number to base 7
    while (num > 0) {
        buffer[index++] = (num % 7) + '0'; // store the current digit
        num /= 7; // divide the number by 7
    }
    
    // Add the negative sign if needed
    if (isNegative) {
        buffer[index++] = '-';
    }
    
    // Null-terminate the string
    buffer[index] = '\0';
    
    // Reverse the buffer to get the correct base-7 representation
    int start = 0, end = index - 1;
    while (start < end) {
        char temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
        start++;
        end--;
    }

    // Allocate memory for the result and copy the string
    char* result = (char*)malloc((index + 1) * sizeof(char));
    strcpy(result, buffer);
    
    return result;
}
int main() {
    int num = -100;
    char* result = convertToBase7(num);
    printf("Base-7 representation of %d is: %s\n", num, result);
    
    free(result);  // Don't forget to free the allocated memory!
    
    return 0;
}