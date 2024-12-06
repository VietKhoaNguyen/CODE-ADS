#include <stdio.h>

int tribonacci(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    // Variables to hold the last three Tribonacci numbers
    int a = 0, b = 1, c = 1, d;
    
    // Iteratively calculate the Tribonacci number
    for (int i = 3; i <= n; i++) {
        d = a + b + c;  // T(i) = T(i-1) + T(i-2) + T(i-3)
        a = b;           // Update a, b, and c for the next iteration
        b = c;
        c = d;
    }

    return c;  // The nth Tribonacci number
}

int main() {
    int n = 4;
    printf("Tribonacci(%d) = %d\n", n, tribonacci(n));  // Output should be 4
    return 0;
}
/*recur O(3^n)
#include <stdio.h>

int tribonacci(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    // Recursive call for T(n) = T(n-1) + T(n-2) + T(n-3)
    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}

int main() {
    int n = 4;
    printf("Tribonacci(%d) = %d\n", n, tribonacci(n));  // Output should be 4
    return 0;
}
*/