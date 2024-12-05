#include <stdio.h>
#include <limits.h>  // For INT_MIN and INT_MAX

int divide(int dividend, int divisor) {
    // Edge case: handle overflow (INT_MIN divided by -1)
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;  // Overflow case
    }

    // Determine if the result should be negative
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    // Convert both numbers to positive for ease of calculation
    long long absDividend = llabs((long long)dividend);
    long long absDivisor = llabs((long long)divisor);

    int quotient = 0;

    // Loop to subtract multiples of divisor from dividend
    while (absDividend >= absDivisor) {
        long long tempDivisor = absDivisor;
        long long multiple = 1;

        // Double the divisor until it is larger than the remaining dividend
        while (absDividend >= (tempDivisor << 1)) {
            tempDivisor <<= 1;
            multiple <<= 1;
        }

        // Subtract the largest doubled divisor from the dividend
        absDividend -= tempDivisor;
        quotient += multiple;
    }

    // Apply the sign to the result
    return sign * quotient;
}

int main() {
    int dividend = 10;
    int divisor = 3;

    int result = divide(dividend, divisor);
    printf("Result of %d / %d = %d\n", dividend, divisor, result);

    return 0;
}
/*recur O(log n)
#include <stdio.h>
#include <limits.h>  // To handle INT_MIN edge case

// Helper function to handle the recursive division
int recursiveDivide(int dividend, int divisor, int count) {
    // Base case: when the dividend is smaller than the divisor, return 0
    if (dividend < divisor) {
        return count;
    }

    // Double the divisor using bit shifting (left shift by 1) and increment the count
    int doubledDivisor = divisor;
    int multiple = 1;

    while (dividend >= (doubledDivisor << 1)) {
        doubledDivisor <<= 1;
        multiple <<= 1;  // We also double the multiple of the result
    }

    // Subtract the largest doubled divisor from the dividend
    dividend -= doubledDivisor;

    // Recursively divide the remaining dividend and add the result
    return recursiveDivide(dividend, divisor, count + multiple);
}

// Main function to divide two integers
int divide(int dividend, int divisor) {
    // Edge case: handle overflow (INT_MIN divided by -1)
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;  // Overflow case
    }

    // Determine if the result should be negative
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    // Convert both numbers to positive for ease of calculation
    long long absDividend = llabs((long long)dividend);
    long long absDivisor = llabs((long long)divisor);

    // Call the recursive function with absolute values and start with count = 0
    int result = recursiveDivide(absDividend, absDivisor, 0);

    // Apply the sign
    return sign * result;
}

int main() {
    int dividend = 10;
    int divisor = 3;

    int result = divide(dividend, divisor);
    printf("Result of %d / %d = %d\n", dividend, divisor, result);

    return 0;
}
*/