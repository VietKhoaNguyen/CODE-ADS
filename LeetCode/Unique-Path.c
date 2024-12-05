#include <stdio.h>

int uniquePaths(int m, int n) {
    // Create a 2D DP table
    int dp[m][n];
    
    // Fill the first row and first column with 1
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }

    // Fill the rest of the DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    // Return the value in the bottom-right corner, which contains the number of unique paths
    return dp[m - 1][n - 1];
}

// Example usage
int main() {
    int m = 3, n = 7;
    printf("Number of unique paths: %d\n", uniquePaths(m, n));
    return 0;
}
/*recur O(2^(m+n))
#include <stdio.h>

int uniquePathsRecursive(int m, int n) {
    // Base case: If we are at the top row or leftmost column, return 1
    if (m == 1 || n == 1) {
        return 1;
    }
    
    // Recursive case: The number of paths to reach (m, n) is the sum of
    // the number of paths to reach (m-1, n) and (m, n-1)
    return uniquePathsRecursive(m - 1, n) + uniquePathsRecursive(m, n - 1);
}

// Example usage
int main() {
    int m = 3, n = 7;
    printf("Number of unique paths: %d\n", uniquePathsRecursive(m, n));
    return 0;
}
*/