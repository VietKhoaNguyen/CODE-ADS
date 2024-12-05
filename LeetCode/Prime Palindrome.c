#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a number is a palindrome
bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return original == reversed;
}

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    if (num % 2 == 0) {
        return false;  // Even numbers greater than 2 are not prime
    }
    for (int i = 3; i <= sqrt(num); i += 2) {  // Check odd numbers up to sqrt(num)
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to find the smallest prime palindrome >= n
int primePalindrome(int n) {
    // Handle the edge case where n is less than 2
    if (n <= 2) {
        return 2;  // 2 is the smallest prime palindrome
    }
    
    // Start from n and check each number
    while (1) {
        if (isPalindrome(n) && isPrime(n)) {
            return n;
        }
        n++;
    }
}

// Example usage
int main() {
    int n = 31;  // Example input
    int result = primePalindrome(n);
    printf("The smallest prime palindrome greater than or equal to %d is: %d\n", n, result);
    return 0;
}
/*recur O(k* sqrt(n)*logn)
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Recursive function to check if a number is a palindrome
bool isPalindrome(int num, int reversed) {
    if (num == 0) {
        return num == reversed;
    }
    reversed = reversed * 10 + (num % 10);
    return isPalindrome(num / 10, reversed);
}

// Function to check if a number is prime recursively
bool isPrime(int num, int divisor) {
    if (num <= 1) {
        return false;
    }
    if (divisor == 1) {
        return true;
    }
    if (num % divisor == 0) {
        return false;
    }
    return isPrime(num, divisor - 1);
}

// Main recursive function to find the smallest prime palindrome >= n
int primePalindromeRecursive(int n) {
    if (isPalindrome(n, 0) && isPrime(n, (int)sqrt(n))) {
        return n;
    }
    return primePalindromeRecursive(n + 1);
}

// Wrapper function to handle the case where n is less than 2
int primePalindrome(int n) {
    if (n <= 2) {
        return 2;  // 2 is the smallest prime palindrome
    }
    return primePalindromeRecursive(n);
}

// Example usage
int main() {
    int n = 31;  // Example input
    int result = primePalindrome(n);
    printf("The smallest prime palindrome greater than or equal to %d is: %d\n", n, result);
    return 0;
}
*/