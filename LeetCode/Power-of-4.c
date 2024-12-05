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
