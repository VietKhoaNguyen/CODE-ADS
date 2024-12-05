#include <stdio.h>
#include <stdlib.h>

int getMoneyAmount(int n) {
    // Create a DP table to store results for subproblems
    int dp[n+1][n+1];
    
    // Initialize the DP table: cost of guessing from i to i is 0
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    // Build the DP table
    for (int len = 2; len <= n; len++) { // len is the length of the range
        for (int i = 1; i <= n - len + 1; i++) { // i is the starting number
            int j = i + len - 1; // j is the ending number
            dp[i][j] = INT_MAX;
            
            // Try every possible guess k between i and j
            for (int k = i; k <= j; k++) {
                int cost = k + (k - 1 >= i ? dp[i][k-1] : 0) + (k + 1 <= j ? dp[k+1][j] : 0);
                dp[i][j] = (dp[i][j] < cost) ? dp[i][j] : cost;
            }
        }
    }

    // The answer is the minimum cost to guess between 1 and n
    return dp[1][n];
}

int main() {
    int n = 10;  // Example value for n
    printf("Minimum cost to guess the number between 1 and %d: %d\n", n, getMoneyAmount(n));
    return 0;
}
/*recur O(n^3)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Helper function to compute the minimum cost for a given range [i, j]
int helper(int* dp, int i, int j) {
    if (i >= j) return 0; // Base case: No guessing needed if only one number
    
    // If we already computed the value for this range, return it from dp table
    if (dp[i * 100 + j] != -1) {
        return dp[i * 100 + j];
    }

    int minCost = INT_MAX;
    // Try each possible guess k between i and j
    for (int k = i; k <= j; k++) {
        int cost = k + (helper(dp, i, k - 1)) + (helper(dp, k + 1, j));
        minCost = (cost < minCost) ? cost : minCost;
    }

    // Memoize the result for this range
    dp[i * 100 + j] = minCost;
    return minCost;
}

int getMoneyAmount(int n) {
    // Create a memoization array initialized to -1 (indicating uncomputed subproblems)
    int* dp = (int*)malloc(sizeof(int) * 100 * 100);
    for (int i = 0; i < 100 * 100; i++) {
        dp[i] = -1;
    }

    // Start the recursive computation for the range [1, n]
    int result = helper(dp, 1, n);

    // Free the memoization table
    free(dp);

    return result;
}

int main() {
    int n = 10;  // Example value for n
    printf("Minimum cost to guess the number between 1 and %d: %d\n", n, getMoneyAmount(n));
    return 0;
}
*/