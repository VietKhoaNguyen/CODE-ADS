#include <stdio.h>
#include <stdlib.h>

int numTrees(int n) {
    // dp[i] will store the number of unique BSTs that can be formed with i nodes
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    
    // Base cases
    dp[0] = 1;  // 1 way to form a BST with 0 nodes (empty tree)
    dp[1] = 1;  // 1 way to form a BST with 1 node
    
    // Fill the dp array for all values from 2 to n
    for (int i = 2; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];  // Number of BSTs with j as root
        }
    }

    int result = dp[n];  // The result is the number of unique BSTs with n nodes
    free(dp);  // Free the dynamically allocated memory
    return result;
}

int main() {
    int n = 3;  // Example: n = 3
    printf("Number of unique BSTs with %d nodes: %d\n", n, numTrees(n));
    return 0;
}
/*recur O(2^n)
#include <stdio.h>

int numTreesRecursive(int n) {
    // Base case: if n is 0 or 1, there's only one possible BST (empty tree or one node)
    if (n == 0 || n == 1) {
        return 1;
    }
    
    int total = 0;
    
    // For each possible root (1 to n), calculate the number of unique BSTs
    for (int i = 1; i <= n; i++) {
        // The number of unique BSTs with root i is:
        // Left subtree: (i-1) nodes, Right subtree: (n-i) nodes
        total += numTreesRecursive(i - 1) * numTreesRecursive(n - i);
    }
    
    return total;
}

int main() {
    int n = 3;  // Example: n = 3
    printf("Number of unique BSTs with %d nodes: %d\n", n, numTreesRecursive(n));
    return 0;
}
*/