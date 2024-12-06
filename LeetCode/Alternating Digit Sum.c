#include <stdio.h>

// Helper recursive function to calculate the alternate digit sum
int alternateDigitSumHelper(int n, int isPositive) {
    if (n == 0) {
        return 0; // Base case: if the number is 0, return 0
    }

    // Get the last digit of the number
    int lastDigit = n % 10;

    // Add or subtract the last digit based on whether the index is even or odd
    if (isPositive) {
        return lastDigit + alternateDigitSumHelper(n / 10, !isPositive);
    } else {
        return -lastDigit + alternateDigitSumHelper(n / 10, !isPositive);
    }
}

// Main function to calculate the alternate digit sum
int alternateDigitSum(int n) {
    return alternateDigitSumHelper(n, 1); // Start with adding the first digit
}

int main() {
    int n;

    // Input number
    printf("Enter a number: ");
    scanf("%d", &n);

    // Calculate and display the result
    int result = alternateDigitSum(n);
    printf("The alternate digit sum is: %d\n", result);

    return 0;
}
/*recur O(n)
#include <stdio.h>

// Recursive function to calculate the alternate digit sum
int alternateDigitSum(int n, int isPositive) {
    if (n == 0) {
        return 0; // Base case: no more digits
    }
    
    // Get the last digit of the number
    int lastDigit = n % 10;

    // Add or subtract based on whether the position is even or odd
    if (isPositive) {
        return lastDigit + alternateDigitSum(n / 10, 0); // Add the digit and alternate
    } else {
        return -lastDigit + alternateDigitSum(n / 10, 1); // Subtract the digit and alternate
    }
}

int main() {
    int n;

    // Input number
    printf("Enter a number: ");
    scanf("%d", &n);

    // Calculate the alternate digit sum starting with addition
    int result = alternateDigitSum(n, 1);
    printf("The alternate digit sum is: %d\n", result);

    return 0;
}
*/