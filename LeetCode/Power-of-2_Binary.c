#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is a power of two
bool isPowerOfTwo(int n) {
    // If n is positive and n & (n - 1) is 0, then n is a power of two
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    // Test cases
    printf("isPowerOfTwo(1): %d\n", isPowerOfTwo(1));   // True (1 is 2^0)
    printf("isPowerOfTwo(2): %d\n", isPowerOfTwo(2));   // True (2 is 2^1)
    printf("isPowerOfTwo(4): %d\n", isPowerOfTwo(4));   // True (4 is 2^2)
    printf("isPowerOfTwo(8): %d\n", isPowerOfTwo(8));   // True (8 is 2^3)
    printf("isPowerOfTwo(16): %d\n", isPowerOfTwo(16)); // True (16 is 2^4)
    
    // Non-power of two test cases
    printf("isPowerOfTwo(3): %d\n", isPowerOfTwo(3));   // False
    printf("isPowerOfTwo(5): %d\n", isPowerOfTwo(5));   // False
    printf("isPowerOfTwo(18): %d\n", isPowerOfTwo(18)); // False
    printf("isPowerOfTwo(0): %d\n", isPowerOfTwo(0));   // False (0 is not a power of two)
    printf("isPowerOfTwo(-16): %d\n", isPowerOfTwo(-16)); // False (negative number)

    return 0;
}
