#include <stdio.h>

int fib(int n) {
    if (n <= 1) {
        return n; // Base cases
    }
    int prev2 = 0, prev1 = 1, current;
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}

int main() {
    int n = 10; // Example
    printf("Fibonacci of %d is %d\n", n, fib(n));
    return 0;
}

/*recur O(2^n)
#include <stdio.h>

int fib(int n) {
    // Base cases: fib(0) = 0, fib(1) = 1
    if (n <= 1) {
        return n;
    }
    // Recursive relation: fib(n) = fib(n-1) + fib(n-2)
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 10; // Example input
    printf("Fibonacci of %d is %d\n", n, fib(n));
    return 0;
}
*/