#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is a power of four
bool isPowerOfFour(int n) {
    // Check if n is greater than 0, is a power of 2, and the 1-bit is at an even position
    return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
}

// Main function for testing
int main() {
    int n1 = 16;
    int n2 = 8;
    int n3 = 1;
    int n4 = 5;

    // Test cases
    printf("%d is %sa power of four.\n", n1, isPowerOfFour(n1) ? "" : "not ");
    printf("%d is %sa power of four.\n", n2, isPowerOfFour(n2) ? "" : "not ");
    printf("%d is %sa power of four.\n", n3, isPowerOfFour(n3) ? "" : "not ");
    printf("%d is %sa power of four.\n", n4, isPowerOfFour(n4) ? "" : "not ");

    return 0;
}
/*recur O(log4(n))
#include <stdio.h>
#include <stdbool.h>

// Recursive function to check if a number is a power of four
bool isPowerOfFourRecursive(int n) {
    // Base case: If n is 1, it is a power of four (since 4^0 = 1)
    if (n == 1) {
        return true;
    }

    // Base case: If n is less than 4 or not divisible by 4, it is not a power of four
    if (n < 4 || n % 4 != 0) {
        return false;
    }

    // Recursive case: Divide n by 4 and continue checking
    return isPowerOfFourRecursive(n / 4);
}

int main() {
    int n1 = 16;
    int n2 = 8;
    int n3 = 1;
    int n4 = 5;

    // Test cases
    printf("%d is %sa power of four.\n", n1, isPowerOfFourRecursive(n1) ? "" : "not ");
    printf("%d is %sa power of four.\n", n2, isPowerOfFourRecursive(n2) ? "" : "not ");
    printf("%d is %sa power of four.\n", n3, isPowerOfFourRecursive(n3) ? "" : "not ");
    printf("%d is %sa power of four.\n", n4, isPowerOfFourRecursive(n4) ? "" : "not ");

    return 0;
}
*/