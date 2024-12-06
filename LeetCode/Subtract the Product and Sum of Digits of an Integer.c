#include <stdio.h>

int subtractProductAndSum(int n) {
    int product = 1;
    int sum = 0;

    // Iterate through each digit of the number
    while (n > 0) {
        int digit = n % 10;  // Get the last digit
        product *= digit;    // Multiply it with the product
        sum += digit;        // Add it to the sum
        n /= 10;             // Remove the last digit
    }

    return product - sum;  // Return the difference
}

// Example usage
int main() {
    int n = 234;
    printf("Result: %d\n", subtractProductAndSum(n));  // Expected output: 15 (product = 2*3*4 = 24, sum = 2+3+4 = 9, 24 - 9 = 15)
    return 0;
}
/*recur O(d)
#include <stdio.h>

int subtractProductAndSumHelper(int n, int product, int sum) {
    // Base case: when the number is 0, return the difference between product and sum
    if (n == 0) {
        return product - sum;
    }
    
    int digit = n % 10;  // Extract the last digit
    // Recursively call with updated product, sum, and reduced number
    return subtractProductAndSumHelper(n / 10, product * digit, sum + digit);
}

int subtractProductAndSum(int n) {
    return subtractProductAndSumHelper(n, 1, 0);
}

// Example usage
int main() {
    int n = 234;
    printf("Result: %d\n", subtractProductAndSum(n));  // Expected output: 15
    return 0;
}
*/