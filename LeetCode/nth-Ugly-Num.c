#include <stdio.h>
#include <stdlib.h>

int nthUglyNumber(int n) {
    int* ugly = (int*)malloc(n * sizeof(int));
    ugly[0] = 1;

    int index2 = 0, index3 = 0, index5 = 0;
    int next2 = 2, next3 = 3, next5 = 5;
    int nextUgly;

    for (int i = 1; i < n; i++) {
        // Pick the smallest among next2, next3, and next5
        nextUgly = (next2 < next3) ? (next2 < next5 ? next2 : next5) : (next3 < next5 ? next3 : next5);
        ugly[i] = nextUgly;

        // Increment the respective index if that factor was used
        if (nextUgly == next2) next2 = 2 * ugly[++index2];
        if (nextUgly == next3) next3 = 3 * ugly[++index3];
        if (nextUgly == next5) next5 = 5 * ugly[++index5];
    }

    int result = ugly[n - 1];
    free(ugly);
    return result;
}

// Example usage
int main() {
    int n = 10;
    printf("The %dth ugly number is: %d\n", n, nthUglyNumber(n)); // Expected output: 12
    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Helper recursive function to compute the nth ugly number
int nthUglyNumberRecursive(int n, int* dp) {
    if (dp[n] != -1) return dp[n]; // Return cached result if available
    if (n == 1) return dp[n] = 1;  // Base case: 1st ugly number is 1

    int i = n - 1;
    while (i > 0) {
        int val = nthUglyNumberRecursive(i, dp);
        if (val % 2 == 0 || val % 3 == 0 || val % 5 == 0) {
            dp[n] = val;
            return dp[n];
        }
        i--;
    }

    return dp[n];
}

int nthUglyNumber(int n) {
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) dp[i] = -1; // Initialize cache with -1

    int result = nthUglyNumberRecursive(n, dp);
    free(dp);
    return result;
}

// Example usage
int main() {
    int n = 10;
    printf("The %dth ugly number is: %d\n", n, nthUglyNumber(n)); // Expected output: 12
    return 0;
}
*/