#include <stdio.h>

int isPalindrome(int x) {
    if (x < 0) return 0; // Negative numbers are not palindromes.

    int original = x, reversed = 0;

    // Reverse the number
    while (x != 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }

    // Check if the original number is a palindrome
    if (original == reversed) {
        long long product = (long long)original * reversed;
        printf("Original: %d, Reversed: %d, Product: %lld\n", original, reversed, product);
        return 1; // Return 1 if palindrome
    } else {
        printf("The number is not a palindrome.\n");
        return 0; // Return 0 if not a palindrome
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPalindrome(num)) {
        printf("The number %d is a palindrome.\n", num);
    } else {
        printf("The number %d is not a palindrome.\n", num);
    }

    return 0;
}
