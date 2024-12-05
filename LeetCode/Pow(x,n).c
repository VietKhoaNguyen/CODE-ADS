#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n) {
    // Handle negative powers and edge cases
    long long exp = n; // Use long long to avoid overflow when n == INT_MIN
    if (exp < 0) {
        x = 1 / x;
        exp = -exp;
    }

    double result = 1.0;
    double currentProduct = x;

    while (exp > 0) {
        if (exp % 2 == 1) { // If the current bit is set
            result *= currentProduct;
        }
        currentProduct *= currentProduct; // Square the base
        exp /= 2; // Move to the next bit
    }

    return result;
}

// Example usage
int main() {
    double x = 2.0;
    int n = -3;

    double result = myPow(x, n);
    printf("Result of %.2f^%d = %.5f\n", x, n, result);

    return 0;
}
/*recur O(log n)
#include <stdio.h>
#include <stdlib.h>

double myPowHelper(double x, long long n) {
    // Base case: exponent is 0
    if (n == 0) {
        return 1.0;
    }

    // Recursive case: exponent is positive
    double half = myPowHelper(x, n / 2);

    if (n % 2 == 0) {
        return half * half;  // If n is even, x^n = (x^(n/2))^2
    } else {
        return half * half * x;  // If n is odd, x^n = (x^(n/2))^2 * x
    }
}

double myPow(double x, int n) {
    if (n < 0) {
        x = 1 / x;  // Invert the base for negative exponents
        return myPowHelper(x, -(long long)n);  // Call the helper function with positive n
    } else {
        return myPowHelper(x, n);  // For non-negative exponents
    }
}

// Example usage
int main() {
    double x = 2.0;
    int n = -3;

    double result = myPow(x, n);
    printf("Result of %.2f^%d = %.5f\n", x, n, result);

    return 0;
}
*/