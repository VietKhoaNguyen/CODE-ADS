#include <stdio.h>

int integerBreak(int n) {
    if (n == 2) return 1;  // Base case: for n = 2, the best split is 1 + 1 -> product = 1
    if (n == 3) return 2;  // Base case: for n = 3, the best split is 2 + 1 -> product = 2

    int product = 1;

    // While n is greater than 4, break it into 3s
    while (n > 4) {
        product *= 3;  // Multiply by 3 for maximum product
        n -= 3;        // Subtract 3 from n
    }

    // Handle the remaining part (n will be 4 or less)
    product *= n;  // Multiply by the remaining value (either 2 or 4)

    return product;
}

int main() {
    int n = 10;
    printf("Maximum product for integer break of %d is: %d\n", n, integerBreak(n));
    return 0;
}
/*recur O(n^2)
#include <stdio.h>

int memo[1001];  // Memoization array to store results for subproblems

// Recursive function to compute the maximum product
int integerBreakHelper(int n) {
    // If we already computed the result, return it
    if (memo[n] != -1) {
        return memo[n];
    }

    int maxProduct = 0;

    // Try splitting n into two parts, i and n - i, and compute the product recursively
    for (int i = 1; i < n; i++) {
        // Either use the product of i * (n - i), or the product of the recursive split of (n - i)
        maxProduct = (maxProduct > i * (n - i)) ? maxProduct : i * (n - i);
        maxProduct = (maxProduct > i * integerBreakHelper(n - i)) ? maxProduct : i * integerBreakHelper(n - i);
    }

    // Memoize the result for this n
    memo[n] = maxProduct;
    return maxProduct;
}

// Function to get the result for integer break of n
int integerBreak(int n) {
    // Initialize memo array with -1 (indicating uncomputed values)
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }

    return integerBreakHelper(n);
}

int main() {
    int n = 10;
    printf("Maximum product for integer break of %d is: %d\n", n, integerBreak(n));
    return 0;
}
*/