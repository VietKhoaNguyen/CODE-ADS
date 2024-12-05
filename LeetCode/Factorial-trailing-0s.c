#include <stdio.h>

int trailingZeroes(int n) {
    int count = 0;
    
    // Keep dividing n by powers of 5 (i.e., 5, 25, 125, ...)
    while (n >= 5) {
        n /= 5;      // Divide n by 5
        count += n;  // Add the quotient to count
    }
    
    return count;
}

// Example usage
int main() {
    int n = 100;
    printf("Number of trailing zeroes in %d! is %d\n", n, trailingZeroes(n));
    return 0;
}
/*recur O(log5 n)
#include <stdio.h>

// Recursive function to count trailing zeroes
int trailingZeroes(int n) {
    // Base case: when n is less than 5, no more trailing zeroes can be added
    if (n < 5) {
        return 0;
    }
    
    // Recursive case: divide n by 5 and add the result to the count
    return n / 5 + trailingZeroes(n / 5);
}

// Example usage
int main() {
    int n = 100;
    printf("Number of trailing zeroes in %d! is %d\n", n, trailingZeroes(n));
    return 0;
}
*/