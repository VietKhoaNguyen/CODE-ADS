#include <stdio.h>

int countDigits(int num) {
    // Base case: If the number becomes 0, there are no more digits
    if (num == 0) {
        return 0;
    }

    // Recursive case: Remove the last digit and count recursively
    return 1 + countDigits(num / 10);
}

int main() {
    int num;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Handle the case for 0 explicitly, as it has one digit
    if (num == 0) {
        printf("The number of digits is: 1\n");
    } else {
        // Call the recursive function and display the result
        printf("The number of digits is: %d\n", countDigits(num < 0 ? -num : num));
    }

    return 0;
}
/*recur O(n)
#include <stdio.h>

int countDigits(int num) {
    // If the number is negative, convert it to positive for simplicity
    if (num < 0) {
        num = -num;
    }

    // Base case: when the number becomes 0, no more digits are left
    if (num == 0) {
        return 0;
    }

    // Recursive case: remove the last digit and count the remaining digits
    return 1 + countDigits(num / 10);
}

int main() {
    int num;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Special case for 0 as it has exactly 1 digit
    if (num == 0) {
        printf("The number of digits is: 1\n");
    } else {
        // Call the recursive function and display the result
        printf("The number of digits is: %d\n", countDigits(num));
    }

    return 0;
}
*/