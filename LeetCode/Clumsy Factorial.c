#include <stdio.h>

int clumsy(int n) {
    // If n is 1, the result is just 1
    if (n == 1) return 1;

    // Initialize the result to the first operation: n * (n-1)
    int result = n * (n - 1);

    // We start from n-2 and perform the operations
    int i = n - 2;
    
    // Define the operation: Multiply, Divide, Multiply, Divide...
    int sign = 1; // Start with multiplication as the first operation
    while (i > 0) {
        if (sign) {
            result *= i;  // Multiply by the current number
        } else {
            result /= i;  // Divide by the current number
        }
        sign = !sign;  // Flip the operation (Multiply <-> Divide)
        i--;
    }
    
    // Finally, subtract the remaining number
    if (i == 0) {
        result -= i;
    }

    return result;
}

// Example usage
int main() {
    int n = 4;
    int result = clumsy(n);
    printf("Clumsy of %d: %d\n", n, result);

    return 0;
}
/*recur O(n)
#include <stdio.h>

// Recursive helper function
int helper(int n, int sign) {
    if (n == 1) {
        return 1;
    }

    int current = (sign == 1) ? n * (n - 1) : n / (n - 1);  // Multiply or Divide
    // Alternate the sign for the next operation (multiply <-> divide)
    return current + helper(n - 2, 1 - sign);
}

// Main clumsy function
int clumsy(int n) {
    // Handle base case for n = 1
    if (n == 1) return 1;

    // Start the recursion with the first number and a sign of 1 (multiply first)
    return helper(n, 1);
}

// Example usage
int main() {
    int n = 4;
    int result = clumsy(n);
    printf("Clumsy of %d: %d\n", n, result);

    return 0;
}
*/