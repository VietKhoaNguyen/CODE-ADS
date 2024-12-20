#include <stdio.h>
#include <limits.h>

int myAtoi(char* s) {
    int i = 0, sign = 1, result = 0;
    
    // Step 1: Skip leading whitespaces
    while (s[i] == ' ') {
        i++;
    }
    
    // Step 2: Check for the sign
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }
    
    // Step 3: Process digits and convert to integer
    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';
        
        // Step 4: Check for overflow before updating the result
        if (result > (INT_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        
        result = result * 10 + digit;
        i++;
    }
    
    // Step 5: Return the result with the appropriate sign
    return result * sign;
}
int main() {
    char str1[] = "42";
    printf("Converted: %d\n", myAtoi(str1)); // Output: 42

    char str2[] = "   -42";
    printf("Converted: %d\n", myAtoi(str2)); // Output: -42

    char str3[] = "4193 with words";
    printf("Converted: %d\n", myAtoi(str3)); // Output: 4193
    return 0
}
/*recur O(n)
#include <stdio.h>
#include <limits.h>

int myAtoiHelper(char* s, int i, int sign, int result) {
    // Base case: if we've reached the end of the string or encountered a non-digit character
    if (s[i] < '0' || s[i] > '9') {
        return result * sign;  // Return the accumulated result with sign
    }

    // Convert current character to an integer and update result
    int digit = s[i] - '0';
    
    // Check for overflow before updating the result
    if (result > (INT_MAX - digit) / 10) {
        return sign == 1 ? INT_MAX : INT_MIN;
    }

    result = result * 10 + digit;

    // Recursively process the next character
    return myAtoiHelper(s, i + 1, sign, result);
}

int myAtoi(char* s) {
    int i = 0, sign = 1, result = 0;
    
    // Step 1: Skip leading whitespaces
    while (s[i] == ' ') {
        i++;
    }
    
    // Step 2: Check for the sign
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }
    
    // Step 3: Recursively process the digits
    return myAtoiHelper(s, i, sign, result);
}

int main() {
    char str1[] = "42";
    printf("Converted: %d\n", myAtoi(str1)); // Output: 42

    char str2[] = "   -42";
    printf("Converted: %d\n", myAtoi(str2)); // Output: -42

    char str3[] = "4193 with words";
    printf("Converted: %d\n", myAtoi(str3)); // Output: 4193
    
    return 0;
}
*/