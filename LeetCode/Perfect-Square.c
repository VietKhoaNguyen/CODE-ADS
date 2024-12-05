#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numSquares(int n) {
    // Initialize an array dp where dp[i] represents the least number of perfect squares that sum up to i
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    
    // Base case: dp[0] = 0 (0 squares needed to sum up to 0)
    dp[0] = 0;

    // Initialize all dp[i] with a large value
    for (int i = 1; i <= n; i++) {
        dp[i] = i;  // Maximum is i squares (1^2 + 1^2 + ... + 1^2)
    }

    // Fill dp array with minimum squares needed for each value
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = fmin(dp[i], dp[i - j * j] + 1);
        }
    }

    int result = dp[n];
    free(dp);
    return result;
}

// Example usage
int main() {
    int n = 12;  // Example: Find the least number of perfect squares that sum up to 12
    printf("Least number of perfect squares for %d: %d\n", n, numSquares(n));
    return 0;
}
/*recur O(n sqrt(n))
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int helper(int n, int* memo) {
    // Base case: if n is 0, no squares are needed
    if (n == 0) {
        return 0;
    }

    // If we've already computed the result for this value of n, return it
    if (memo[n] != -1) {
        return memo[n];
    }

    int minSquares = n;  // Maximum number of squares would be n (1^2 + 1^2 + ... + 1^2)

    // Try every square number i^2 (starting from 1^2, 2^2, ..., i^2 <= n)
    for (int i = 1; i * i <= n; i++) {
        int remaining = n - i * i;
        minSquares = fmin(minSquares, helper(remaining, memo) + 1);
    }

    memo[n] = minSquares;  // Store the result in the memoization table
    return minSquares;
}

int numSquares(int n) {
    // Initialize the memoization table
    int* memo = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }

    int result = helper(n, memo);
    free(memo);
    return result;
}

// Example usage
int main() {
    int n = 12;  // Example: Find the least number of perfect squares that sum up to 12
    printf("Least number of perfect squares for %d: %d\n", n, numSquares(n));
    return 0;
}
*/