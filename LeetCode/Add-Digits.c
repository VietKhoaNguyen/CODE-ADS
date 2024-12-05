#include <stdio.h>

// Function to compute the repeated sum of digits of a number
int addDigits(int num) {
    // If the number is 0, the result is 0
    if (num == 0) {
        return 0;
    }
    // The digital root formula: 1 + (num - 1) % 9
    return 1 + (num - 1) % 9;
}

// Main function to test the addDigits function
int main() {
    int num;
    // Test case 1
    num = 38;
    printf("The result for num = %d is: %d\n", num, addDigits(num));
    // Test case 2
    num = 0;
    printf("The result for num = %d is: %d\n", num, addDigits(num));
    return 0;
}
/*Recusive              O(log n)
#include <stdio.h>

// Helper function to compute the sum of digits of a number
int sumOfDigits(int num) {
    if (num == 0) {
        return 0;
    }
    return (num % 10) + sumOfDigits(num / 10);
}

// Recursive function to compute the repeated sum of digits
int addDigits(int num) {
    // Base case: If the number is a single digit, return it
    if (num < 10) {
        return num;
    }
    // Recursive case: Compute the sum of digits and call addDigits again
    return addDigits(sumOfDigits(num));
}

// Main function to test the addDigits function
int main() {
    int num;
    // Test case 1
    num = 38;
    printf("The result for num = %d is: %d\n", num, addDigits(num));
    // Test case 2
    num = 0;
    printf("The result for num = %d is: %d\n", num, addDigits(num));
    // Test case 3
    num = 12345;
    printf("The result for num = %d is: %d\n", num, addDigits(num));
    return 0;
}
*/