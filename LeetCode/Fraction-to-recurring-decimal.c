#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>

char* fractionToDecimal(int numerator, int denominator) {
    // Handle the case where the numerator is 0
    if (numerator == 0) {
        char* result = (char*)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    // Determine the sign of the result
    char sign = (numerator < 0) ^ (denominator < 0) ? '-' : ' ';
    
    // Work with absolute values to avoid negative numbers
    long long num = llabs((long long)numerator);
    long long den = llabs((long long)denominator);
    
    // Calculate the integer part
    long long intPart = num / den;
    long long remainder = num % den;
    
    // Create a string for the result
    char* result = (char*)malloc(1024 * sizeof(char));  // Make sure we have enough space for large numbers
    int idx = 0;

    // Add the sign and integer part to the result
    if (sign == '-') {
        result[idx++] = '-';
    }
    idx += sprintf(result + idx, "%lld", intPart);

    // If there's no remainder, return the result
    if (remainder == 0) {
        return result;
    }

    // Otherwise, process the fractional part
    result[idx++] = '.';

    // Map to store the remainder and its corresponding index in the result
    unordered_map<long long, int> remainderMap;

    // Loop to find the decimal part
    while (remainder != 0) {
        // If this remainder has been seen before, a cycle is detected
        if (remainderMap.find(remainder) != remainderMap.end()) {
            int cycleStart = remainderMap[remainder];
            // Insert parentheses around the repeating part
            memmove(result + cycleStart + 1, result + cycleStart, idx - cycleStart);
            result[cycleStart] = '(';
            result[idx + 1] = ')';
            result[idx + 2] = '\0';
            return result;
        }

        // Store the current remainder's position in the result
        remainderMap[remainder] = idx;

        // Multiply remainder by 10 to get the next digit
        remainder *= 10;
        result[idx++] = (remainder / den) + '0';
        remainder %= den;
    }

    // Null terminate the string
    result[idx] = '\0';
    return result;
}

// Example usage
int main() {
    int numerator = 1;
    int denominator = 2;
    
    char* result = fractionToDecimal(numerator, denominator);
    printf("Result: %s\n", result);  // Expected: "0.5"
    free(result);
    
    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function for recursive decimal calculation
int recursiveFraction(long long numerator, long long denominator, long long remainder, char* result, int idx, int* seenRemainders) {
    // If the remainder repeats, add parentheses and return the length
    if (seenRemainders[remainder] != -1) {
        int cycleStart = seenRemainders[remainder];
        memmove(result + cycleStart + 1, result + cycleStart, idx - cycleStart);
        result[cycleStart] = '(';
        result[idx + 1] = ')';
        result[idx + 2] = '\0';
        return idx + 2;  // Updated size with parentheses
    }

    // Mark the current remainder with its index
    seenRemainders[remainder] = idx;

    // Multiply the remainder by 10 to get the next digit
    remainder *= 10;
    int digit = remainder / denominator;
    result[idx++] = digit + '0';  // Convert digit to character
    remainder %= denominator;

    // If there's no remainder, return the final result
    if (remainder == 0) {
        result[idx] = '\0';
        return idx;
    }

    // Recursive call to process the next digit in the decimal
    return recursiveFraction(numerator, denominator, remainder, result, idx, seenRemainders);
}

// Main function to convert fraction to decimal
char* fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
        char* result = (char*)malloc(2 * sizeof(char));  // Just "0"
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    // Determine the sign of the result
    char sign = (numerator < 0) ^ (denominator < 0) ? '-' : ' ';
    
    // Work with absolute values to avoid negative numbers
    long long num = llabs((long long)numerator);
    long long den = llabs((long long)denominator);
    
    // Allocate enough memory for the result string
    char* result = (char*)malloc(1024 * sizeof(char));  // Assuming large enough space
    int idx = 0;

    // Add sign if necessary
    if (sign == '-') {
        result[idx++] = '-';
    }

    // Calculate the integer part
    long long intPart = num / den;
    result[idx++] = intPart + '0';  // Add the integer part to the result

    // Calculate the remainder
    long long remainder = num % den;
    
    // If there is no remainder, we're done
    if (remainder == 0) {
        result[idx] = '\0';
        return result;
    }

    // Add the decimal point
    result[idx++] = '.';

    // Initialize the seenRemainders map for cycle detection
    int seenRemainders[den + 1];
    for (int i = 0; i <= den; i++) {
        seenRemainders[i] = -1;  // Initialize all remainders as unseen
    }

    // Call the recursive function to handle the fractional part
    recursiveFraction(num, den, remainder, result, idx, seenRemainders);

    return result;
}

// Example usage
int main() {
    int numerator = 1;
    int denominator = 3;
    
    char* result = fractionToDecimal(numerator, denominator);
    printf("Result: %s\n", result);  // Expected: "0.(3)"
    
    free(result);
    
    return 0;
}
*/