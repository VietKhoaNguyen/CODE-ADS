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
