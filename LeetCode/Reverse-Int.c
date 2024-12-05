#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    int result = 0;

    // Loop until x becomes 0
    while (x != 0) {
        // Extract the last digit
        int digit = x % 10;
        
        // Check for overflow before multiplying and adding
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
            return 0; // Overflow case
        }
        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) {
            return 0; // Overflow case
        }
        
        // Update result by adding the digit
        result = result * 10 + digit;
        
        // Remove the last digit from x
        x /= 10;
    }
    
    return result;
}
int main() {
    int x = 123;
    printf("Reversed: %d\n", reverse(x)); // Output: 321
    return 0;
}
/*recur O(log x)
#include <stdio.h>
#include <limits.h>

// Helper function for recursive reversal
int reverseHelper(int x, int result) {
    // Base case: when x becomes 0, return the result
    if (x == 0) {
        return result;
    }

    // Extract the last digit
    int digit = x % 10;

    // Check for overflow before performing multiplication
    if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
        return 0; // Overflow case
    }
    if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) {
        return 0; // Overflow case
    }

    // Recurse with the updated result and the remaining number
    return reverseHelper(x / 10, result * 10 + digit);
}

// Public function to start the recursion
int reverse(int x) {
    return reverseHelper(x, 0);
}

int main() {
    int x = 123;
    printf("Reversed: %d\n", reverse(x)); // Output: 321
    
    x = -123;
    printf("Reversed: %d\n", reverse(x)); // Output: -321
    
    x = 120;
    printf("Reversed: %d\n", reverse(x)); // Output: 21

    return 0;
}
*/