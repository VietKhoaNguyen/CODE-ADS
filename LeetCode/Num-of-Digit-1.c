#include <stdio.h>

// Function to count the number of digit '1' in all numbers from 0 to n
int countDigitOne(int n) {
    int count = 0;
    long long factor = 1; // The factor determines the current digit's place (1, 10, 100, etc.)
    
    while (n / factor > 0) {
        int lower = n - (n / factor) * factor; // Numbers below the current place
        int current = (n / factor) % 10;      // The digit at the current place
        int higher = n / (factor * 10);       // Numbers above the current place

        // Count based on the current digit
        if (current == 0) {
            count += higher * factor; // Add all contributions from higher digits
        } else if (current == 1) {
            count += higher * factor + lower + 1; // Include lower numbers +1 for the current position
        } else {
            count += (higher + 1) * factor; // Count full groups of '1's
        }

        factor *= 10; // Move to the next higher digit
    }

    return count;
}

// Example usage
int main() {
    int n = 13; // Example input
    printf("Number of digit '1' from 0 to %d: %d\n", n, countDigitOne(n)); // Expected output: 6
    return 0;
}
/*recur O(log10 n)
#include <stdio.h>

// Helper recursive function
int countDigitOneRecursive(long long n) {
    if (n <= 0) return 0;

    // Determine the current power of 10
    long long powerOf10 = 1;
    while (powerOf10 * 10 <= n) {
        powerOf10 *= 10;
    }

    long long mostSignificantDigit = n / powerOf10; // Extract the most significant digit
    long long remainder = n % powerOf10;           // Remaining digits after the most significant

    // Count '1's contributed by the most significant digit
    int countFromMSD = 0;
    if (mostSignificantDigit == 1) {
        countFromMSD = remainder + 1; // '1's from the most significant position (e.g., 100-199 contributes 100 '1's)
    } else {
        countFromMSD = powerOf10; // Full power of 10 contributes (e.g., 200-299 contributes 100 '1's)
    }

    // Recursive call for numbers below the most significant digit
    int countFromLowerNumbers = mostSignificantDigit * countDigitOneRecursive(powerOf10 - 1);

    // Recursive call for the remaining digits
    int countFromRemainder = countDigitOneRecursive(remainder);

    return countFromMSD + countFromLowerNumbers + countFromRemainder;
}

// Wrapper function
int countDigitOne(int n) {
    return countDigitOneRecursive(n);
}

// Example usage
int main() {
    int n = 13; // Example input
    printf("Number of digit '1' from 0 to %d: %d\n", n, countDigitOne(n)); // Expected output: 6
    return 0;
}
*/