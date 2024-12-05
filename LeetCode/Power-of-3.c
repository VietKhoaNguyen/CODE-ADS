#include <stdbool.h>

// Function to check if a number is a power of three
bool isPowerOfThree(int n) {
    // Handle edge case: if n is less than or equal to 0, it cannot be a power of three
    if (n <= 0) {
        return false;
    }

    // Keep dividing n by 3 while it's divisible by 3
    while (n % 3 == 0) {
        n /= 3;
    }

    // If n is 1 after all divisions, it is a power of three
    return n == 1;
}

// Example usage
#include <stdio.h>

int main() {
    // Test cases
    int testCases[] = {27, 45, 9, 81, 1, -3};
    int nTestCases = sizeof(testCases) / sizeof(testCases[0]);

    // Test the isPowerOfThree function with different test cases
    for (int i = 0; i < nTestCases; i++) {
        int n = testCases[i];
        if (isPowerOfThree(n)) {
            printf("%d is a power of three.\n", n);
        } else {
            printf("%d is not a power of three.\n", n);
        }
    }

    return 0;
}
