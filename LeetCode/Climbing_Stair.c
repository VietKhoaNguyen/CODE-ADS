#include <stdio.h>

int climbStairs(int n) {
    if (n == 0 || n == 1) {
        return 1;  // Base cases: 1 way to climb 0 or 1 step
    }

    int prev1 = 1, prev2 = 1, current = 0;

    // Start from the 2nd step and compute the number of ways to climb up to n
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;  // Number of ways to reach the current step
        prev2 = prev1;            // Update prev2 to the previous step
        prev1 = current;          // Update prev1 to the current step
    }

    return current;  // The number of ways to reach the nth step
}

// Main function to test climbStairs
int main() {
    int n = 5;
    printf("Ways to climb %d steps: %d\n", n, climbStairs(n));  // Expected output: 8

    n = 10;
    printf("Ways to climb %d steps: %d\n", n, climbStairs(n));  // Expected output: 89

    return 0;
}
/*recur O(2^n)
#include <stdio.h>

int climbStairs(int n) {
    if (n == 0 || n == 1) {
        return 1;  // Base cases: 1 way to climb 0 or 1 step
    }
    return climbStairs(n - 1) + climbStairs(n - 2);  // Recursive step
}

// Main function to test climbStairs
int main() {
    int n = 5;
    printf("Ways to climb %d steps: %d\n", n, climbStairs(n));  // Expected output: 8

    n = 10;
    printf("Ways to climb %d steps: %d\n", n, climbStairs(n));  // Expected output: 89

    return 0;
}
*/