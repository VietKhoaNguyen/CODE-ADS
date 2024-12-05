#include <math.h>
#include <stdbool.h>

bool judgeSquareSum(int c) {
    // Loop through values of a from 0 to sqrt(c)
    for (long a = 0; a * a <= c; a++) {
        long b = c - a * a;
        // Check if b is a perfect square
        long sqrt_b = (long)sqrt(b);
        if (sqrt_b * sqrt_b == b) {
            return true;
        }
    }
    return false;
}
/*recur O(sqrt(c))
#include <math.h>
#include <stdbool.h>

// Helper function to check if a number is a perfect square
bool isPerfectSquare(long num) {
    long sqrt_num = (long)sqrt(num);
    return sqrt_num * sqrt_num == num;
}

// Recursive function to check if there exist a and b such that a^2 + b^2 = c
bool judgeSquareSumRecursive(int c, long a) {
    // Base case: if a^2 > c, no need to continue
    if (a * a > c) {
        return false;
    }

    // Calculate b = c - a^2
    long b = c - a * a;

    // Check if b is a perfect square
    if (isPerfectSquare(b)) {
        return true;
    }

    // Recur for the next value of a
    return judgeSquareSumRecursive(c, a + 1);
}

bool judgeSquareSum(int c) {
    // Start the recursion with a = 0
    return judgeSquareSumRecursive(c, 0);
}
*/