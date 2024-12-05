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
/*recur O(log n)
#include <stdio.h>
#include <stdbool.h>

// Recursive function to check if a number is a power of two
bool isPowerOfTwoRecursive(int n) {
    // Base case: if n is 1, it's a power of two
    if (n == 1) {
        return true;
    }

    // Base case: if n is less than 1, it can't be a power of two
    if (n <= 0 || n % 2 != 0) {
        return false;
    }

    // Recur by dividing the number by 2
    return isPowerOfTwoRecursive(n / 2);
}

int main() {
    // Test cases
    printf("isPowerOfTwoRecursive(1): %d\n", isPowerOfTwoRecursive(1));   // True (1 is 2^0)
    printf("isPowerOfTwoRecursive(2): %d\n", isPowerOfTwoRecursive(2));   // True (2 is 2^1)
    printf("isPowerOfTwoRecursive(4): %d\n", isPowerOfTwoRecursive(4));   // True (4 is 2^2)
    printf("isPowerOfTwoRecursive(8): %d\n", isPowerOfTwoRecursive(8));   // True (8 is 2^3)
    printf("isPowerOfTwoRecursive(16): %d\n", isPowerOfTwoRecursive(16)); // True (16 is 2^4)
    
    // Non-power of two test cases
    printf("isPowerOfTwoRecursive(3): %d\n", isPowerOfTwoRecursive(3));   // False
    printf("isPowerOfTwoRecursive(5): %d\n", isPowerOfTwoRecursive(5));   // False
    printf("isPowerOfTwoRecursive(18): %d\n", isPowerOfTwoRecursive(18)); // False
    printf("isPowerOfTwoRecursive(0): %d\n", isPowerOfTwoRecursive(0));   // False (0 is not a power of two)
    printf("isPowerOfTwoRecursive(-16): %d\n", isPowerOfTwoRecursive(-16)); // False (negative number)

    return 0;
}
*/