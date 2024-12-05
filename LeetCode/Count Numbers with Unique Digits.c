#include <stdio.h>

int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;  // Edge case: If n == 0, the only valid number is the empty number

    int result = 10;  // Start with 1-digit numbers (0-9), which are 10 numbers
    
    int product = 9;  // The product for the second digit onward
    int availableDigits = 9;  // The available digits for each position
    
    // Iterate for numbers with 2 to n digits
    for (int i = 2; i <= n; i++) {
        product *= availableDigits--;  // Multiply by available digits for each position
        result += product;  // Add the valid numbers for this length
    }
    
    return result;
}

int main() {
    int n = 3;
    printf("The number of numbers with unique digits of length %d is: %d\n", n, countNumbersWithUniqueDigits(n));
    return 0;
}
/*recur O(n)
#include <stdio.h>

// Recursive function to calculate the number of unique numbers with n digits
int countNumbersWithUniqueDigitsRecursive(int n, int product, int availableDigits) {
    // Base case: if n is 0, return 1 (the empty number is the only valid number)
    if (n == 0) {
        return 1;
    }
    
    // Calculate the number of valid n-digit numbers for this recursion level
    int result = product;  // Multiply the valid numbers at this recursion level
    // Recur for the next level, reduce availableDigits by 1
    return result + countNumbersWithUniqueDigitsRecursive(n - 1, product * availableDigits, availableDigits - 1);
}

// Wrapper function for countNumbersWithUniqueDigitsRecursive
int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;  // Base case: 1 valid number (empty number) for n == 0
    
    int product = 9;  // First digit has 9 options (1-9)
    int availableDigits = 9;  // The available digits for each subsequent digit
    
    // Start recursion from n digits, we begin with 9 options for the first digit
    return 10 + countNumbersWithUniqueDigitsRecursive(n - 1, product * availableDigits, availableDigits - 1);
}

int main() {
    int n = 3;
    printf("The number of numbers with unique digits of length %d is: %d\n", n, countNumbersWithUniqueDigits(n));
    return 0;
}
*/