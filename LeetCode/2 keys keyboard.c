#include <stdio.h>

int minSteps(int n) {
    int steps = 0;

    // Iterate over all possible divisors of n (from 2 to sqrt(n))
    for (int i = 2; i * i <= n; i++) {
        // If i is a divisor of n, then we perform copy-paste operations
        while (n % i == 0) {
            steps += i;  // i is a divisor, so we add i to steps
            n /= i;  // Divide n by i to reduce the problem size
        }
    }

    // If n is still greater than 1, then n itself is prime
    if (n > 1) {
        steps += n;  // Add the remaining prime factor
    }

    return steps;
}

int main() {
    int n = 3;
    int result = minSteps(n);
    printf("Minimum steps to get %d 'A's: %d\n", n, result);
    return 0;
}
/*recur O(sqrt(n))
#include <stdio.h>

int minStepsRecursive(int n) {
    // Base case: If n is 1, no operations are needed
    if (n == 1) {
        return 0;
    }

    int steps = n;  // Initialize with the worst case where we perform n steps (which could happen when n is prime)

    // Try all divisors i of n (from 2 up to sqrt(n))
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            // If i is a divisor of n, perform a copy-paste operation and reduce the problem size
            steps = steps < i + minStepsRecursive(n / i) ? steps : i + minStepsRecursive(n / i);
            
            // As n might be divisible by multiple factors, we continue checking for all divisors
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    // If n is still greater than 1, it means n is prime, so we add n to steps
    if (n > 1) {
        steps = steps < n + minStepsRecursive(1) ? steps : n + minStepsRecursive(1);
    }

    return steps;
}

int main() {
    int n = 3;
    int result = minStepsRecursive(n);
    printf("Minimum steps to get %d 'A's: %d\n", n, result);
    return 0;
}
*/