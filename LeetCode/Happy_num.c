#include <stdio.h>
#include <stdbool.h>

int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    while (n != 1 && n != 4) {  // If we encounter 1, it's happy; 4 means we're in a cycle.
        n = sumOfSquares(n);
    }
    return n == 1;
}

// Example usage
int main() {
    int n = 19;  // Example input
    if (isHappy(n)) {
        printf("%d is a happy number.\n", n);
    } else {
        printf("%d is not a happy number.\n", n);
    }
    return 0;
}
/*recur O(log n)
#include <stdio.h>
#include <stdbool.h>

int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    // Base cases: if n is 1, it's a happy number; if n is 4, it's a cycle and not a happy number
    if (n == 1) {
        return true;
    }
    if (n == 4) {
        return false;
    }

    // Recursively check the sum of squares of the digits
    return isHappy(sumOfSquares(n));
}

// Example usage
int main() {
    int n = 19;  // Example input
    if (isHappy(n)) {
        printf("%d is a happy number.\n", n);
    } else {
        printf("%d is not a happy number.\n", n);
    }
    return 0;
}
*/