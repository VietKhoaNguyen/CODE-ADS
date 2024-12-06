#include <stdio.h>

// Helper recursive function to calculate the sum of digits at even and odd positions
void splitNumHelper(int num, int *sumOdd, int *sumEven, int isOdd) {
    if (num == 0) {
        return;  // Base case: If number is 0, return
    }
    
    int digit = num % 10;  // Extract the last digit
    if (isOdd) {
        *sumOdd += digit;  // Add to sum of odd-indexed digits
    } else {
        *sumEven += digit; // Add to sum of even-indexed digits
    }

    // Recurse with the next digit (remove the last digit)
    splitNumHelper(num / 10, sumOdd, sumEven, !isOdd);
}

// Main function to split the number and return the sum of both parts
int splitNum(int num) {
    int sumOdd = 0, sumEven = 0;

    // Start with the least significant digit (rightmost one is odd-indexed)
    splitNumHelper(num, &sumOdd, &sumEven, 1);

    // Return the sum of the two parts
    return sumOdd + sumEven;
}

int main() {
    int num;

    // Input number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Calculate and display the result
    int result = splitNum(num);
    printf("The result of splitNum is: %d\n", result);

    return 0;
}
/*recur O(d)
#include <stdio.h>

// Helper recursive function to split and calculate the sum of digits
void splitNumHelper(int num, int *oddSum, int *evenSum, int index) {
    if (num == 0) {
        return;  // Base case: no more digits to process
    }

    int digit = num % 10;  // Extract the last digit
    if (index % 2 == 0) {
        *evenSum += digit;  // If the position is even (0-based), add to even sum
    } else {
        *oddSum += digit;   // If the position is odd (0-based), add to odd sum
    }

    // Recurse with the next digit and increment the index (to alternate between even and odd positions)
    splitNumHelper(num / 10, oddSum, evenSum, index + 1);
}

// Main function to calculate the sum of digits at odd and even positions
int splitNum(int num) {
    int oddSum = 0, evenSum = 0;

    // Start the recursion with index 0 (the rightmost digit is at position 0)
    splitNumHelper(num, &oddSum, &evenSum, 0);

    // Return the sum of both parts (odd and even positioned digits)
    return oddSum + evenSum;
}

int main() {
    int num;

    // Input number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Calculate and display the result
    int result = splitNum(num);
    printf("The result of splitNum is: %d\n", result);

    return 0;
}
*/