#include <stdio.h>
#include <stdbool.h>

int countPrimes(int n) {
    if (n <= 2) return 0;  // There are no primes less than 2
    
    // Create a boolean array to track whether numbers are prime
    bool isPrime[n];
    
    // Initialize the array, assuming all numbers are prime initially
    for (int i = 0; i < n; i++) {
        isPrime[i] = true;
    }
    
    // Mark 0 and 1 as non-prime
    isPrime[0] = isPrime[1] = false;
    
    // Sieve of Eratosthenes algorithm
    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {  // If the current number is prime
            // Mark all multiples of i as non-prime
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Count the number of primes
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }

    return count;
}

// Example usage
int main() {
    int n = 10;
    printf("Number of primes less than %d: %d\n", n, countPrimes(n)); // Output: 4
    return 0;
}
/*recur O(n^2)
#include <stdio.h>
#include <stdbool.h>

// Recursive function to check if a number is prime
bool isPrime(int num, int divisor) {
    if (num <= 1) return false;  // Base case: 0 and 1 are not prime
    if (divisor == 1) return true;  // Base case: no divisors found, so num is prime
    if (num % divisor == 0) return false;  // If divisible, not a prime
    return isPrime(num, divisor - 1);  // Check for the next smaller divisor
}

// Recursive function to count primes less than n
int countPrimesRecursive(int n) {
    if (n <= 2) return 0;  // Base case: no primes less than 2
    // Check if n-1 is prime, and recurse for the rest
    return (isPrime(n - 1, n - 2) ? 1 : 0) + countPrimesRecursive(n - 1);
}

// Example usage
int main() {
    int n = 10;
    int count = countPrimesRecursive(n);
    printf("Number of primes less than %d: %d\n", n, count);  // Output: 4
    return 0;
}
*/