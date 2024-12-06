#include <stdio.h>

int maximum69Number (int num) {
    // Convert the number to a string (array of characters)
    char str[20]; // Enough space for large numbers
    sprintf(str, "%d", num);

    // Traverse through the string and change the first '6' to '9'
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '6') {
            str[i] = '9'; // Change the first '6' to '9'
            break; // Only one change is allowed
        }
    }

    // Convert the modified string back to an integer
    return atoi(str);
}

int main() {
    int num = 9669;
    int result = maximum69Number(num);
    printf("Maximum number: %d\n", result); // Expected output: 9969

    return 0;
}
/*recur O(d)
#include <stdio.h>
#include <math.h>

// Recursive helper function to process the digits and change the first 6 to 9
int helper(int num, int power, int changed) {
    if (num == 0) {
        return 0; // Base case: If no digits left, return 0
    }
    
    int currentDigit = num % 10;  // Get the last digit of the number
    
    if (!changed && currentDigit == 6) {
        // Change the first '6' to '9' and mark the change as done
        return (9 * power) + helper(num / 10, power / 10, 1);
    } else {
        // Keep the digit as is
        return (currentDigit * power) + helper(num / 10, power / 10, changed);
    }
}

// Main function to find the maximum number by changing the first '6' to '9'
int maximum69Number (int num) {
    return helper(num, pow(10, (int)log10(num)), 0);
}

// Example usage
int main() {
    int num = 9669;
    int result = maximum69Number(num);
    printf("Maximum number: %d\n", result);  // Output should be 9969
    return 0;
}
*/